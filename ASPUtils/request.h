// Request.h : Declaration of the CRequest

#pragma once

#include "resource.h"       // main symbols
#include "asptlb.h"
#include "ASPUtils_i.h"
#include "atlcom.h"

#ifndef __REQUEST_H_ 
#define __REQUEST_H_ 
 
///////////////////////////////////////////////////////////////////////////// 
// CRequest 
//class CRequestDictionary; 
 
[coclass, uuid("9A1A3D89-73E0-4B1A-90F5-E2B29E5B4E6A")]
class CRequest : public IRequest
{ 
private: 
	//CRequestDictionary *m_pQueryString; 
	//CRequestDictionary *m_pForm; 
	//CRequestDictionary *m_pCookie; 
	//CRequestDictionary *m_pServerVariables; 
	 
public: 
	CRequest(); 
	~CRequest(); 
 
//
//BEGIN_COM_MAP(CRequest) 
//	COM_INTERFACE_ENTRY(IRequest) 
//	COM_INTERFACE_ENTRY(IDispatch) 
//END_COM_MAP() 
 
public: 
// IRequest 
	STDMETHOD(get_TotalBytes)(/*[out, retval]*/ long *pVal); 
	STDMETHOD(get_ServerVariables)(IRequestDictionary **ppDictReturn); 
	STDMETHOD(get_QueryString)(/* [out, retval] */ IRequestDictionary **ppDictReturn); 
	STDMETHOD(get_Form)(/* [out, retval] */ IRequestDictionary **ppDictReturn); 
	STDMETHOD(get_Cookies)(/* [out, retval] */ IRequestDictionary **ppDictReturn); 
	STDMETHOD(BinaryRead)(/* [in, out] */ VARIANT *pvarCount, /* [out, retval] */ VARIANT *pvarReturn); 
}; 
 
#endif //__REQUEST_H_ 