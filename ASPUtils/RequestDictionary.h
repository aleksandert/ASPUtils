#pragma once

#include "resource.h"       // main symbols
#include "asptlb.h"
#include "ASPUtils_i.h"
#include "atlcom.h"
 
#ifndef __DICT_H_ 
#define __DICT_H_ 
 
 
class ATL_NO_VTABLE CRequestDictionary :  
	public CComObjectRootEx<CComMultiThreadModel>, 
//	public CComCoClass<CRequestDictionary, &CLSID_RequestDictionary>, 
	public IDispatchImpl<IRequestDictionary, &IID_IRequestDictionary, &LIBID_ASPUtilsLib>
{ 
private: 
	DICT_TYPE m_dictType; 
	PSTR m_pszRawData;				// original, unformatted data.   
									// Read only!! Not a copy of httpd data buffer.			 
//	long			m_cRef; 
	 
 
public: 
//	BOOL ParseInput();		// parses post, query string, and cookie data 
//	BOOL WriteCookies();	// for Response.Cookies, setting header 
 
	STDMETHODIMP GetServerVariables(BSTR bstrName, VARIANT* pvarReturn); 
	 
	CRequestDictionary(); 
	CRequestDictionary(DICT_TYPE dt, PSTR pszData); 
	~CRequestDictionary(); 
	friend CRequestDictionary * CreateCRequestDictionary(DICT_TYPE dt, PSTR pszData); 
	friend STDMETHODIMP CRequest::get_Form(IRequestDictionary **ppDictReturn); 
 
 
	// Collect 
 	STDMETHOD(get_Item)(/* [in, optional] */ VARIANT Var, /* [out, retval] */ VARIANT* pVariantReturn); 
	STDMETHOD(put_Item)(/* [optional, in] */ VARIANT varKey, /* [in] */ BSTR bstrValue); 
  	STDMETHOD(get__NewEnum)(/*  [out, retval] */ IUnknown** ppEnumReturn); 
    STDMETHOD(get_Count)(/* [out, retval] */ int* cStrRet); 
    STDMETHOD(get_Key)(/* [in] */ VARIANT VarKey,  /* [out, retval] */ VARIANT* pvar); 
}; 
 
 
 
CRequestDictionary * CreateCRequestDictionary(); 
CRequestDictionary * CreateCRequestDictionary(DICT_TYPE dt, PSTR pszData); 

#endif // __DICT_H_ 