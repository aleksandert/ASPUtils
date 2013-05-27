// ResourceAccessor.cpp : Implementation of CResourceAccessor

#include "stdafx.h"
#include "ResourceAccessor.h"


/// <summary>
/// De-references the VARIANT argument.  We receive variants by reference
/// when inside a VB 'for each|loop'.  We must de-reference VARIANTs because
/// Cache does not know how to compare (operator==) VARIANTs BYREF.
/// </summary>
/// <param name="pvar">The pvar.</param>
/// <returns></returns>
inline VARIANT VARIANTDREF(const VARIANT* pvar)
{
	return (V_VT(pvar) == (VT_VARIANT | VT_BYREF)) ? *(V_VARIANTREF(pvar)) : *pvar;
}


STDMETHODIMP CResourceAccessor::EnsureContext()
{
	if (contextInited)
	{
		return S_OK;
	}

	// Get the IObjectContext Interface
	CComPtr<IObjectContext> piObjectContext;
    		
	HRESULT hr = GetObjectContext(&piObjectContext);

	if (FAILED(hr))
	{
		return hr;
	}

	// Get the Properties interface
    CComPtr<IGetContextProperties> piProperties;

    piObjectContext->QueryInterface(IID_IGetContextProperties, (void**) &piProperties);
	
	// Get ASP Intrinsic Objects

	CComPtr<IApplicationObject> piApplicationObject;
	CComPtr<ISessionObject> piSessionObject;
	CComPtr<IServer> piServer;

	CComVariant vInterface;
	
	piProperties->GetProperty(L"Server", &vInterface);
	vInterface.pdispVal->QueryInterface(__uuidof(IServer), reinterpret_cast<void**>(&piServer));

	NetInterop::IASPContextPtr ipASPContext;

	hr = ipASPContext.CreateInstance(__uuidof(NetInterop::ASPContext));

	ipASPContext->InitializeContext(piServer);
		
	ipASPContext.Release();

	// Prepare Resource Accessor
	hr = m_ipResources.CreateInstance(__uuidof(NetInterop::ResourceAccessor));

	if (FAILED(hr)) return hr;
	

	contextInited = true;

	return S_OK;
}

/// <summary>
/// Gets an application-level resource object based on the specified classKey and resourceKey properties.
/// </summary>
/// <param name="classKey">A string representing a classKey.</param>
/// <param name="resourceKey">A string representing a resourceKey.</param>
/// <param name="pObject">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CResourceAccessor::GetGlobalResourceObject(VARIANT classKey, VARIANT resourceKey, VARIANT *pRetVal)
{
	VariantInit(pRetVal);

	CComVariant varClassKey = VARIANTDREF(&classKey);
	CComVariant varResourceKey = VARIANTDREF(&resourceKey);

	if (varClassKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_ResourceAccessor, _T("The classKey must be convertable to type string."), IID_IResourceAccessor, 0);
	}

	if (varClassKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_ResourceAccessor, _T("The resourceKey must be convertable to type string."), IID_IResourceAccessor, 0);
	}
	
	EnsureContext();

	NetInterop::IResourceAccessorPtr ipResources;

	HRESULT hr = ipResources.CreateInstance(__uuidof(NetInterop::ResourceAccessor));

	if (FAILED(hr)) return hr;
		
	ipResources->GetGlobalResourceObject(varClassKey.bstrVal, varResourceKey.bstrVal, pRetVal); 

	ipResources.Release();

	return S_OK;
}

STDMETHODIMP CResourceAccessor::GetCulturedGlobalResourceObject(VARIANT classKey, VARIANT resourceKey, VARIANT culture, VARIANT* pRetVal)
{
	VariantInit(pRetVal);

	CComVariant varClassKey = VARIANTDREF(&classKey);
	CComVariant varResourceKey = VARIANTDREF(&resourceKey);
	CComVariant varCulture = VARIANTDREF(&culture);

	if (varClassKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_ResourceAccessor, _T("The classKey must be convertable to type string."), IID_IResourceAccessor, 0);
	}

	if (varClassKey.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_ResourceAccessor, _T("The resourceKey must be convertable to type string."), IID_IResourceAccessor, 0);
	}

	if (varCulture.ChangeType(VT_BSTR))
	{
		return AtlReportError(CLSID_ResourceAccessor, _T("The culture must be convertable to type string."), IID_IResourceAccessor, 0);
	}

	EnsureContext();

	NetInterop::IResourceAccessorPtr ipResources;
	
	ipResources->GetCulturedGlobalResourceObject(varClassKey.bstrVal, varResourceKey.bstrVal, varCulture.bstrVal, pRetVal); 

	return S_OK;
}

STDMETHODIMP CResourceAccessor::GetLocalResourceObject(VARIANT resourceKey, VARIANT* pRetVal)
{
	return S_OK;
}
	
STDMETHODIMP CResourceAccessor::GetCulturedLocalResourceObject(VARIANT resourceKey, VARIANT culture, VARIANT* pRetVal)
{
	return S_OK;
}
