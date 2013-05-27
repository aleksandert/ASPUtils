// HashMap.h : Declaration of the CHashMap

#pragma once
#ifndef _HASHMAP_H_
#define _HASHMAP_H_

#include "resource.h"       // main symbols

#include "ASPUtils_i.h"
#include "atlcoll.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CHashMap

class ATL_NO_VTABLE CHashMap :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHashMap, &CLSID_HashMap>,
	public ISupportErrorInfo,
	public IDispatchImpl<IHashMap, &IID_IHashMap, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
	typedef CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > CComEnumVariant;

public:
	CHashMap()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HASHMAP)


BEGIN_COM_MAP(CHashMap)
	COM_INTERFACE_ENTRY(IHashMap)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


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

	STDMETHOD(putref_Item)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT value);
	STDMETHOD(put_Item)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT value);
	STDMETHOD(get_Item)(/*[in]*/ VARIANT key, /*[out, retval]*/ VARIANT* pItem);
	STDMETHOD(Set)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT value);
	STDMETHOD(get_Count)(/*[out, retval]*/ long* pCount);
	STDMETHOD(Exists)(/*[in]*/ VARIANT key, /*[out, retval]*/ VARIANT_BOOL* pExists);
	STDMETHOD(Keys)(/*[out, retval]*/ VARIANT* pKeysArray);
	STDMETHOD(Remove)(/*[in]*/ VARIANT key);
	STDMETHOD(RemoveAll)();
	STDMETHOD(_NewEnum)(/*[out, retval]*/ IUnknown** ppunk);

private:

//	CComAutoCriticalSection m_CriticalSection;

	CAtlMap<CComBSTR, CComVariant> m_Items;
		
	STDMETHOD(Initialize)();
	STDMETHOD(Terminate)();

	STDMETHOD(Put)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT item);

};

OBJECT_ENTRY_AUTO(__uuidof(HashMap), CHashMap)
#endif // !_HASHMAP_H_