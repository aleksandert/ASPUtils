// PageHandler.h : Declaration of the CPageHandler

#pragma once
#ifndef _PAGEHANDLER_H_
#define _PAGEHANDLER_H_

#include "resource.h"       // main symbols
#include <asptlb.h>         // Active Server Pages Definitions
#include "ASPUtils_i.h"

using namespace ATL;



// CPageHandler

class ATL_NO_VTABLE CPageHandler :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CPageHandler, &CLSID_PageHandler>,
	public ISupportErrorInfo,
	public IDispatchImpl<IPageHandler, &IID_IPageHandler, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CPageHandler()
	{
		m_pUnkMarshaler = NULL;
//		m_bOnStartPageCalled = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PAGEHANDLER)


BEGIN_COM_MAP(CPageHandler)
	COM_INTERFACE_ENTRY(IPageHandler)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}

	CComPtr<IUnknown> m_pUnkMarshaler;

	CComPtr<ISessionManager> m_SessionManager;
	CComBSTR m_SessionId;
	void* m_LockId;

// IPageHandler
public:
	//Active Server Pages Methods
	STDMETHOD(OnStartPage)(IUnknown* IUnk);
	STDMETHOD(OnEndPage)();

	STDMETHOD(RegisterNotifyOnEndPage)(ISessionManager *pSessionManager, BSTR bstrSessionId, void* lLockId);

private:
	//CComPtr<IRequest> m_piRequest;					//Request Object
	//CComPtr<IResponse> m_piResponse;				//Response Object
	//CComPtr<ISessionObject> m_piSession;			//Session Object
	//CComPtr<IServer> m_piServer;					//Server Object
	//CComPtr<IApplicationObject> m_piApplication;	//Application Object
	//BOOL m_bOnStartPageCalled;						//OnStartPage successful?
};

OBJECT_ENTRY_AUTO(__uuidof(PageHandler), CPageHandler)
#endif // !_PAGEHANDLER_H_