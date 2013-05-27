// Cache.cpp : Implementation of CCache


#include "stdafx.h"
#include "ATLComTime.h"
#include "Cache.h"

STDMETHODIMP CCache::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_ICache
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


VOID CALLBACK ExpireCachedItems(PVOID lpParameter, BOOLEAN TimerOrWaitFired)
{
	CacheStorage* storage = reinterpret_cast< CacheStorage* >( lpParameter );
	
	CAtlMap<CComBSTR, CacheEntry>* cachedItems = storage->Items;
	CRBMultiMap<long, CComBSTR>* cacheTimers = storage->Timers;

	long currentTime = (long)CTime::GetCurrentTime().GetTime();
	long expiresTime;

	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	// Traverse the tree
	POSITION pos = cacheTimers->GetHeadPosition();

	while (pos != NULL)
	{
		expiresTime = cacheTimers->GetKeyAt(pos);

		if (expiresTime <= currentTime)
		{
			cachedItems->RemoveKey(cacheTimers->GetValueAt(pos));
			cacheTimers->RemoveAt(pos);
		}
		else
		{
			break;
		}
				
		cacheTimers->GetNextKey(pos);
	}

	//Update Performance Counter Values

	m_PerfCounterValues.Entries = cachedItems->GetCount();
	

	return;
}

STDMETHODIMP CCache::Initialize()
{
	m_cacheStorage.Items = &m_cachedItems;
	m_cacheStorage.Timers = &m_cacheTimers;

	//Register Performance Counters

	if (CounterInitialize() != ERROR_SUCCESS)
	{
		return GetLastError();
	}

	CString sPID; sPID.Format(L"%d", GetCurrentProcessId());
	
	m_PerfCounterSet = PerfCreateInstance(ASPUtils, &ASPUtilsCacheCountersGuid, sPID, 0);

    if (m_PerfCounterSet == NULL)
	{
		return GetLastError();
    }

	PerfSetCounterRefValue(ASPUtils, m_PerfCounterSet, 1, &m_PerfCounterValues.Entries);
	PerfSetCounterRefValue(ASPUtils, m_PerfCounterSet, 2, &m_PerfCounterValues.Hits);
	PerfSetCounterRefValue(ASPUtils, m_PerfCounterSet, 3, &m_PerfCounterValues.Misses);
    
	//Create expiration timer
	CreateTimerQueueTimer( &hTimer, NULL, (WAITORTIMERCALLBACK)ExpireCachedItems, &m_cacheStorage , 1000, 1000, 0);
	
	return S_OK;
}

STDMETHODIMP CCache::Terminate()
{
	RemoveAll();
	
	DeleteTimerQueueTimer(NULL, hTimer, NULL);

	CounterCleanup();

	return S_OK;
}

/// <summary>
/// Inserts an object into the <b>Cache</b>.
/// </summary>
/// <param name="key">The cache key used to reference the item.</param>
/// <param name="value">The object to be inserted into the cache.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::Set(VARIANT key, VARIANT value)
{
	CachePolicy policy;

	policy.Type = None;

	return Put(key, value, policy);
}

/// <summary>
/// Inserts an object into the <b>Cache</b> with sliding expiration policy.
/// </summary>
/// <param name="key">The cache key used to reference the object.</param>
/// <param name="value">The object to be inserted in the cache. </param>
/// <param name="slidingExpiration">The interval (in seconds) between the time the inserted object is last accessed and the time at which that object expires.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::SetSliding(VARIANT key, VARIANT value, VARIANT expiration)
{
	CComVariant varExpiration = VARIANTDREF(&expiration);

	if (varExpiration.ChangeType(VT_UI4) != S_OK)
	{
		return AtlReportError(CLSID_Cache, _T("Parameter \"slidingExpiration\" must be a positive number of seconds."), IID_ICache, 0);
	}

	CachePolicy policy;

	policy.Type = Sliding;
	policy.SlidingExpiration = CTimeSpan(0, 0, 0, varExpiration.lVal);

	varExpiration.Clear();

	return Put(key, value, policy);
}

/// <summary>
/// Inserts an object into the <b>Cache</b> with absolute expiration policy.
/// </summary>
/// <param name="key">The cache key used to reference the object.</param>
/// <param name="value">The object to be inserted in the cache. </param>
/// <param name="absoluteExpiration">The time at which the inserted object expires and is removed from the cache.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::SetAbsolute(VARIANT key, VARIANT value, VARIANT expiration)
{
	CComVariant varExpiration = VARIANTDREF(&expiration);

	if (varExpiration.ChangeType(VT_DATE) != S_OK)
	{
		return AtlReportError(CLSID_Cache, _T("AbsoluteExpiration must be of type date."), IID_ICache, 0);
	}

	COleDateTime tmpExpires(varExpiration); 
	SYSTEMTIME time;
	tmpExpires.GetAsSystemTime(time);
	
	CachePolicy policy;

	policy.Type = Absolute;
	policy.AbsoluteExpiration = CTime(time);

	varExpiration.Clear();

	return Put(key, value, policy);
}

/// <summary>
/// Inserts an object into the <b>Cache</b>.
/// </summary>
/// <param name="key">The cache key used to reference the item.</param>
/// <param name="value">The object to be inserted into the cache.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::putref_Item(VARIANT key, VARIANT item)
{
	return put_Item(key, item);
}

/// <summary>
/// Inserts an object into the <b>Cache</b>.
/// </summary>
/// <param name="key">The cache key used to reference the item.</param>
/// <param name="value">The object to be inserted into the cache.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::put_Item(VARIANT key, VARIANT value)
{
	CachePolicy policy;

	policy.Type = None;
	
	return Put(key, value, policy);
}

/// <summary>
/// Inserts an object into the <b>Cache</b>.
/// </summary>
/// <param name="key">The cache key used to reference the item.</param>
/// <param name="value">The object to be inserted into the cache.</param>
/// <param name="policy">The expiration policy for the inserted object.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::Put(VARIANT key, VARIANT value, CachePolicy policy)
{
	//CComVariant varKey = VARIANTDREF(&key);
	//CComVariant varValue = VARIANTDREF(&value);

	CComVariant varKey; VariantCopy(&varKey, &VARIANTDREF(&key));
	CComVariant varValue; VariantCopy(&varValue, &VARIANTDREF(&value));

	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_Cache, _T("The key must be convertable to type string."), IID_ICache, 0);
	}

	

	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);
	
	CacheEntry entry;
	
	entry.Item = varValue;
	entry.Policy = policy;
	entry.Position = NULL;
		
	//calculate absolute expiration time
	CTime absExpiration;
	
	if (policy.Type == Sliding)
	{
		absExpiration = CTime::GetCurrentTime() + policy.SlidingExpiration;
	}
	else if (policy.Type == Absolute)
	{
		absExpiration = policy.AbsoluteExpiration;
	}
	
	if (absExpiration.GetTime() > 0)
	{
		entry.Position = m_cacheTimers.Insert((long)absExpiration.GetTime(), varKey.bstrVal);
	}
	
	Remove(varKey);

	m_cachedItems[varKey.bstrVal] = entry;
				
	return S_OK;
}

/// <summary>
/// Retrieves the specified item from the <b>Cache</b> object.
/// </summary>
/// <param name="key">The identifier for the cache item to retrieve.</param>
/// <param name="pItem">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::get_Item(VARIANT key, VARIANT *pItem)
{
	// Empty callers variant.
	VariantInit(pItem);

	CComVariant varKey = VARIANTDREF(&key);

	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_Cache, _T("The key must be convertable to type string."), IID_ICache, 0);
	}

	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	CAtlMap<CComBSTR, CacheEntry>::CPair* pPair = m_cachedItems.Lookup(varKey.bstrVal);

	if (pPair)
	{
		if (pPair->m_value.Policy.Type == Sliding)
		{
			CTime absExpiration = CTime::GetCurrentTime();
								
			absExpiration += pPair->m_value.Policy.SlidingExpiration;

			if (absExpiration.GetTime() > 0)
			{
					m_cacheTimers.RemoveAt(pPair->m_value.Position);
					pPair->m_value.Position = m_cacheTimers.Insert((long)absExpiration.GetTime(), varKey.bstrVal);
			}
		}

		VariantCopy(pItem, &pPair->m_value.Item);

		m_PerfCounterValues.Hits += 1;
	}
	else
	{
		m_PerfCounterValues.Misses += 1;
	}

	return S_OK;
}

/// <summary>
/// Returns the size in bytes of the cached object.
/// </summary>
/// <param name="key">The identifier for the cache item.</param>
/// <param name="pSize">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::GetSize(VARIANT key, long *pSize)
{
	CComVariant varKey = VARIANTDREF(&key);

	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_Cache, _T("The key must be convertable to type string."), IID_ICache, 0);
	}

	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	CAtlMap<CComBSTR, CacheEntry>::CPair* pPair = m_cachedItems.Lookup(varKey.bstrVal);

	if (pPair)
	{
		CComVariant item = pPair->m_value.Item;

		*pSize = item.GetSize();

		item.Clear();
	}

	varKey.Clear();

	return S_OK;
}


/// <summary>
/// Gets the number of items stored in the cache.
/// </summary>
/// <param name="pCount">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::get_Count(long *pCount)
{
	*pCount = m_cachedItems.GetCount();
	return S_OK;
}

/// <summary>
/// Determines whether the <b>Cache</b> contains the specified key.
/// </summary>
/// <param name="Key">The key to locate in the Cache.</param>
/// <param name="pExists">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::Exists(VARIANT Key, VARIANT_BOOL *pExists)
{
	CComVariant varKey = VARIANTDREF(&Key);

	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_Cache, _T("The key must be convertable to type string."), IID_ICache, 0);
	}
		
	bool bFound = m_cachedItems.Lookup(varKey.bstrVal) != 0;
	
	*pExists = bFound;

	varKey.Clear();

	return S_OK;
}

/// <summary>
/// Gets a collection containing the keys in the Cache.
/// </summary>
/// <param name="pKeysArray">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::Keys(VARIANT *pKeysArray)
{
	// Empty callers variant.
	::VariantInit(pKeysArray);

	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	// Get count of keys.
	int nSize = m_cachedItems.GetCount();

	// Build single-dim SafeArray of variant keys.
	SAFEARRAY FAR* psa;
	SAFEARRAYBOUND rgsabound[1];

	rgsabound[0].lLbound = 0;
	rgsabound[0].cElements = nSize;

	psa = ::SafeArrayCreate(VT_VARIANT, 1, rgsabound);
	if (psa == NULL)
	{
		return E_OUTOFMEMORY;
	}

	long ix[1];

	// Traverse internal list, create copy of keys, store in array.
	POSITION pos = m_cachedItems.GetStartPosition();
	int i = 0;

	// Now iterate the map, element by element
	while (pos != NULL) {
		ix[0] = i;

		CComBSTR sKey = m_cachedItems.GetKeyAt(pos);

		CComVariant varKey = sKey;

		HRESULT hr = ::SafeArrayPutElement(psa, ix, &varKey);

		if (FAILED(hr))
		{
			return hr;
		}

		m_cachedItems.GetNextKey(pos);
		i++;
	}

	// Set callers variant to the new SafeArray.
	V_VT(pKeysArray) = VT_ARRAY | VT_VARIANT;
	V_ARRAY(pKeysArray) = psa;

	return S_OK;
}


/// <summary>
///	Returns the absolute expiration date for cached object.
/// </summary>
/// <param name="Key">The identifier for the cache item.</param>
/// <param name="pExpires">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::Expires(VARIANT Key, VARIANT *pExpires)
{
	// Empty callers variant.
	::VariantInit(pExpires);

	CComVariant varKey = VARIANTDREF(&Key);
		
	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_Cache, _T("The key must be convertable to type string."), IID_ICache, 0);
	}

	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	CAtlMap<CComBSTR, CacheEntry>::CPair* pPair = m_cachedItems.Lookup(varKey.bstrVal);

	if (pPair && pPair->m_value.Position != NULL)
	{
		POSITION pos = pPair->m_value.Position;

		long lExpires = m_cacheTimers.GetKeyAt(pos);
		
		SYSTEMTIME stExpires;

		CTime(lExpires).GetAsSystemTime(stExpires);

		double date;
		
		AtlConvertSystemTimeToVariantTime(stExpires, &date);

		pExpires->date = date;
		pExpires->vt = VT_DATE;
	}
		
	return S_OK;
}

/// <summary>
/// Removes the specified item from the <b>Cache</b> object.
/// </summary>
/// <param name="Key">The identifier for the cache item.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::Remove(VARIANT Key)
{
	CComVariant varKey = VARIANTDREF(&Key);

	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_Cache, _T("The key must be convertable to type string."), IID_ICache, 0);
	}

	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);		
	
	CAtlMap<CComBSTR, CacheEntry>::CPair* pPair = m_cachedItems.Lookup(varKey.bstrVal);

	if (pPair)
	{
		if (pPair->m_value.Position != NULL)
		{
			m_cacheTimers.RemoveAt(pPair->m_value.Position);
		}
		
		m_cachedItems.RemoveAtPos(pPair);
	}

	return S_OK;
}

/// <summary>
/// Removes all keys and values from the <b>Cache</b>.
/// </summary>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::RemoveAll()
{
	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	m_cachedItems.RemoveAll();
	m_cacheTimers.RemoveAll();

	return S_OK;
}

/// <summary>
/// Returns an enumeration interface for the Cache keys.
/// </summary>
/// <param name="ppunk">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CCache::_NewEnum(IUnknown **ppunk)
{
	// Do some arg checking.
	if (ppunk == NULL)
		return E_POINTER;

	*ppunk = NULL;

	// Create an enumerator of VARIANTS.
	CComEnumVariant* pEnum = new CComObject<CComEnumVariant>;
	if (pEnum == NULL)
		return E_OUTOFMEMORY;

	// Keep other threads from changing the data for now.
	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	int nSize;
	nSize = m_cachedItems.GetCount();

	/* 
	 * Allocate and initialize an array of contiguous memory for 
	 * VARIANT objects.  This will be an array of all keys in the
	 * Dictionary.
	 */
	VARIANT* varVector = new VARIANT[nSize];

	// Zero the memory.
	memset(varVector, '\0', sizeof(VARIANT) * nSize);


	// Traverse internal list, create copy of keys, store in array.
	POSITION pos = m_cachedItems.GetStartPosition();
	int i = 0;

	// Now iterate the map, element by element
	while (pos != NULL) {
		m_cachedItems.GetKeyAt(pos).CopyTo(&varVector[i]);
		m_cachedItems.GetNextKey(pos);
		i++;
	}

	/*
	 * Initialize the enumerator.  It will take ownership of the
	 * array and free the array's memory when all references to this
	 * enumerator are Release()'ed.
	 */
	HRESULT hr = pEnum->Init(&varVector[0], &varVector[nSize], NULL, AtlFlagTakeOwnership);
	if (FAILED(hr))
	{
		delete pEnum;
		return hr;
	}

	// Return the enumerator interface pointer to the caller.
	hr = pEnum->QueryInterface(IID_IEnumVARIANT, (void**)ppunk);
	if (FAILED(hr))
		delete pEnum;

	return hr;
}
