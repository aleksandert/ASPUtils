// CouchBaseSessionStore.cpp : Implementation of CCouchBaseSessionStore

#include "stdafx.h"
#include "CouchBaseSessionStore.h"


// CCouchBaseSessionStore

STDMETHODIMP CCouchBaseSessionStore::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_ICouchBaseSessionStore
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

static void error_callback(lcb_t instance, lcb_error_t err, const char *errinfo)
{
	ATLTRACE(lcb_strerror(instance, err));
}

static void store_callback(lcb_t instance, const void *cookie, lcb_storage_t operation, lcb_error_t error, const lcb_store_resp_t *resp)
{
	//todo: retry policy

	StoreItem* item = static_cast<StoreItem*>(const_cast<void*>(cookie));

	item->m_Error = error;

	if (error == LCB_SUCCESS)
	{
		item->m_LockId = resp->v.v0.cas;
	}
}

static void remove_callback(lcb_t instance, const void *cookie, lcb_error_t error, const lcb_remove_resp_t *resp)
{}

static void get_callback(lcb_t instance, const void *cookie, lcb_error_t error, const lcb_get_resp_t *resp)
{
	//todo: retry policy

	StoreItem* item = static_cast<StoreItem*>(const_cast<void*>(cookie));

	item->m_Error = error;

	if (error == LCB_SUCCESS)
	{
		BYTE* bytes = static_cast<BYTE*>(const_cast<void*>(resp->v.v0.bytes));
		
		item->m_DataSize = resp->v.v0.nbytes;
		item->m_Data.insert(item->m_Data.end(), bytes, bytes + item->m_DataSize);
		item->m_LockId = resp->v.v0.cas;
	}
}


STDMETHODIMP CCouchBaseSessionStore::Initialize()
{
	struct lcb_create_st create_options;
	
	lcb_error_t err;

	memset(&create_options, 0, sizeof(create_options));
	create_options.v.v0.host = "localhost:8091";
	create_options.v.v0.user = "Administrator";
	create_options.v.v0.passwd = "Test.123";
	create_options.v.v0.bucket = "default";

	err = lcb_create(&m_lcb_instance, &create_options);

	if (err != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, err));
	}
	
	/* Set up the handler to catch all errors! */
	lcb_set_error_callback(m_lcb_instance, error_callback);

	lcb_set_remove_callback(m_lcb_instance, remove_callback);
	lcb_set_get_callback(m_lcb_instance, get_callback);
	lcb_set_store_callback(m_lcb_instance, store_callback);

	/*
	 * Initiate the connect sequence in libcouchbase
	 */
	if ((err = lcb_connect(m_lcb_instance)) != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, err));
	}

	/* Run the event loop and wait until we've connected */
	lcb_wait(m_lcb_instance);

	return S_OK;
}

STDMETHODIMP CCouchBaseSessionStore::Terminate()
{
	lcb_destroy(m_lcb_instance);

	return S_OK;
}

STDMETHODIMP CCouchBaseSessionStore::GetItem(BSTR bstrKey, ExclusiveMode lExclusiveMode, IStream* pStream, long* lLockId, long* lLockAge, VARIANT_BOOL* lLocked)
{
	CComBSTR bKey = bstrKey;

	StoreItem item;

	//create lcb request
	unique_ptr<lcb_get_cmd_st> pGet(new lcb_get_cmd_st());
	
	pGet->version = 0;
	pGet->v.v0.key = bKey;
	pGet->v.v0.nkey = bKey.ByteLength();
	pGet->v.v0.lock = EXC_MODE_ACQUIRE == lExclusiveMode ? 1 : 0;
	pGet->v.v0.exptime = 0;
	pGet->v.v0.hashkey = nullptr;
	pGet->v.v0.nhashkey = 0;

	lcb_get_cmd_st* commands[] = { pGet.get() };
	
	lcb_error_t err;

	// send request
	err = lcb_get(m_lcb_instance, &item, 1, commands);

	if (err != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, err));
	}

	// wait for response
	err = lcb_wait(m_lcb_instance);

	if (err != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, err));
	}

	if (item.m_Error != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, item.m_Error));
	}
	
	//set output parameters
	//copy item metadata and buffer to out vars
	*lLockId = item.m_LockId;
	*lLockAge = (long)difftime(time(0), item.m_LockTime);
	*lLocked = item.m_Locked;
	
	CComPtr<IStream> piStream(pStream);

	ULONG cbWritten;
	TestHR(piStream->Write(item.m_Data.data(), item.m_DataSize, &cbWritten));

	ATLENSURE(cbWritten == item.m_DataSize);
	
	return S_OK;
}
	
STDMETHODIMP CCouchBaseSessionStore::SetItem(BSTR bstrKey, long lTimeout, long lLockId, IStream* pStream)
{
	CComBSTR bKey = bstrKey;

	StoreItem item;

	//... read data into buffer
	STATSTG stat;
	CComPtr<IStream> piStream(pStream);
	TestHR(piStream->Stat(&stat, STATFLAG_NONAME));

	ULONG totalBytes = stat.cbSize.QuadPart;
	
	item.m_Data.resize(totalBytes);
	TestHR(piStream->Read(item.m_Data.data(), totalBytes, &item.m_DataSize));
	ATLENSURE(totalBytes == item.m_DataSize);
	
	//create lcb request
	unique_ptr<lcb_store_cmd_st> pStore(new lcb_store_cmd_st());

	pStore->version = 0;
	pStore->v.v0.key = bKey;
	pStore->v.v0.nkey = bKey.ByteLength();
	pStore->v.v0.bytes = item.m_Data.data();
	pStore->v.v0.nbytes = item.m_DataSize;
	pStore->v.v0.flags = 0;
	pStore->v.v0.cas = lLockId;
	pStore->v.v0.exptime = lTimeout;
	pStore->v.v0.datatype = 0;
	pStore->v.v0.operation = LCB_SET;
	 
	lcb_store_cmd_st* commands[] = { pStore.get() };

	lcb_error_t err;

	//send request
	err = lcb_store(m_lcb_instance, &item, 1, commands);
	
	if (err != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, err));
	}

	//and wait for response
	err = lcb_wait(m_lcb_instance);

	if (err != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, err));
	}

	if (item.m_Error != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, item.m_Error));
	}
	
	return S_OK;
}
	
STDMETHODIMP CCouchBaseSessionStore::ReleaseItemExclusive(/*[in]*/ BSTR bstrKey, /*[in]*/ LONG lockId)
{
	CComBSTR bKey = bstrKey;

	//create lcb request
	unique_ptr<lcb_unlock_cmd_t> pCmd(new lcb_unlock_cmd_t());
	
	pCmd->version = 0;
	pCmd->v.v0.key = bKey;
	pCmd->v.v0.nkey = bKey.ByteLength();
	pCmd->v.v0.cas = lockId;

	lcb_unlock_cmd_t* commands[] = { pCmd.get() };

	//send request
	lcb_error_t err = lcb_unlock(m_lcb_instance, NULL, 1, commands);
	
	//wait for response
	lcb_wait(m_lcb_instance);

	if (err != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, err));
	}

	return S_OK;
}
	
STDMETHODIMP CCouchBaseSessionStore::RemoveItem(/*[in]*/ BSTR bstrKey, /*[in]*/ LONG lLockId)
{
	CComBSTR bKey = bstrKey;

	//create lcb request
	unique_ptr<lcb_remove_cmd_t> pCmd(new lcb_remove_cmd_t());

	pCmd->version = 0;
	pCmd->v.v0.key = bKey;
	pCmd->v.v0.nkey = bKey.ByteLength();
	pCmd->v.v0.cas = lLockId;
	lcb_remove_cmd_t* commands[] = { pCmd.get() };
	
	//send request
	lcb_error_t err = lcb_remove(m_lcb_instance, NULL, 1, commands);

	//wait for response
	lcb_wait(m_lcb_instance);

	if (err != LCB_SUCCESS)
	{
		return AtlReportError (GetObjectCLSID(), lcb_strerror(NULL, err));
	}

	return S_OK;
}

STDMETHODIMP CCouchBaseSessionStore::ResetItemTimeout(/*[in]*/ BSTR bstrKey)
{
	return E_NOTIMPL;
}
