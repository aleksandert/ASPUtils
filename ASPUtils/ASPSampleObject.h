// ASPSampleObject.h : Declaration of the CASPSampleObject

#pragma once

#include "resource.h"       // main symbols
#include <asptlb.h>         // Active Server Pages Definitions

#include "ASPUtils_i.h"

using namespace ATL;



// CASPSampleObject

class ATL_NO_VTABLE CASPSampleObject :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CASPSampleObject, &CLSID_ASPSampleObject>,
	public ISupportErrorInfo,
	public IDispatchImpl<IASPSampleObject, &IID_IASPSampleObject, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CASPSampleObject()
	{
		m_pUnkMarshaler = NULL;
		m_bOnStartPageCalled = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ASPSAMPLEOBJECT)


BEGIN_COM_MAP(CASPSampleObject)
	COM_INTERFACE_ENTRY(IASPSampleObject)
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

// IASPSampleObject
public:
	//Active Server Pages Methods
	STDMETHOD(OnStartPage)(IUnknown* IUnk);
	STDMETHOD(OnEndPage)();
private:
	CComPtr<IRequest> m_piRequest;					//Request Object
	CComPtr<IResponse> m_piResponse;				//Response Object
	CComPtr<ISessionObject> m_piSession;			//Session Object
	CComPtr<IServer> m_piServer;					//Server Object
	CComPtr<IApplicationObject> m_piApplication;	//Application Object
	BOOL m_bOnStartPageCalled;						//OnStartPage successful?
};

OBJECT_ENTRY_AUTO(__uuidof(ASPSampleObject), CASPSampleObject)
