// ScriptParser.h : Declaration of the CScriptParser

#pragma once
#include "resource.h"       // main symbols



#include "ASPUtils_i.h"
#include "asptlb.h"
#include "ASPObjects.h"
#import "C:\Windows\System32\msscript.ocx"  // msscript.ocx


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CScriptParser

class ATL_NO_VTABLE CScriptParser :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CScriptParser, &CLSID_ScriptParser>,
	public IDispatchImpl<IScriptParser, &IID_IScriptParser, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CScriptParser()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SCRIPTPARSER)


BEGIN_COM_MAP(CScriptParser)
	COM_INTERFACE_ENTRY(IScriptParser)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		Initialize();

		return S_OK;
	}

	void FinalRelease()
	{
		Terminate();
	}

public:
	STDMETHOD(ParseScript)(/*[in]*/ VARIANT script, /*[out, retval]*/ VARIANT* pResult);
	STDMETHOD(ParseFile)(/*[in]*/ VARIANT path, /*[out, retval]*/ VARIANT* pResult);

private:
	STDMETHOD(Initialize)();
	STDMETHOD(Terminate)();
	MSScriptControl::IScriptControlPtr m_piScriptControl;
};

OBJECT_ENTRY_AUTO(__uuidof(ScriptParser), CScriptParser)
