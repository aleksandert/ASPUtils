// MemcachedSessionStore.cpp : Implementation of CMemcachedSessionStore

#include "stdafx.h"
#include "MemcachedSessionStore.h"

// CMemcachedSessionStore

STDMETHODIMP CMemcachedSessionStore::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IMemcachedSessionStore
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CMemcachedSessionStore::Initialize()
{
	//const char *config_string= "--SERVER=host10.example.com --SERVER=host11.example.com --SERVER=host10.example.com";
	//string servers_list = "sr-si-build01-t";

	string servers_list = "127.0.0.1";

	m_memc = memcached_create(NULL);

	// Create a list of servers
	memcached_server_st *servers = memcached_servers_parse(servers_list.c_str());

	memcached_return_t rc;

	rc = memcached_behavior_set(m_memc, MEMCACHED_BEHAVIOR_BINARY_PROTOCOL, 1);
	rc = memcached_behavior_set(m_memc, MEMCACHED_BEHAVIOR_NO_BLOCK, 1);
	rc = memcached_behavior_set(m_memc, MEMCACHED_BEHAVIOR_TCP_NODELAY, 1);
	rc = memcached_behavior_set(m_memc, MEMCACHED_BEHAVIOR_NOREPLY, 1);
	rc = memcached_behavior_set(m_memc, MEMCACHED_BEHAVIOR_SUPPORT_CAS, 1);
//	rc = memcached_behavior_set(m_memc, MEMCACHED_BEHAVIOR_KETAMA, 0);
        
	if (rc != MEMCACHED_SUCCESS)
	{
		return AtlReportError(GetObjectCLSID(), memcached_strerror(NULL, rc), IID_IMemcachedSessionStore, E_FAIL);
	}

    rc = memcached_server_push(m_memc, servers);
	
	memcached_server_free(servers);

	if (rc != MEMCACHED_SUCCESS)
	{
		return AtlReportError(GetObjectCLSID(), memcached_strerror(NULL, rc), IID_IMemcachedSessionStore, E_FAIL);
	}

	if(memcached_server_count(m_memc) < 1) 
	{
		return AtlReportError(GetObjectCLSID(), "No connected servers.", IID_IMemcachedSessionStore, E_FAIL);
	}

	return S_OK;
}

STDMETHODIMP CMemcachedSessionStore::Terminate()
{
	memcached_free(m_memc);

	return S_OK;
}
//
//HRESULT CMemcachedSessionStore::GetItemHeader(string sKey, ExclusiveMode lExclusiveMode, ItemHeader* itemHeader)
//{
//	HRESULT hr = S_FALSE;
//
//	vector<const char*> key;
//	vector<size_t> len;
//
//	key.reserve(1);
//	len.reserve(1);
//
//	key.push_back(sKey.c_str());
//	len.push_back(sKey.length());
//
//	//execute mget cmd
//	memcached_return_t rc = memcached_mget(m_memc, &key[0], &len[0], key.size());
//      
//	if (rc != MEMCACHED_SUCCESS)
//	{
//		return AtlReportError(GetObjectCLSID(), memcached_strerror(NULL, rc), IID_IMemcachedSessionStore, SSTORE_E_FAILED);
//	}
//	
//	//fetch single result
//	memcached_result_st* result = memcached_fetch_result(m_memc, NULL, &rc);
//
//	if (rc != MEMCACHED_SUCCESS && rc != MEMCACHED_NOTFOUND)
//	{
//		memcached_result_free(result);
//
//		return AtlReportError(GetObjectCLSID(), string("Fetch failed: ").append(memcached_strerror(NULL, rc)).c_str(), IID_IMemcachedSessionStore, SSTORE_E_FAILED);
//	}
//
//	if(result == NULL)
//	{
//		hr = SSTORE_S_ITEMNOTFOUND;
//	}
//	else
//	{
//		itemHeader = (ItemHeader*) memcached_result_value(result);
//		hr = SSTORE_S_OK;
//	}
//
//	memcached_result_free(result);	
//
//	return hr;
//}

STDMETHODIMP CMemcachedSessionStore::GetItem(BSTR bstrKey, ExclusiveMode lExclusiveMode, IStream* pStream, void** lLockId, long* lLockAge, VARIANT_BOOL* lLocked)
{
	//we need to use memcached_mget that will gave us access to cas value

	string sKey = _bstr_t(bstrKey);

	std::vector<const char*> real_keys;
    std::vector<size_t> key_len;

	//reserve space
    real_keys.reserve(1);
    key_len.reserve(1);

	//push key and len
    real_keys.push_back(const_cast<char *>(sKey.c_str()));
	key_len.push_back(sKey.length());
    
	//execute mget cmd
	memcached_return_t rc = memcached_mget(m_memc, &real_keys[0], &key_len[0], real_keys.size());
      
	if (rc != MEMCACHED_SUCCESS)
	{
		return AtlReportError(GetObjectCLSID(), memcached_strerror(NULL, rc), IID_IMemcachedSessionStore, E_FAIL);
	}
	
	//fetch single result
	memcached_result_st* result = memcached_fetch_result(m_memc, NULL, &rc);
	
	if (rc == MEMCACHED_NOTFOUND)
	{
		memcached_result_free(result);
		return SSTORE_S_ITEMNOTFOUND;
	}

	if (rc != MEMCACHED_SUCCESS)
	{
		memcached_result_free(result);
		return AtlReportError(GetObjectCLSID(), string("Fetch failed: ").append(memcached_strerror(NULL, rc)).c_str(), IID_IMemcachedSessionStore, SSTORE_E_FAILED);
	}

	HRESULT hr;

	if (EXC_MODE_ACQUIRE == lExclusiveMode)
	{
		while (true)
		{
			if (memcached_result_flags(result) > 0)
			{
				//item is already locked
				hr = SSTORE_E_ITEMLOCKED;
				break;
			}
		
			rc = memcached_cas(m_memc, sKey.c_str(), sKey.length(), 
								memcached_result_value(result), 
								memcached_result_length(result),
								result->item_expiration,
								time(0), 
								memcached_result_cas(result));

			if (rc == MEMCACHED_SUCCESS)
			{
				hr = SSTORE_S_OK;
				break;
			}

			memcached_result_free(result);

			rc = memcached_mget(m_memc, &real_keys[0], &key_len[0], real_keys.size());

			result = memcached_fetch_result(m_memc, NULL, &rc);
		}
	}

	uint64_t cas = result->item_cas;

	*lLockId = (void*)&cas;
	*lLockAge = 0;
	*lLocked = VARIANT_TRUE;
	
	if (hr == SSTORE_S_OK)
	{
		//write data to stream
		ULONG lWritten;
		ULONG lLength = memcached_result_length(result);
	
		CComPtr<IStream> piStream(pStream);
		HRESULT hr = piStream->Write(memcached_result_value(result), lLength, &lWritten);

		memcached_result_free(result);

		TestHR(hr);

		ATLENSURE(lLength == lWritten);
	}

	return hr;
}
	
STDMETHODIMP CMemcachedSessionStore::SetItem(BSTR bstrKey, long lTimeout, void* lLockId, IStream* pStream)
{
	string sKey = _bstr_t(bstrKey);
	
	if (sKey.empty())
    {
		return AtlReportError(GetObjectCLSID(), "The key supplied is empty!");
    }

	CComPtr<IStream> piStream(pStream);

	//get stream size
	ULONG totalBytes;
	{
		STATSTG stat;
		TestHR(piStream->Stat(&stat, STATFLAG_NONAME));
		totalBytes =  stat.cbSize.QuadPart;
	}

	//... read data into buffer
	ULONG bytesRead;

	vector<char> vData;

	vData.resize(totalBytes);

	TestHR(piStream->Read(vData.data(), totalBytes, &bytesRead));

	ATLENSURE(totalBytes == bytesRead);

	struct tm ts; ts.tm_min = lTimeout;
	long lLockTime = 0;

	uint64_t cas = 0;
	
	if (lLockId)
	{
		cas	= *(uint64_t*)lLockId;
	}
	
	memcached_return_t rc;

	// new items are added to store, existing are updated using cas
	if (cas == 0)
	{
		rc = memcached_add(m_memc, sKey.c_str(), sKey.length(), &vData[0], vData.size(), mktime(&ts), lLockTime);
	}
	else
	{
		rc = memcached_cas(m_memc, sKey.c_str(), sKey.length(), &vData[0], vData.size(), mktime(&ts), lLockTime, cas);
	}

	vData.clear();

    if (!(rc == MEMCACHED_SUCCESS || rc == MEMCACHED_BUFFERED))
	{
		return AtlReportError(GetObjectCLSID(), string("Store failed: ").append(memcached_strerror(NULL, rc)).c_str());
	}
	
	return S_OK;
}
	
STDMETHODIMP CMemcachedSessionStore::ReleaseItemExclusive(/*[in]*/ BSTR bstrKey, /*[in]*/ void* lockId)
{
	return E_NOTIMPL;
}
	
STDMETHODIMP CMemcachedSessionStore::RemoveItem(/*[in]*/ BSTR bstrKey, /*[in]*/ void* lLockId)
{
	return E_NOTIMPL;
}

STDMETHODIMP CMemcachedSessionStore::ResetItemTimeout(/*[in]*/ BSTR bstrKey)
{
	return E_NOTIMPL;
}
