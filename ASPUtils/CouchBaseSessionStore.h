// CouchBaseSessionStore.h : Declaration of the CCouchBaseSessionStore

#pragma once
#include "resource.h"       // main symbols
#include <memory>
#include <vector>
#include <libcouchbase\couchbase.h>


#include "ASPUtils_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;
using namespace std;

struct StoreItem
{
public:
	long				m_LockId;
	VARIANT_BOOL		m_Locked;
	time_t				m_LockTime;
	long				m_Timeout;
	ULONG				m_DataSize; 
	vector<BYTE>		m_Data;
	lcb_error_t			m_Error;

	StoreItem()
	{
		m_LockId = 0;
		m_Locked = VARIANT_FALSE;
		m_LockTime = 0;
		m_Timeout = 0;
		m_DataSize = 0;
		m_Error = LCB_SUCCESS;
	}

	~StoreItem()
	{
		m_Data.clear();
	}
};

// CCouchBaseSessionStore

class ATL_NO_VTABLE CCouchBaseSessionStore :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCouchBaseSessionStore, &CLSID_CouchBaseSessionStore>,
	public ISupportErrorInfo,
	public IDispatchImpl<ICouchBaseSessionStore, &IID_ICouchBaseSessionStore, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CCouchBaseSessionStore()
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_COUCHBASESESSIONSTORE)


BEGIN_COM_MAP(CCouchBaseSessionStore)
	COM_INTERFACE_ENTRY(ICouchBaseSessionStore)
	COM_INTERFACE_ENTRY(IASPSessionStoreProvider)
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

	lcb_t m_lcb_instance;

public:

	STDMETHOD(Initialize)();

	STDMETHOD(Terminate)();

	STDMETHOD(GetItem)(
		/*[in]*/ BSTR bstrKey, 
		/*[in]*/ ExclusiveMode lExclusiveMode,
		/*[in]*/ IStream* pStream,
		/*[out]*/ long* lLockId, 
		/*[out]*/ long* lLockAge,
		/*[out]*/ VARIANT_BOOL* lLocked);
	
	STDMETHOD(SetItem)(
		/*[in]*/ BSTR bstrKey,
		/*[in]*/ long lTimeout,
		/*[in]*/ long lLockId,
		/*[in]*/ IStream* pStream);
	
	STDMETHOD(ReleaseItemExclusive)(
		/*[in]*/ BSTR bstrKey, 
		/*[in]*/ LONG lockId);
	
	STDMETHOD(RemoveItem)(
		/*[in]*/ BSTR bstrKey,
		/*[in]*/ LONG lLockId);

	STDMETHOD(ResetItemTimeout)(
		/*[in]*/ BSTR bstrKey);

};

OBJECT_ENTRY_AUTO(__uuidof(CouchBaseSessionStore), CCouchBaseSessionStore)
