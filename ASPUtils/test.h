// test.h : Declaration of the Ctest

#pragma once

#include "resource.h"       // main symbols
#include <asptlb.h>         // Active Server Pages Definitions

#include "ASPUtils_i.h"

using namespace ATL;



// Ctest

class ATL_NO_VTABLE Ctest :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<Ctest, &CLSID_test>,
	public IDispatchImpl<Itest, &IID_Itest, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	Ctest()
	{
		m_bOnStartPageCalled = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TEST)


BEGIN_COM_MAP(Ctest)
	COM_INTERFACE_ENTRY(Itest)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

// Itest
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

OBJECT_ENTRY_AUTO(__uuidof(test), Ctest)
