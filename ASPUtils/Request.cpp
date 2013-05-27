#include "stdafx.h"
#include "ASPObjects.h"
   
/////////////////////////////////////////////////////////////////////////////   
// CRequest   

STDMETHODIMP CRequest::get_TotalBytes(long *pVal)   
{   
    return S_OK;   
}   
   
//  Like GetServerVariable ISAPI call.   
STDMETHODIMP CRequest::get_ServerVariables(IRequestDictionary **ppDictReturn)   
{   
  /*  if (m_pServerVariables)   
        return m_pServerVariables->QueryInterface(IID_IRequestDictionary,(void **) ppDictReturn);   
   */
    return E_NOTIMPL;   
}   
   
   
STDMETHODIMP CRequest::get_QueryString(IRequestDictionary **ppDictReturn)   
{   
   /* if (m_pQueryString)   
        return m_pQueryString->QueryInterface(IID_IRequestDictionary,(void **) ppDictReturn);   
   */
    return E_NOTIMPL;   
}   
   
STDMETHODIMP CRequest::get_Cookies(IRequestDictionary **ppDictReturn)   
{   
   /* if (m_pCookie)   
        return m_pCookie->QueryInterface(IID_IRequestDictionary,(void **) ppDictReturn);   
    */   
    return E_NOTIMPL;   
}   
   
STDMETHODIMP CRequest::get_Form(IRequestDictionary **ppDictReturn)   
{   
  /*  if (m_pForm)
        return m_pForm->QueryInterface(IID_IRequestDictionary,(void **) ppDictReturn);   
  */  
    return E_NOTIMPL;   
}   
   
   
STDMETHODIMP CRequest::BinaryRead(VARIANT *pvarCount, VARIANT *pvarReturn)   
{   
	VariantClear(pvarReturn);
   
    return S_OK;   
}   
     
CRequest::CRequest()   
{   
	//m_pQueryString = CreateCRequestDictionary(QUERY_STRING_TYPE, NULL);   
	//m_pForm = CreateCRequestDictionary(FORM_TYPE,NULL);   
 //   m_pCookie= CreateCRequestDictionary(REQUEST_COOKIE_TYPE, NULL);   
	//m_pServerVariables = CreateCRequestDictionary(SERVER_VARIABLE_TYPE, NULL);   
}   
   
CRequest::~CRequest()   
{   
  /*  if (m_pQueryString)   
        m_pQueryString->Release();   
   
    if (m_pForm)   
        m_pForm->Release();   
   
    if (m_pCookie)   
        m_pCookie->Release();   
   
    if (m_pServerVariables)   
        m_pServerVariables->Release();   */
}   
   