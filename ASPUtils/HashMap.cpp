// HashMap.cpp : Implementation of CHashMap

#include "stdafx.h"
#include "HashMap.h"


// CHashMap

STDMETHODIMP CHashMap::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IHashMap
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CHashMap::Initialize()
{
	return S_OK;
}

STDMETHODIMP CHashMap::Terminate()
{
	RemoveAll();

	return S_OK;
}

/// <summary>
/// Inserts an object into the <b>HashMap</b>.
/// </summary>
/// <param name="key">The HashMap key used to reference the item.</param>
/// <param name="value">The object to be inserted into the HashMap.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::Set(VARIANT key, VARIANT value)
{
	return Put(key, value);
}

/// <summary>
/// Inserts an object into the <b>HashMap</b>.
/// </summary>
/// <param name="key">The HashMap key used to reference the item.</param>
/// <param name="value">The object to be inserted into the HashMap.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::putref_Item(VARIANT key, VARIANT item)
{
	return put_Item(key, item);
}

/// <summary>
/// Inserts an object into the <b>HashMap</b>.
/// </summary>
/// <param name="key">The HashMap key used to reference the item.</param>
/// <param name="value">The object to be inserted into the HashMap.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::put_Item(VARIANT key, VARIANT value)
{
	return Put(key, value);
}

/// <summary>
/// Inserts an object into the <b>HashMap</b>.
/// </summary>
/// <param name="key">The HashMap key used to reference the item.</param>
/// <param name="value">The object to be inserted into the HashMap.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::Put(VARIANT key, VARIANT value)
{
	CComVariant varKey; VariantCopy(&varKey, &VARIANTDREF(&key));
	CComVariant varValue; VariantCopy(&varValue, &VARIANTDREF(&value));

	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_HashMap, _T("The key must be convertable to type string."), IID_IHashMap, 0);
	}

//	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);
	
	m_Items[varKey.bstrVal] = varValue;
			
	return S_OK;
}

/// <summary>
/// Retrieves the specified item from the <b>HashMap</b> object.
/// </summary>
/// <param name="key">The identifier for the HashMap item to retrieve.</param>
/// <param name="pItem">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::get_Item(VARIANT key, VARIANT *pItem)
{
	// Empty callers variant.
	VariantInit(pItem);

	CComVariant varKey = VARIANTDREF(&key);

	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_HashMap, _T("The key must be convertable to type string."), IID_IHashMap, 0);
	}

//	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);
	
	CComVariant item;

	m_Items.Lookup(varKey.bstrVal, item);

	VariantCopy(pItem, &item);

	return S_OK;
}

/// <summary>
/// Gets the number of items stored in the HashMap.
/// </summary>
/// <param name="pCount">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::get_Count(long *pCount)
{
	*pCount = m_Items.GetCount();

	return S_OK;
}

/// <summary>
/// Determines whether the <b>HashMap</b> contains the specified key.
/// </summary>
/// <param name="Key">The key to locate in the HashMap.</param>
/// <param name="pExists">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::Exists(VARIANT Key, VARIANT_BOOL *pExists)
{
	CComVariant varKey = VARIANTDREF(&Key);

	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_HashMap, _T("The key must be convertable to type string."), IID_IHashMap, 0);
	}
		
	bool bFound = m_Items.Lookup(varKey.bstrVal) != 0;
	
	*pExists = bFound;

	varKey.Clear();

	return S_OK;
}

/// <summary>
/// Gets a collection containing the keys in the HashMap.
/// </summary>
/// <param name="pKeysArray">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::Keys(VARIANT *pKeysArray)
{
	// Empty callers variant.
	::VariantInit(pKeysArray);

//	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	// Get count of keys.
	int nSize = m_Items.GetCount();

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
	POSITION pos = m_Items.GetStartPosition();
	int i = 0;

	// Now iterate the map, element by element
	while (pos != NULL) {
		ix[0] = i;

		CComBSTR sKey = m_Items.GetKeyAt(pos);

		CComVariant varKey = sKey;

		HRESULT hr = ::SafeArrayPutElement(psa, ix, &varKey);

		if (FAILED(hr))
		{
			return hr;
		}

		m_Items.GetNextKey(pos);
		i++;
	}

	// Set callers variant to the new SafeArray.
	V_VT(pKeysArray) = VT_ARRAY | VT_VARIANT;
	V_ARRAY(pKeysArray) = psa;

	return S_OK;
}

/// <summary>
/// Removes the specified item from the <b>HashMap</b> object.
/// </summary>
/// <param name="Key">The identifier for the HashMap item.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::Remove(VARIANT Key)
{
	CComVariant varKey = VARIANTDREF(&Key);

	//If key is not string, return error.
	if (varKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_HashMap, _T("The key must be convertable to type string."), IID_IHashMap, 0);
	}

	CComBSTR sKey = varKey.bstrVal;

//	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);		
	
	m_Items.RemoveKey(sKey);
	
	return S_OK;
}

/// <summary>
/// Removes all keys and values from the <b>HashMap</b>.
/// </summary>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::RemoveAll()
{
//	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	m_Items.RemoveAll();
	
	return S_OK;
}

/// <summary>
/// Returns an enumeration interface for the HashMap keys.
/// </summary>
/// <param name="ppunk">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CHashMap::_NewEnum(IUnknown **ppunk)
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
//	CComCritSecLock<CComAutoCriticalSection> DataLock(m_CriticalSection);

	int nSize;
	nSize = m_Items.GetCount();

	/* 
	 * Allocate and initialize an array of contiguous memory for 
	 * VARIANT objects.  This will be an array of all keys in the
	 * Dictionary.
	 */
	VARIANT* varVector = new VARIANT[nSize];

	// Zero the memory.
	memset(varVector, '\0', sizeof(VARIANT) * nSize);


	// Traverse internal list, create copy of keys, store in array.
	POSITION pos = m_Items.GetStartPosition();
	int i = 0;

	// Now iterate the map, element by element
	while (pos != NULL) {
		m_Items.GetKeyAt(pos).CopyTo(&varVector[i]);
		m_Items.GetNextKey(pos);
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
