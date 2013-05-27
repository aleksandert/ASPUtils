// VariantDictionary.h : Declaration of the CVariantDictionary

#pragma once
#ifndef _VARIANTDICTIONARY_H_
#define _VARIANTDICTIONARY_H_

#include <map>
#include "resource.h"       // main symbols
#include "ASPUtils_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

#include "VariantDictionaryDef.h"

namespace VariantDictionaryDef
{
	class _CopyMapKeyToVariant
	{
	public:
		static HRESULT copy(VARIANT* p2, const ItemType *p1)
		{
			return VariantCopy(p2, &p1->second);
		}
		static void init(VARIANT* p) {VariantInit(p);}
		static void destroy(VARIANT* p) {VariantClear(p);}
	};

	typedef CComEnumOnSTL< EnumeratorInterface, &__uuidof(EnumeratorInterface), ExposedType,
							_CopyMapKeyToVariant, ContainerType > EnumeratorType;

	typedef ICollectionOnSTLImpl< CollectionInterface, ContainerType, ExposedType,
							_CopyMapKeyToVariant, EnumeratorType > CollectionType;

}

#include "VariantDictionaryPersist.h"
//
using namespace VariantDictionaryDef;

// CVariantDictionary

class ATL_NO_VTABLE CVariantDictionary :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CVariantDictionary, &CLSID_VariantDictionary>,
	public ISupportErrorInfo,
	public IDispatchImpl<CollectionType, &IID_IVariantDictionary, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IPersistStreamInitImpl<CVariantDictionary>
{
public:
	CVariantDictionary()
	{
		m_pUnkMarshaler = NULL;
		m_bRequiresSave = FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_VARIANTDICTIONARY)

DECLARE_NOT_AGGREGATABLE(CVariantDictionary)

BEGIN_COM_MAP(CVariantDictionary)
	COM_INTERFACE_ENTRY(IVariantDictionary)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY_IID(IID_IPersistStream, IPersistStreamInit) 
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
END_COM_MAP()

/*
BEGIN_COM_MAP(CMap)
	COM_INTERFACE_ENTRY(IATLExtCollection)
	COM_INTERFACE_ENTRY(IATLExtMap)
	COM_INTERFACE_ENTRY(IATLExtMapEn)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IMarshal)
END_COM_MAP()
*/

BEGIN_PROP_MAP(CVariantDictionary)

END_PROP_MAP()




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
	
	BOOL m_bRequiresSave;

	STDMETHOD(Lookup)(VARIANT VarKey, ContainerType::value_type* pair);

public:

	STDMETHOD(get_Item)(/* [in] */ VARIANT VarKey, /* [retval][out] */ VARIANT *pvar);
	STDMETHOD(put_Item)(/* [in] */ VARIANT VarKey, /* [in] */ VARIANT var);
	STDMETHOD(putref_Item)(/* [in] */ VARIANT VarKey, /* [in] */ VARIANT var);
	STDMETHOD(get_Key)(/* [in] */ VARIANT VarKey, /* [retval][out] */ VARIANT *pvar);
	STDMETHOD(get_Count)(/* [retval][out] */ int *cStrRet);
	STDMETHOD(get__NewEnum)(/* [retval][out] */ IUnknown **ppEnumReturn);
	STDMETHOD(Remove)(/* [in] */ VARIANT VarKey);
	STDMETHOD(RemoveAll)();

	HRESULT IPersistStreamInit_Load(LPSTREAM pStm, const ATL_PROPMAP_ENTRY* pMap);
	HRESULT IPersistStreamInit_Save(LPSTREAM pStm, BOOL fClearDirty, const ATL_PROPMAP_ENTRY* pMap);
	
	STDMETHOD(GetSizeMax)(ULARGE_INTEGER* pcbSize);
};

OBJECT_ENTRY_AUTO(__uuidof(VariantDictionary), CVariantDictionary)
#endif // !_VARIANTDICTIONARY_H_