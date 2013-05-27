// ResourceAccessor.h : Declaration of the CResourceAccessor

#pragma once
#include "resource.h"       // main symbols

#include "ASPUtils_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CResourceAccessor

class ATL_NO_VTABLE CResourceAccessor :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CResourceAccessor, &CLSID_ResourceAccessor>,
	public IDispatchImpl<IResourceAccessor, &IID_IResourceAccessor, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CResourceAccessor()
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RESOURCEACCESSOR)


BEGIN_COM_MAP(CResourceAccessor)
	COM_INTERFACE_ENTRY(IResourceAccessor)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()



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

public:
	STDMETHOD(GetGlobalResourceObject)(/*[in]*/ VARIANT classKey, /*[in]*/ VARIANT resourceKey, /*[out, retval]*/ VARIANT* pRetVal);
	STDMETHOD(GetCulturedGlobalResourceObject)(/*[in]*/ VARIANT classKey, /*[in]*/ VARIANT resourceKey, /*[in]*/ VARIANT culture, /*[out,retval]*/ VARIANT* pRetVal);
	STDMETHOD(GetLocalResourceObject)(/*[in]*/ VARIANT resourceKey, /*[out, retval]*/ VARIANT* pRetVal);
	STDMETHOD(GetCulturedLocalResourceObject)(/*[in]*/ VARIANT resourceKey, /*[in]*/ VARIANT culture, /*[out,retval]*/ VARIANT* pRetVal);


private:
	STDMETHOD(EnsureContext)();
		
//
////	ASP intrinsic objects
//    CComPtr<IRequest>           m_piRequest;
//    CComPtr<IResponse>          m_piResponse;
//    CComPtr<IApplicationObject> m_piApplication;
//    CComPtr<ISessionObject>     m_piSession;
//    CComPtr<IServer>            m_piServer;
//	
//	CComPtr<IObjectContext>		m_piContext;
//	CComPtr<IResourceAccessor>	m_piProvider;
};

OBJECT_ENTRY_AUTO(__uuidof(ResourceAccessor), CResourceAccessor)
