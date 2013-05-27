// CustomSession.cpp : Implementation of CCustomSession

#include "stdafx.h"
#include "CustomSession.h"
#include "Context.h"
#include "VariantDictionary.h"
#include "SessionManager.h"

// CCustomSession

STDMETHODIMP CCustomSession::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_ICustomSession
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CCustomSession::Initialize()
{
	TestHR(m_piStaticObjects.CoCreateInstance(__uuidof(VariantDictionary), NULL, CLSCTX_ALL));
	TestHR(m_piContents.CoCreateInstance(__uuidof(VariantDictionary), NULL, CLSCTX_ALL));

	return S_OK;
}

STDMETHODIMP CCustomSession::Terminate()
{
	m_piStaticObjects.Release();
	m_piContents.Release();

	return S_OK;
}

STDMETHODIMP CCustomSession::Init(ISessionObject* pSession)
{
	pSession->get_CodePage(&m_CodePage);
	pSession->get_LCID(&m_LCID);
	pSession->get_SessionID(&m_SessionID);
	pSession->get_Timeout(&m_Timeout);

	//copy contents
	CComPtr<IVariantDictionary> piContents;

	TestHR(pSession->get_Contents(&piContents));

	int cntContents = 0;

	TestHR(piContents->get_Count(&cntContents));
	
	for (int i = 1; i<=cntContents; i++)
	{
		CComVariant index(i);

		CComVariant key;
		CComVariant val;
				
		TestHR(piContents->get_Key(index, &key));
		TestHR(piContents->get_Item(index, &val));

		TestHR(m_piContents->put_Item(key, val));
	}

	//copy static objects
	CComPtr<IVariantDictionary> piStaticObjects;

	TestHR(pSession->get_StaticObjects(&piStaticObjects));
	
	int cntStaticObjects = 0;

	TestHR(piStaticObjects->get_Count(&cntStaticObjects));
	
	for (int i = 1; i<=cntStaticObjects; i++)
	{
		CComVariant index(i);

		CComVariant key;
		CComVariant val;
		
		TestHR(piStaticObjects->get_Key(index, &key));
		TestHR(piStaticObjects->get_Item(index, &val));

		TestHR(m_piStaticObjects->put_Item(key, val));
	}

	return S_OK;
}

STDMETHODIMP CCustomSession::get_Value(BSTR bstrValue, VARIANT* pVar)
{
	VariantClear(pVar);

	m_piContents->get_Item(CComVariant(bstrValue), pVar);

	return S_OK;
}

STDMETHODIMP CCustomSession::put_Value(BSTR bstrValue, VARIANT pVar)
{
	CComVariant vtKey = bstrValue;
	CComVariant vtVal = pVar;

	m_bRequiresSave = TRUE;

	return m_piContents->put_Item(vtKey, vtVal);
}

STDMETHODIMP CCustomSession::putref_Value(BSTR bstrValue, VARIANT pVar)
{
	CComVariant vtKey = bstrValue;
	CComVariant vtVal = pVar;

	m_bRequiresSave = TRUE;

	return m_piContents->putref_Item(vtKey, vtVal);
}

STDMETHODIMP CCustomSession::get_SessionID(BSTR* pRetVal)
{
	m_SessionID.CopyTo(pRetVal);

	return S_OK;
}

STDMETHODIMP CCustomSession::get_Timeout(long* plvar)
{
	*plvar = m_Timeout;

	return S_OK;
}

STDMETHODIMP CCustomSession::put_Timeout(long lvar)
{
	m_Timeout = lvar;

	m_bRequiresSave = TRUE;

	return S_OK;
}

STDMETHODIMP CCustomSession::Abandon()
{
	return E_NOTIMPL;
}

STDMETHODIMP CCustomSession::get_CodePage(long* plvar)
{
	*plvar = m_CodePage;

	return S_OK;
}

STDMETHODIMP CCustomSession::put_CodePage(long lvar)
{
	m_CodePage = lvar;

	m_bRequiresSave = TRUE;

	return S_OK;
}

STDMETHODIMP CCustomSession::get_LCID(long* plvar)
{
	*plvar = m_LCID;

	return S_OK;
}

STDMETHODIMP CCustomSession::put_LCID(long lvar)
{
	m_LCID = lvar;

	m_bRequiresSave = TRUE;

	return S_OK;
}

STDMETHODIMP CCustomSession::get_StaticObjects(IVariantDictionary **ppTaggedObjects)
{
	return m_piStaticObjects.CopyTo(ppTaggedObjects);
}

STDMETHODIMP CCustomSession::get_Contents(IVariantDictionary **ppProperties)
{
	return m_piContents.CopyTo(ppProperties);
}

HRESULT CCustomSession::IPersistStreamInit_Load(LPSTREAM pStm, const ATL_PROPMAP_ENTRY* pMap)
{
	// Read sessionId
	TestHR(m_SessionID.ReadFromStream(pStm));

	// Read the property map.
	TestHR(IPersistStreamInitImpl::IPersistStreamInit_Load(pStm, pMap));
	
	// Read the contents dictionary
	CComPtr<IPersistStreamInit> piPersist;
	TestHR(m_piContents->QueryInterface<IPersistStreamInit>(&piPersist));
	TestHR(piPersist->InitNew());
	TestHR(piPersist->Load(pStm));

	return S_OK;
}

HRESULT CCustomSession::IPersistStreamInit_Save(LPSTREAM pStm, BOOL fClearDirty, const ATL_PROPMAP_ENTRY* pMap)
{ 
	// Write sessionId
	TestHR(m_SessionID.WriteToStream(pStm));

	// Write the property map
	TestHR(IPersistStreamInitImpl::IPersistStreamInit_Save(pStm, fClearDirty, pMap))
	
	// Write the contents dictionary
	CComPtr<IPersistStreamInit> piPersist;
	TestHR(m_piContents->QueryInterface<IPersistStreamInit>(&piPersist));
	TestHR(piPersist->Save(pStm, fClearDirty));
	
	if (fClearDirty) // IPersistStreamInitImpl does not clear the dirty flag.
		m_bRequiresSave = FALSE;

	return S_OK;
}
