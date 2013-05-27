// MemcachedSessionStore.h : Declaration of the CMemcachedSessionStore

#pragma once
#ifndef _MEMCACHEDSESSIONSTORE_H_
#define _MEMCACHEDSESSIONSTORE_H_

#include "resource.h"       // main symbols
#include "SessionStore.h"
#include <memory>
#include <vector>
#include <comutil.h>
#include <time.h>

//#define LIBMEMCACHED_STATIC
//

#include "libmemcached\memcached.hpp"

#include "ASPUtils_i.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;
using namespace std;
//
//struct ItemHeader
//{
//	uint64_t	m_LockId;
//	time_t		m_LockTime;
//	long		m_Timeout;
//	uint64_t	m_HeadCas;
//	uint64_t	m_DataCas;
//};

CComAutoCriticalSection m_Memcached_Lock;

typedef CComCritSecLock<CComAutoCriticalSection> LockType;

// CMemcachedSessionStore

class ATL_NO_VTABLE CMemcachedSessionStore :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CMemcachedSessionStore, &CLSID_MemcachedSessionStore>,
	public ISupportErrorInfo,
	public IDispatchImpl<IMemcachedSessionStore, &IID_IMemcachedSessionStore, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CMemcachedSessionStore()
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MEMCACHEDSESSIONSTORE)


BEGIN_COM_MAP(CMemcachedSessionStore)
	COM_INTERFACE_ENTRY(IMemcachedSessionStore)
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

	memcached_st* m_memc;

	
	
	
public:

	STDMETHOD(Initialize)();

	STDMETHOD(Terminate)();

	STDMETHOD(GetItem)(
		/*[in]*/ BSTR bstrKey, 
		/*[in]*/ ExclusiveMode lExclusiveMode,
		/*[in]*/ IStream* pStream,
		/*[out]*/ void** lLockId, 
		/*[out]*/ long* lLockAge,
		/*[out]*/ VARIANT_BOOL* lLocked);
	
	STDMETHOD(SetItem)(
		/*[in]*/ BSTR bstrKey,
		/*[in]*/ long lTimeout,
		/*[in]*/ void* lLockId,
		/*[in]*/ IStream* pStream);
	
	STDMETHOD(ReleaseItemExclusive)(
		/*[in]*/ BSTR bstrKey, 
		/*[in]*/ void* lockId);
	
	STDMETHOD(RemoveItem)(
		/*[in]*/ BSTR bstrKey,
		/*[in]*/ void* lLockId);

	STDMETHOD(ResetItemTimeout)(
		/*[in]*/ BSTR bstrKey);

};

OBJECT_ENTRY_AUTO(__uuidof(MemcachedSessionStore), CMemcachedSessionStore)

#endif // !_MEMCACHEDSESSIONSTORE_H_