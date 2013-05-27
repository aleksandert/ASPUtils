// VariantDictionary.cpp : Implementation of CVariantDictionary

#include "stdafx.h"
#include "VariantDictionary.h"


// CVariantDictionary

STDMETHODIMP CVariantDictionary::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IVariantDictionary
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CVariantDictionary::Lookup(VARIANT VarKey, ItemType* itemType)
{
	HRESULT hr;

	CComVariant var;

	if (VarKey.vt != VT_BSTR)
	{
		// If the index isn't a string, but can be converted to a long value, get item by index
		hr = var.ChangeType(VT_I4, &VarKey);

		if (SUCCEEDED(hr))
		{
			long lIndex = var.lVal;
			
			m_coll.begin();

			//Index is 1-based
			if (lIndex < 1)
				return E_INVALIDARG;
			
			HRESULT hr = E_FAIL;
			lIndex--;
			ContainerType::const_iterator iter = m_coll.begin();
			while (iter != m_coll.end() && lIndex > 0)
			{
				iter++;
				lIndex--;
			}
			if (iter != m_coll.end())
				hr = _Copy<ContainerType::value_type>::copy(itemType, &*iter);
			
			return hr;
		}
	}

	// Otherwise, we assume index is a key into the map
	hr = var.ChangeType(VT_BSTR, &VarKey);

	// If we can't convert to a string, just return
	if (FAILED(hr))
		return hr;

	ContainerType::iterator it = m_coll.find(var);

	// If item not found, just return
	if (it == m_coll.end())
		return E_FAIL;
	
	hr = _Copy<ContainerType::value_type>::copy(itemType, &*it);
	
	return hr;
}

STDMETHODIMP CVariantDictionary::get_Item(/* [in] */ VARIANT VarKey, /* [retval][out] */ VARIANT *pvar)
{
	CComVariant vtKey;
	CComVariant vtOut;

	TestHR(vtOut.Attach(pvar));

	// If the index isn't a string, but can be converted to a long value, get item by index
	if (VarKey.vt != VT_BSTR && SUCCEEDED(vtKey.ChangeType(VT_I4, &VarKey)))
	{
		long lIndex = vtKey.lVal;
			
		m_coll.begin();

		//Index is 1-based
		if (lIndex >= 1)
		{
			lIndex--;
			ContainerType::const_iterator iter = m_coll.begin();
			while (iter != m_coll.end() && lIndex > 0)
			{
				iter++;
				lIndex--;
			}
			if (iter != m_coll.end())
			{
				vtOut.Copy(&iter->second);
			}
		}
	}
	// Otherwise, we assume index is a key into the map
	else if (SUCCEEDED(vtKey.ChangeType(VT_BSTR, &VarKey)))
	{
		ContainerType::iterator it = m_coll.find(vtKey);
	
		if (it != m_coll.end())
		{
			vtOut.Copy(&it->second);
		}
	}
	
	TestHR(vtOut.Detach(pvar));

	return S_OK;
}

STDMETHODIMP CVariantDictionary::put_Item(/* [in] */ VARIANT VarKey, /* [in] */ VARIANT VarValue)
{
	CComVariant var;

	TestHR(var.ChangeType(VT_BSTR, &VarKey));
	
	m_coll[var] = CComVariant(VarValue);
	m_bRequiresSave = TRUE;

	return S_OK;
}

STDMETHODIMP CVariantDictionary::putref_Item(/* [in] */ VARIANT VarKey, /* [in] */ VARIANT VarValue)
{
	CComVariant var;

	TestHR(var.ChangeType(VT_BSTR, &VarKey));
	
	m_coll[var] = VarValue;
	m_bRequiresSave = TRUE;

	return S_OK;
}

STDMETHODIMP CVariantDictionary::get_Key(/* [in] */ VARIANT VarKey, /* [retval][out] */ VARIANT *pvar)
{
	CComVariant vtKey;
	CComVariant vtOut;

	TestHR(vtOut.Attach(pvar));

	// If the index isn't a string, but can be converted to a long value, get item by index
	if (VarKey.vt != VT_BSTR && SUCCEEDED(vtKey.ChangeType(VT_I4, &VarKey)))
	{
		long lIndex = vtKey.lVal;
			
		m_coll.begin();

		//Index is 1-based
		if (lIndex >= 1)
		{
			lIndex--;
			ContainerType::const_iterator iter = m_coll.begin();
			while (iter != m_coll.end() && lIndex > 0)
			{
				iter++;
				lIndex--;
			}
			if (iter != m_coll.end())
			{
				vtOut.Copy(&iter->first);
			}
		}
	}
	// Otherwise, we assume index is a key into the map
	else if (SUCCEEDED(vtKey.ChangeType(VT_BSTR, &VarKey)))
	{
		ContainerType::iterator it = m_coll.find(vtKey);
	
		if (it != m_coll.end())
		{
			vtOut.Copy(&it->first);
		}
	}
	
	TestHR(vtOut.Detach(pvar));

	return S_OK;
}

STDMETHODIMP CVariantDictionary::get_Count(/* [retval][out] */ int *cStrRet)
{
	return CollectionType::get_Count((long*)cStrRet);
}

STDMETHODIMP CVariantDictionary::get__NewEnum(/* [retval][out] */ IUnknown **ppEnumReturn)
{
	return CollectionType::get__NewEnum(ppEnumReturn);
}

STDMETHODIMP CVariantDictionary::Remove(/* [in] */ VARIANT VarKey)
{
	CComVariant var;

	TestHR(var.ChangeType(VT_BSTR, &VarKey));

	if (m_coll.erase(var) == 0)
		return E_INVALIDARG;
	
	m_bRequiresSave = TRUE;
	
	return S_OK;
}

STDMETHODIMP CVariantDictionary::RemoveAll()
{
	m_coll.clear();

	return S_OK;
}

HRESULT CVariantDictionary::IPersistStreamInit_Load(LPSTREAM pStm, const ATL_PROPMAP_ENTRY* pMap)
{
	// Load the property map.
	TestHR(IPersistStreamInitImpl::IPersistStreamInit_Load(pStm, pMap))
	
	// Load the STL collection.
	TestHR((_Persist<ContainerType>::Load(pStm, &m_coll)))

	return S_OK;
}


HRESULT CVariantDictionary::IPersistStreamInit_Save(LPSTREAM pStm, BOOL fClearDirty, const ATL_PROPMAP_ENTRY* pMap)
{ 
	// Save the property map.
	TestHR(IPersistStreamInitImpl::IPersistStreamInit_Save(pStm, fClearDirty, pMap))
	
	// Save the STL collection.
	TestHR((_Persist<ContainerType>::Save(pStm, fClearDirty, &m_coll)))

	if (fClearDirty) // IPersistStreamInitImpl does not clear the dirty flag.
		m_bRequiresSave = FALSE;
	return S_OK;
}

STDMETHODIMP CVariantDictionary::GetSizeMax(ULARGE_INTEGER* pcbSize)
{
	ULARGE_INTEGER cbSizeTemp = {0};

	// Get the required size for the property map.
	TestHR(IPersistStreamInitImpl::GetSizeMax(pcbSize))
	
	// Get the required size for the STL collection.
	TestHR((_Persist<ContainerType>::GetSizeMax(&cbSizeTemp, &m_coll)))
	pcbSize->QuadPart += cbSizeTemp.QuadPart;

	return S_OK;
}