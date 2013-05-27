// Cache.h : Declaration of the CCache

#pragma once
#ifndef _CACHE_H_
#define _CACHE_H_

#include "resource.h"       // main symbols

#include "ASPUtils_i.h"
#include "atlcoll.h"

#include <perflib.h>
#include <winperf.h>
#include "perf.h"

using namespace ATL;

CComAutoCriticalSection m_CriticalSection;

PPERF_COUNTERSET_INSTANCE m_PerfCounterSet;

enum CacheExpiration { None, Sliding, Absolute };

struct CacheCounterValues
{
	int Entries;
	int Hits;
	int Misses;
	float HitRatio;
};

CacheCounterValues m_PerfCounterValues;

struct CachePolicy
{
	CacheExpiration	Type;
	CTime AbsoluteExpiration;
	CTimeSpan SlidingExpiration;
};

struct CacheEntry
{
	int m_hash;
	
	CachePolicy Policy;
	POSITION Position;
	CComVariant Item;

	CacheEntry()
	{
		m_hash = rand();

		ATLTRACE2(atlTraceGeneral, 4, "Entry created @ %d\n", m_hash);
	}
	~CacheEntry()
	{
		ATLTRACE2(atlTraceGeneral, 4, "Entry deleted @ %d\n", m_hash);
	}


};

struct CacheStorage
{
	CAtlMap<CComBSTR, CacheEntry>* Items;
	CRBMultiMap<long, CComBSTR>* Timers;
};


// CCache
/// <summary>
/// Implements the cache for a application.
/// </summary>
class ATL_NO_VTABLE CCache :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CCache, &CLSID_Cache>,
	public ISupportErrorInfo,
	public IDispatchImpl<ICache, &IID_ICache, &LIBID_ASPUtilsLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
	typedef CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > CComEnumVariant;

public:
	CCache()
	{
		m_pUnkMarshaler = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CACHE)


BEGIN_COM_MAP(CCache)
	COM_INTERFACE_ENTRY(ICache)
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

// ICache
public:
	STDMETHOD(putref_Item)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT value);
	STDMETHOD(put_Item)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT value);
	STDMETHOD(get_Item)(/*[in]*/ VARIANT key, /*[out, retval]*/ VARIANT* pItem);
	STDMETHOD(Set)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT value);
	STDMETHOD(SetSliding)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT value, /*[in]*/ VARIANT slidingExpiration);
	STDMETHOD(SetAbsolute)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT value, /*[in]*/ VARIANT absoluteExpiration);
	STDMETHOD(get_Count)(/*[out, retval]*/ long* pCount);
	STDMETHOD(Exists)(/*[in]*/ VARIANT key, /*[out, retval]*/ VARIANT_BOOL* pExists);
	STDMETHOD(Keys)(/*[out, retval]*/ VARIANT* pKeysArray);
	STDMETHOD(Remove)(/*[in]*/ VARIANT key);
	STDMETHOD(RemoveAll)();
	STDMETHOD(_NewEnum)(/*[out, retval]*/ IUnknown** ppunk);
	STDMETHOD(Expires)(/*[in]*/ VARIANT key, /*[out, retval]*/ VARIANT* pExpires);
	STDMETHOD(GetSize)(/*[in]*/ VARIANT key, /*[out, retval]*/ long* pSize);
	
private:
	HANDLE hTimer;

	CAtlMap<CComBSTR, CacheEntry> m_cachedItems;
	CRBMultiMap<long, CComBSTR> m_cacheTimers;
	CacheStorage m_cacheStorage;
	
	STDMETHOD(Initialize)();
	STDMETHOD(Terminate)();

	STDMETHOD(Put)(/*[in]*/ VARIANT key, /*[in]*/ VARIANT item, CachePolicy policy);
};


OBJECT_ENTRY_AUTO(__uuidof(Cache), CCache)
#endif	// !_CACHE_H_