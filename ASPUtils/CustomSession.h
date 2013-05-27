// CustomSession.h : Declaration of the CCustomSession

#pragma once
#ifndef _CUSTOMSESSION_H_
#define _CUSTOMSESSION_H_

#include "resource.h"       // main symbols
#include <memory>
#include "atlcoll.h"
#include "Context.h"


#include "ASPUtils_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;
using namespace std;


// CCustomSession

class ATL_NO_VTABLE CCustomSession :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCustomSession, &CLSID_CustomSession>,
	public ISupportErrorInfo,
	public IPersistStreamInitImpl<CCustomSession>,
	public IDispatchImpl<ICustomSession, &IID_ICustomSession, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCustomSession()
	{
		m_pUnkMarshaler = NULL;
		m_bRequiresSave = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CUSTOMSESSION)


BEGIN_COM_MAP(CCustomSession)
	COM_INTERFACE_ENTRY(ICustomSession)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY_IID(IID_IPersistStream, IPersistStreamInit) 
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

BEGIN_PROP_MAP(CCustomSession)
	PROP_DATA_ENTRY("CodePage", m_CodePage, VT_I4)
	PROP_DATA_ENTRY("LCID", m_LCID, VT_I4)
	PROP_DATA_ENTRY("Timeout", m_Timeout, VT_I4)
END_PROP_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct()
	{
		Initialize();

		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		Terminate();

		m_pUnkMarshaler.Release();
	}

	CComPtr<IUnknown> m_pUnkMarshaler;
	
	BOOL m_bRequiresSave;
	
public:
	
	STDMETHOD(Init)(ISessionObject* pSession);
	STDMETHOD(get_Value)(/*[in]*/BSTR bstrValue, /*[out]*/ VARIANT* pvar);
	STDMETHOD(put_Value)(/*[in]*/BSTR bstrValue,  /*[in]*/ VARIANT pvar);
	STDMETHOD(putref_Value)(/*[in]*/ BSTR bstrValue,  /*[in]*/ VARIANT pvar);
	STDMETHOD(get_SessionID)(/*[out]*/ BSTR* pbstrRet);
	STDMETHOD(get_Timeout)(/*[out, retval]*/ long *plvar);
	STDMETHOD(put_Timeout)(/*[in]*/ long lvar);
	STDMETHOD(Abandon)();
	STDMETHOD(get_CodePage)(/*[out, retval]*/ long *plvar);
	STDMETHOD(put_CodePage)(/*[in]*/ long lvar);
	STDMETHOD(get_LCID)(/*[out, retval]*/ long *plvar);
	STDMETHOD(put_LCID)(/*[in]*/ long lvar);
	STDMETHOD(get_StaticObjects)(/*[out, retval]*/ IVariantDictionary **ppTaggedObjects);
	STDMETHOD(get_Contents)(/*[out, retval]*/ IVariantDictionary **ppProperties);

	HRESULT IPersistStreamInit_Load(LPSTREAM pStm, const ATL_PROPMAP_ENTRY* pMap);
	HRESULT IPersistStreamInit_Save(LPSTREAM pStm, BOOL fClearDirty, const ATL_PROPMAP_ENTRY* pMap);
	

private: 

	
	
	long m_CodePage;
	long m_LCID;
	CComBSTR m_SessionID;
	long m_Timeout;
	CComPtr<IVariantDictionary> m_piStaticObjects;
	CComPtr<IVariantDictionary> m_piContents;

	STDMETHOD(Initialize)();
	STDMETHOD(Terminate)();

};

OBJECT_ENTRY_AUTO(__uuidof(CustomSession), CCustomSession)
#endif // !_CUSTOMSESSION_H_ 