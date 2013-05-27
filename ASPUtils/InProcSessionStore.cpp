// InProcSessionStore.cpp : Implementation of CInProcSessionStore

#include "stdafx.h"
#include "InProcSessionStore.h"


// CInProcSessionStore

STDMETHODIMP CInProcSessionStore::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IInProcSessionStore,
		&IID_IASPSessionStoreProvider
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CInProcSessionStore::Initialize()
{
	return S_OK;
}

STDMETHODIMP CInProcSessionStore::Terminate()
{
	return S_OK;
}

/** Return item from store. 
 *	
 *  This method returns ERROR_LOCKED if exclusive access is requested and item is already locked. Metadata is still returned.
 */
STDMETHODIMP CInProcSessionStore::GetItem(BSTR bstrKey, ExclusiveMode lExclusiveMode, IStream* pStream, void** lLockId, long* lLockAge, VARIANT_BOOL* lLocked)
{
	string sKey = _bstr_t(bstrKey);

	itr it = m_tree.find(sKey);

	if(it == m_tree.end())
	{
		//item is not in the store -> exit
		return E_FAIL;
	}	
	shared_ptr<StoreItem> pItem = it->second;

	if (EXC_MODE_ACQUIRE == lExclusiveMode)
	{
		if (pItem->m_LockTime > 0)
		{
			//item is already locked -> set metadata and return error
			*lLockId = (void*)pItem->m_LockId;
			*lLockAge = (long)difftime(time(0), pItem->m_LockTime);
			*lLocked = VARIANT_TRUE;

			return SSTORE_E_ITEMLOCKED;
		}
		else
		{
			//lock item
			pItem->m_LockTime = time(0);
			pItem->m_LockId +=1;
		}
	}
	
	//copy item metadata and buffer to out vars
	*lLockId = (void*)pItem->m_LockId;
	*lLockAge = (long)difftime(time(0), pItem->m_LockTime);
	*lLocked = pItem->m_LockId > 0;
	
	CComPtr<IStream> piStream(pStream);

	ULONG cbWritten;
	TestHR(piStream->Write(pItem->m_Data.data(), pItem->m_DataSize, &cbWritten));

	ATLENSURE(cbWritten == pItem->m_DataSize);

	return S_OK;
}

/** Puts item in store. 
 *	
 *  This method returns ERROR_LOCKED if item is locked with different lockId.
 */
STDMETHODIMP CInProcSessionStore::SetItem(BSTR bstrKey, long lTimeout, void* lLockId, IStream* pStream)
{
	string sKey = _bstr_t(bstrKey);

	shared_ptr<StoreItem> pItem;

	uint64_t lockId = *(uint64_t*)lLockId;
	
	itr it = m_tree.find(sKey);
	
	if (it != m_tree.end())
	{
		pItem = it->second;

		// we need to check lockId 
		if (pItem->m_LockTime > 0 && lockId != pItem->m_LockId)
		{
			//item is locked with different lockId -> return error
			return SSTORE_E_ITEMLOCKED;
		}
	}
	else
	{
		//create new item...
		pItem = make_shared<StoreItem>();
		//... and add it to store
		m_tree.insert(make_pair(sKey, pItem));
	}
	
	//clear in case item already exists
	pItem->m_Data.clear();
	pItem->m_DataSize = 0;

	//... set metadata 
	//pItem->m_LockId = 0;
	pItem->m_LockTime = time(0);
	pItem->m_Timeout = lTimeout;
	
	//... read data
	STATSTG stat;
	CComPtr<IStream> piStream(pStream);
	TestHR(piStream->Stat(&stat, STATFLAG_NONAME));

	pItem->m_Data.resize(stat.cbSize.QuadPart);
	TestHR(piStream->Read(pItem->m_Data.data(), stat.cbSize.QuadPart, &pItem->m_DataSize));

	ATLENSURE(stat.cbSize.QuadPart == pItem->m_DataSize);

	return S_OK;
}
	
STDMETHODIMP CInProcSessionStore::ReleaseItemExclusive(BSTR bstrKey, void* lLockId)
{
	string sKey = _bstr_t(bstrKey);

	uint64_t lockId = *(uint64_t*)lLockId;

	itr it = m_tree.find(sKey);

	if (it != m_tree.end())
	{
		shared_ptr<StoreItem> pItem = it->second;

		if (pItem->m_LockTime > 0 && lockId != pItem->m_LockId)
		{
			//item is locked with different lockId, exit
			return SSTORE_E_ITEMLOCKED;
		}
		else
		{
			//clear exclusive lock
			pItem->m_LockTime = 0;
		}
	}

	return S_OK;
}
	
STDMETHODIMP CInProcSessionStore::RemoveItem(BSTR bstrKey, void* lLockId)
{
	string sKey = _bstr_t(bstrKey);
	uint64_t lockId = *(uint64_t*)lLockId;

	//find item
	itr it = m_tree.find(sKey);

	if (it != m_tree.end())
	{
		shared_ptr<StoreItem> pItem = it->second;

		if (pItem->m_LockTime > 0 && lockId != pItem->m_LockId)
		{
			//item is locked with different lockId, return error
			return SSTORE_E_ITEMLOCKED;
		}
		else
		{
			m_tree.erase(it);
		}
	}

	return S_OK;
}

STDMETHODIMP CInProcSessionStore::ResetItemTimeout(BSTR bstrKey)
{
	return E_NOTIMPL;
}