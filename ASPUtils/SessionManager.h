// SessionManager.h : Declaration of the CSessionManager
#pragma once
#ifndef _SESSIONMANAGER_H_
#define _SESSIONMANAGER_H_

#include "resource.h"       // main symbols
#include "atlcoll.h"
#include <vector>

#include "SessionStore.h"
#include "CustomSession.h"
#include "ASPContext.h"


#include "ASPUtils_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;
using namespace std;

// CSessionManager

class ATL_NO_VTABLE CSessionManager :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CSessionManager, &CLSID_SessionManager>,
	public ISupportErrorInfo,
	public IDispatchImpl<ISessionManager, &IID_ISessionManager, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSessionManager()
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SESSIONMANAGER)


BEGIN_COM_MAP(CSessionManager)
	COM_INTERFACE_ENTRY(ISessionManager)
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

	CComPtr<IASPSessionStoreProvider> m_piStoreProvider;
	CAtlMap<CComBSTR, CComPtr<ICustomSession>> m_Sessions;
	CComBSTR m_PageHandlerProgId;
	
	STDMETHOD(get_Session)(BOOL bReadOnly, ICustomSession **ppSessionObject);
	STDMETHOD(StartSession)();
	STDMETHOD(EndSession)();
	STDMETHOD(OnEndPage)(BSTR bstrSessionId, void* lLockId);

private:

	STDMETHOD(Initialize)();
	STDMETHOD(Terminate)();
	STDMETHOD(CreatePageHandler)(IServer *server, IPageHandler **pageHandler);
	STDMETHOD(WriteSessionCookie)(IResponse *response, BSTR bstrSessionId);
	STDMETHOD(ReadSessionCookie)(IRequest* pRequest, BSTR* pBstrSessionId);
	STDMETHOD(LoadSessionState)(BSTR bstrSessionId, BOOL bReadOnly, void** pLockId, ICustomSession* piCustomSession);
	STDMETHOD(SaveSessionState)(BSTR bstrSessionId, void* lLockId, ICustomSession* piCustomSession);
	STDMETHOD(RegisterOnPage)(BSTR bstrSessionId, void* lLockId, IServer *pServer, ICustomSession* pCustomSession);
	
};

OBJECT_ENTRY_AUTO(__uuidof(SessionManager), CSessionManager)
#endif // !_SESSIONMANAGER_H_