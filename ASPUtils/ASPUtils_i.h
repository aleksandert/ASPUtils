

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0595 */
/* at Sun May 26 11:19:09 2013
 */
/* Compiler settings for ASPUtils.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0595 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ASPUtils_i_h__
#define __ASPUtils_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICache_FWD_DEFINED__
#define __ICache_FWD_DEFINED__
typedef interface ICache ICache;

#endif 	/* __ICache_FWD_DEFINED__ */


#ifndef __IHashMap_FWD_DEFINED__
#define __IHashMap_FWD_DEFINED__
typedef interface IHashMap IHashMap;

#endif 	/* __IHashMap_FWD_DEFINED__ */


#ifndef __IASPSessionStoreProvider_FWD_DEFINED__
#define __IASPSessionStoreProvider_FWD_DEFINED__
typedef interface IASPSessionStoreProvider IASPSessionStoreProvider;

#endif 	/* __IASPSessionStoreProvider_FWD_DEFINED__ */


#ifndef __ICustomSession_FWD_DEFINED__
#define __ICustomSession_FWD_DEFINED__
typedef interface ICustomSession ICustomSession;

#endif 	/* __ICustomSession_FWD_DEFINED__ */


#ifndef __ISessionManager_FWD_DEFINED__
#define __ISessionManager_FWD_DEFINED__
typedef interface ISessionManager ISessionManager;

#endif 	/* __ISessionManager_FWD_DEFINED__ */


#ifndef __IPageHandler_FWD_DEFINED__
#define __IPageHandler_FWD_DEFINED__
typedef interface IPageHandler IPageHandler;

#endif 	/* __IPageHandler_FWD_DEFINED__ */


#ifndef __IInProcSessionStore_FWD_DEFINED__
#define __IInProcSessionStore_FWD_DEFINED__
typedef interface IInProcSessionStore IInProcSessionStore;

#endif 	/* __IInProcSessionStore_FWD_DEFINED__ */


#ifndef __ICouchBaseSessionStore_FWD_DEFINED__
#define __ICouchBaseSessionStore_FWD_DEFINED__
typedef interface ICouchBaseSessionStore ICouchBaseSessionStore;

#endif 	/* __ICouchBaseSessionStore_FWD_DEFINED__ */


#ifndef __IMemcachedSessionStore_FWD_DEFINED__
#define __IMemcachedSessionStore_FWD_DEFINED__
typedef interface IMemcachedSessionStore IMemcachedSessionStore;

#endif 	/* __IMemcachedSessionStore_FWD_DEFINED__ */


#ifndef __IASPSampleObject_FWD_DEFINED__
#define __IASPSampleObject_FWD_DEFINED__
typedef interface IASPSampleObject IASPSampleObject;

#endif 	/* __IASPSampleObject_FWD_DEFINED__ */


#ifndef __Cache_FWD_DEFINED__
#define __Cache_FWD_DEFINED__

#ifdef __cplusplus
typedef class Cache Cache;
#else
typedef struct Cache Cache;
#endif /* __cplusplus */

#endif 	/* __Cache_FWD_DEFINED__ */


#ifndef __HashMap_FWD_DEFINED__
#define __HashMap_FWD_DEFINED__

#ifdef __cplusplus
typedef class HashMap HashMap;
#else
typedef struct HashMap HashMap;
#endif /* __cplusplus */

#endif 	/* __HashMap_FWD_DEFINED__ */


#ifndef __PageHandler_FWD_DEFINED__
#define __PageHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class PageHandler PageHandler;
#else
typedef struct PageHandler PageHandler;
#endif /* __cplusplus */

#endif 	/* __PageHandler_FWD_DEFINED__ */


#ifndef __CustomSession_FWD_DEFINED__
#define __CustomSession_FWD_DEFINED__

#ifdef __cplusplus
typedef class CustomSession CustomSession;
#else
typedef struct CustomSession CustomSession;
#endif /* __cplusplus */

#endif 	/* __CustomSession_FWD_DEFINED__ */


#ifndef __SessionManager_FWD_DEFINED__
#define __SessionManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class SessionManager SessionManager;
#else
typedef struct SessionManager SessionManager;
#endif /* __cplusplus */

#endif 	/* __SessionManager_FWD_DEFINED__ */


#ifndef __VariantDictionary_FWD_DEFINED__
#define __VariantDictionary_FWD_DEFINED__

#ifdef __cplusplus
typedef class VariantDictionary VariantDictionary;
#else
typedef struct VariantDictionary VariantDictionary;
#endif /* __cplusplus */

#endif 	/* __VariantDictionary_FWD_DEFINED__ */


#ifndef __InProcSessionStore_FWD_DEFINED__
#define __InProcSessionStore_FWD_DEFINED__

#ifdef __cplusplus
typedef class InProcSessionStore InProcSessionStore;
#else
typedef struct InProcSessionStore InProcSessionStore;
#endif /* __cplusplus */

#endif 	/* __InProcSessionStore_FWD_DEFINED__ */


#ifndef __CouchBaseSessionStore_FWD_DEFINED__
#define __CouchBaseSessionStore_FWD_DEFINED__

#ifdef __cplusplus
typedef class CouchBaseSessionStore CouchBaseSessionStore;
#else
typedef struct CouchBaseSessionStore CouchBaseSessionStore;
#endif /* __cplusplus */

#endif 	/* __CouchBaseSessionStore_FWD_DEFINED__ */


#ifndef __MemcachedSessionStore_FWD_DEFINED__
#define __MemcachedSessionStore_FWD_DEFINED__

#ifdef __cplusplus
typedef class MemcachedSessionStore MemcachedSessionStore;
#else
typedef struct MemcachedSessionStore MemcachedSessionStore;
#endif /* __cplusplus */

#endif 	/* __MemcachedSessionStore_FWD_DEFINED__ */


#ifndef __ASPSampleObject_FWD_DEFINED__
#define __ASPSampleObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class ASPSampleObject ASPSampleObject;
#else
typedef struct ASPSampleObject ASPSampleObject;
#endif /* __cplusplus */

#endif 	/* __ASPSampleObject_FWD_DEFINED__ */


/* header files for imported files */
#include "asptlb.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICache_INTERFACE_DEFINED__
#define __ICache_INTERFACE_DEFINED__

/* interface ICache */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICache;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8DDF5AE5-1782-4DF1-BDAC-CEF5733AA0BA")
    ICache : public IDispatch
    {
    public:
        virtual /* [helpstring][propputref][id] */ HRESULT STDMETHODCALLTYPE putref_Item( 
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Item( 
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetSliding( 
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value,
            /* [in] */ VARIANT slidingExpiration) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAbsolute( 
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value,
            /* [in] */ VARIANT absoluteExpiration) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exists( 
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT_BOOL *pExists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Keys( 
            /* [retval][out] */ VARIANT *pKeysArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT key) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Expires( 
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT *pExpires) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSize( 
            /* [in] */ VARIANT key,
            /* [retval][out] */ long *pSize) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IUnknown **ppunk) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICacheVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICache * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICache * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICache * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICache * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICache * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICache * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICache * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propputref][id] */ HRESULT ( STDMETHODCALLTYPE *putref_Item )( 
            ICache * This,
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Item )( 
            ICache * This,
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            ICache * This,
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Set )( 
            ICache * This,
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetSliding )( 
            ICache * This,
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value,
            /* [in] */ VARIANT slidingExpiration);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetAbsolute )( 
            ICache * This,
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value,
            /* [in] */ VARIANT absoluteExpiration);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            ICache * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exists )( 
            ICache * This,
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT_BOOL *pExists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Keys )( 
            ICache * This,
            /* [retval][out] */ VARIANT *pKeysArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ICache * This,
            /* [in] */ VARIANT key);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAll )( 
            ICache * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Expires )( 
            ICache * This,
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT *pExpires);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            ICache * This,
            /* [in] */ VARIANT key,
            /* [retval][out] */ long *pSize);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *_NewEnum )( 
            ICache * This,
            /* [retval][out] */ IUnknown **ppunk);
        
        END_INTERFACE
    } ICacheVtbl;

    interface ICache
    {
        CONST_VTBL struct ICacheVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICache_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICache_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICache_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICache_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICache_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICache_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICache_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICache_putref_Item(This,key,value)	\
    ( (This)->lpVtbl -> putref_Item(This,key,value) ) 

#define ICache_put_Item(This,key,value)	\
    ( (This)->lpVtbl -> put_Item(This,key,value) ) 

#define ICache_get_Item(This,key,value)	\
    ( (This)->lpVtbl -> get_Item(This,key,value) ) 

#define ICache_Set(This,key,value)	\
    ( (This)->lpVtbl -> Set(This,key,value) ) 

#define ICache_SetSliding(This,key,value,slidingExpiration)	\
    ( (This)->lpVtbl -> SetSliding(This,key,value,slidingExpiration) ) 

#define ICache_SetAbsolute(This,key,value,absoluteExpiration)	\
    ( (This)->lpVtbl -> SetAbsolute(This,key,value,absoluteExpiration) ) 

#define ICache_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define ICache_Exists(This,key,pExists)	\
    ( (This)->lpVtbl -> Exists(This,key,pExists) ) 

#define ICache_Keys(This,pKeysArray)	\
    ( (This)->lpVtbl -> Keys(This,pKeysArray) ) 

#define ICache_Remove(This,key)	\
    ( (This)->lpVtbl -> Remove(This,key) ) 

#define ICache_RemoveAll(This)	\
    ( (This)->lpVtbl -> RemoveAll(This) ) 

#define ICache_Expires(This,key,pExpires)	\
    ( (This)->lpVtbl -> Expires(This,key,pExpires) ) 

#define ICache_GetSize(This,key,pSize)	\
    ( (This)->lpVtbl -> GetSize(This,key,pSize) ) 

#define ICache__NewEnum(This,ppunk)	\
    ( (This)->lpVtbl -> _NewEnum(This,ppunk) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICache_INTERFACE_DEFINED__ */


#ifndef __IHashMap_INTERFACE_DEFINED__
#define __IHashMap_INTERFACE_DEFINED__

/* interface IHashMap */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IHashMap;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D2D624A5-E745-4203-82B8-A9401B8B28C0")
    IHashMap : public IDispatch
    {
    public:
        virtual /* [helpstring][propputref][id] */ HRESULT STDMETHODCALLTYPE putref_Item( 
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Item( 
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Set( 
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pCount) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Exists( 
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT_BOOL *pExists) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Keys( 
            /* [retval][out] */ VARIANT *pKeysArray) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ VARIANT key) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE _NewEnum( 
            /* [retval][out] */ IUnknown **ppunk) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHashMapVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHashMap * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHashMap * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHashMap * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHashMap * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHashMap * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHashMap * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHashMap * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propputref][id] */ HRESULT ( STDMETHODCALLTYPE *putref_Item )( 
            IHashMap * This,
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Item )( 
            IHashMap * This,
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IHashMap * This,
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Set )( 
            IHashMap * This,
            /* [in] */ VARIANT key,
            /* [in] */ VARIANT value);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IHashMap * This,
            /* [retval][out] */ long *pCount);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Exists )( 
            IHashMap * This,
            /* [in] */ VARIANT key,
            /* [retval][out] */ VARIANT_BOOL *pExists);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Keys )( 
            IHashMap * This,
            /* [retval][out] */ VARIANT *pKeysArray);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IHashMap * This,
            /* [in] */ VARIANT key);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RemoveAll )( 
            IHashMap * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *_NewEnum )( 
            IHashMap * This,
            /* [retval][out] */ IUnknown **ppunk);
        
        END_INTERFACE
    } IHashMapVtbl;

    interface IHashMap
    {
        CONST_VTBL struct IHashMapVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHashMap_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHashMap_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHashMap_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHashMap_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHashMap_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHashMap_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHashMap_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHashMap_putref_Item(This,key,value)	\
    ( (This)->lpVtbl -> putref_Item(This,key,value) ) 

#define IHashMap_put_Item(This,key,value)	\
    ( (This)->lpVtbl -> put_Item(This,key,value) ) 

#define IHashMap_get_Item(This,key,value)	\
    ( (This)->lpVtbl -> get_Item(This,key,value) ) 

#define IHashMap_Set(This,key,value)	\
    ( (This)->lpVtbl -> Set(This,key,value) ) 

#define IHashMap_get_Count(This,pCount)	\
    ( (This)->lpVtbl -> get_Count(This,pCount) ) 

#define IHashMap_Exists(This,key,pExists)	\
    ( (This)->lpVtbl -> Exists(This,key,pExists) ) 

#define IHashMap_Keys(This,pKeysArray)	\
    ( (This)->lpVtbl -> Keys(This,pKeysArray) ) 

#define IHashMap_Remove(This,key)	\
    ( (This)->lpVtbl -> Remove(This,key) ) 

#define IHashMap_RemoveAll(This)	\
    ( (This)->lpVtbl -> RemoveAll(This) ) 

#define IHashMap__NewEnum(This,ppunk)	\
    ( (This)->lpVtbl -> _NewEnum(This,ppunk) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHashMap_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_ASPUtils_0000_0002 */
/* [local] */ 

typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ASPUtils_0000_0002_0001
    {
        EXC_MODE_NONE	= 0,
        EXC_MODE_ACQUIRE	= ( EXC_MODE_NONE + 1 ) ,
        EXC_MODE_RELEASE	= ( EXC_MODE_ACQUIRE + 1 ) 
    } 	ExclusiveMode;



extern RPC_IF_HANDLE __MIDL_itf_ASPUtils_0000_0002_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ASPUtils_0000_0002_v0_0_s_ifspec;

#ifndef __IASPSessionStoreProvider_INTERFACE_DEFINED__
#define __IASPSessionStoreProvider_INTERFACE_DEFINED__

/* interface IASPSessionStoreProvider */
/* [local][unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IASPSessionStoreProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("94503E88-964C-45A9-B492-631B31402CEB")
    IASPSessionStoreProvider : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Terminate( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetItem( 
            /* [in] */ BSTR bstrKey,
            /* [in] */ ExclusiveMode lExclusiveMode,
            /* [in] */ IStream *pStream,
            /* [out] */ void **lLockId,
            /* [out] */ long *lLockAge,
            /* [out] */ VARIANT_BOOL *lLocked) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetItem( 
            /* [in] */ BSTR bstrKey,
            /* [in] */ long lTimeout,
            /* [in] */ void *lLockId,
            /* [in] */ IStream *pStream) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReleaseItemExclusive( 
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lockId) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RemoveItem( 
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lLockId) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ResetItemTimeout( 
            /* [in] */ BSTR bstrKey) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IASPSessionStoreProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IASPSessionStoreProvider * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IASPSessionStoreProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IASPSessionStoreProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IASPSessionStoreProvider * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IASPSessionStoreProvider * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IASPSessionStoreProvider * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IASPSessionStoreProvider * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IASPSessionStoreProvider * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            IASPSessionStoreProvider * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IASPSessionStoreProvider * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ ExclusiveMode lExclusiveMode,
            /* [in] */ IStream *pStream,
            /* [out] */ void **lLockId,
            /* [out] */ long *lLockAge,
            /* [out] */ VARIANT_BOOL *lLocked);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItem )( 
            IASPSessionStoreProvider * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ long lTimeout,
            /* [in] */ void *lLockId,
            /* [in] */ IStream *pStream);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseItemExclusive )( 
            IASPSessionStoreProvider * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lockId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RemoveItem )( 
            IASPSessionStoreProvider * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lLockId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetItemTimeout )( 
            IASPSessionStoreProvider * This,
            /* [in] */ BSTR bstrKey);
        
        END_INTERFACE
    } IASPSessionStoreProviderVtbl;

    interface IASPSessionStoreProvider
    {
        CONST_VTBL struct IASPSessionStoreProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IASPSessionStoreProvider_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IASPSessionStoreProvider_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IASPSessionStoreProvider_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IASPSessionStoreProvider_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IASPSessionStoreProvider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IASPSessionStoreProvider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IASPSessionStoreProvider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IASPSessionStoreProvider_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#define IASPSessionStoreProvider_Terminate(This)	\
    ( (This)->lpVtbl -> Terminate(This) ) 

#define IASPSessionStoreProvider_GetItem(This,bstrKey,lExclusiveMode,pStream,lLockId,lLockAge,lLocked)	\
    ( (This)->lpVtbl -> GetItem(This,bstrKey,lExclusiveMode,pStream,lLockId,lLockAge,lLocked) ) 

#define IASPSessionStoreProvider_SetItem(This,bstrKey,lTimeout,lLockId,pStream)	\
    ( (This)->lpVtbl -> SetItem(This,bstrKey,lTimeout,lLockId,pStream) ) 

#define IASPSessionStoreProvider_ReleaseItemExclusive(This,bstrKey,lockId)	\
    ( (This)->lpVtbl -> ReleaseItemExclusive(This,bstrKey,lockId) ) 

#define IASPSessionStoreProvider_RemoveItem(This,bstrKey,lLockId)	\
    ( (This)->lpVtbl -> RemoveItem(This,bstrKey,lLockId) ) 

#define IASPSessionStoreProvider_ResetItemTimeout(This,bstrKey)	\
    ( (This)->lpVtbl -> ResetItemTimeout(This,bstrKey) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IASPSessionStoreProvider_INTERFACE_DEFINED__ */


#ifndef __ICustomSession_INTERFACE_DEFINED__
#define __ICustomSession_INTERFACE_DEFINED__

/* interface ICustomSession */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICustomSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C3E704FD-0C00-45A1-A5A4-D264A8807E7D")
    ICustomSession : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [in] */ BSTR bstrValue,
            /* [retval][out] */ VARIANT *pvar) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ BSTR bstrValue,
            /* [in] */ VARIANT pvar) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_Value( 
            /* [in] */ BSTR bstrValue,
            /* [in] */ VARIANT pvar) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ ISessionObject *pSession) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SessionID( 
            /* [retval][out] */ BSTR *pbstrRet) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Timeout( 
            /* [retval][out] */ long *plvar) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Timeout( 
            /* [in] */ long lvar) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Abandon( void) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CodePage( 
            /* [retval][out] */ long *plvar) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CodePage( 
            /* [in] */ long lvar) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_LCID( 
            /* [retval][out] */ long *plvar) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_LCID( 
            /* [in] */ long lvar) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_StaticObjects( 
            /* [retval][out] */ IVariantDictionary **ppTaggedObjects) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Contents( 
            /* [retval][out] */ IVariantDictionary **ppProperties) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICustomSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICustomSession * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICustomSession * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICustomSession * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICustomSession * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICustomSession * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICustomSession * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICustomSession * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Value )( 
            ICustomSession * This,
            /* [in] */ BSTR bstrValue,
            /* [retval][out] */ VARIANT *pvar);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Value )( 
            ICustomSession * This,
            /* [in] */ BSTR bstrValue,
            /* [in] */ VARIANT pvar);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE *putref_Value )( 
            ICustomSession * This,
            /* [in] */ BSTR bstrValue,
            /* [in] */ VARIANT pvar);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Init )( 
            ICustomSession * This,
            /* [in] */ ISessionObject *pSession);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SessionID )( 
            ICustomSession * This,
            /* [retval][out] */ BSTR *pbstrRet);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Timeout )( 
            ICustomSession * This,
            /* [retval][out] */ long *plvar);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Timeout )( 
            ICustomSession * This,
            /* [in] */ long lvar);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Abandon )( 
            ICustomSession * This);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_CodePage )( 
            ICustomSession * This,
            /* [retval][out] */ long *plvar);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_CodePage )( 
            ICustomSession * This,
            /* [in] */ long lvar);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_LCID )( 
            ICustomSession * This,
            /* [retval][out] */ long *plvar);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_LCID )( 
            ICustomSession * This,
            /* [in] */ long lvar);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_StaticObjects )( 
            ICustomSession * This,
            /* [retval][out] */ IVariantDictionary **ppTaggedObjects);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Contents )( 
            ICustomSession * This,
            /* [retval][out] */ IVariantDictionary **ppProperties);
        
        END_INTERFACE
    } ICustomSessionVtbl;

    interface ICustomSession
    {
        CONST_VTBL struct ICustomSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICustomSession_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICustomSession_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICustomSession_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICustomSession_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICustomSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICustomSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICustomSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICustomSession_get_Value(This,bstrValue,pvar)	\
    ( (This)->lpVtbl -> get_Value(This,bstrValue,pvar) ) 

#define ICustomSession_put_Value(This,bstrValue,pvar)	\
    ( (This)->lpVtbl -> put_Value(This,bstrValue,pvar) ) 

#define ICustomSession_putref_Value(This,bstrValue,pvar)	\
    ( (This)->lpVtbl -> putref_Value(This,bstrValue,pvar) ) 

#define ICustomSession_Init(This,pSession)	\
    ( (This)->lpVtbl -> Init(This,pSession) ) 

#define ICustomSession_get_SessionID(This,pbstrRet)	\
    ( (This)->lpVtbl -> get_SessionID(This,pbstrRet) ) 

#define ICustomSession_get_Timeout(This,plvar)	\
    ( (This)->lpVtbl -> get_Timeout(This,plvar) ) 

#define ICustomSession_put_Timeout(This,lvar)	\
    ( (This)->lpVtbl -> put_Timeout(This,lvar) ) 

#define ICustomSession_Abandon(This)	\
    ( (This)->lpVtbl -> Abandon(This) ) 

#define ICustomSession_get_CodePage(This,plvar)	\
    ( (This)->lpVtbl -> get_CodePage(This,plvar) ) 

#define ICustomSession_put_CodePage(This,lvar)	\
    ( (This)->lpVtbl -> put_CodePage(This,lvar) ) 

#define ICustomSession_get_LCID(This,plvar)	\
    ( (This)->lpVtbl -> get_LCID(This,plvar) ) 

#define ICustomSession_put_LCID(This,lvar)	\
    ( (This)->lpVtbl -> put_LCID(This,lvar) ) 

#define ICustomSession_get_StaticObjects(This,ppTaggedObjects)	\
    ( (This)->lpVtbl -> get_StaticObjects(This,ppTaggedObjects) ) 

#define ICustomSession_get_Contents(This,ppProperties)	\
    ( (This)->lpVtbl -> get_Contents(This,ppProperties) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICustomSession_INTERFACE_DEFINED__ */


#ifndef __ISessionManager_INTERFACE_DEFINED__
#define __ISessionManager_INTERFACE_DEFINED__

/* interface ISessionManager */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISessionManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0C52FDBD-A152-4075-B689-81E90F659236")
    ISessionManager : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Session( 
            BOOL bReadOnly,
            /* [retval][out] */ ICustomSession **ppSessionObject) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartSession( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EndSession( void) = 0;
        
        virtual /* [local][id] */ HRESULT STDMETHODCALLTYPE OnEndPage( 
            /* [in] */ BSTR bstrSessionId,
            /* [in] */ void *lLockId) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Terminate( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISessionManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISessionManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISessionManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISessionManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISessionManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISessionManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISessionManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISessionManager * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Session )( 
            ISessionManager * This,
            BOOL bReadOnly,
            /* [retval][out] */ ICustomSession **ppSessionObject);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *StartSession )( 
            ISessionManager * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *EndSession )( 
            ISessionManager * This);
        
        /* [local][id] */ HRESULT ( STDMETHODCALLTYPE *OnEndPage )( 
            ISessionManager * This,
            /* [in] */ BSTR bstrSessionId,
            /* [in] */ void *lLockId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ISessionManager * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            ISessionManager * This);
        
        END_INTERFACE
    } ISessionManagerVtbl;

    interface ISessionManager
    {
        CONST_VTBL struct ISessionManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISessionManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISessionManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISessionManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISessionManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISessionManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISessionManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISessionManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISessionManager_get_Session(This,bReadOnly,ppSessionObject)	\
    ( (This)->lpVtbl -> get_Session(This,bReadOnly,ppSessionObject) ) 

#define ISessionManager_StartSession(This)	\
    ( (This)->lpVtbl -> StartSession(This) ) 

#define ISessionManager_EndSession(This)	\
    ( (This)->lpVtbl -> EndSession(This) ) 

#define ISessionManager_OnEndPage(This,bstrSessionId,lLockId)	\
    ( (This)->lpVtbl -> OnEndPage(This,bstrSessionId,lLockId) ) 

#define ISessionManager_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#define ISessionManager_Terminate(This)	\
    ( (This)->lpVtbl -> Terminate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISessionManager_INTERFACE_DEFINED__ */


#ifndef __IPageHandler_INTERFACE_DEFINED__
#define __IPageHandler_INTERFACE_DEFINED__

/* interface IPageHandler */
/* [local][unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IPageHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("37EFC32D-2D2B-4DDB-BD40-19D2BFDF1EA5")
    IPageHandler : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStartPage( 
            /* [in] */ IUnknown *piUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEndPage( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterNotifyOnEndPage( 
            /* [in] */ ISessionManager *pSessionManager,
            /* [in] */ BSTR bstrSessionId,
            /* [in] */ void *lLockId) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPageHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPageHandler * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPageHandler * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPageHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPageHandler * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPageHandler * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPageHandler * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPageHandler * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *OnStartPage )( 
            IPageHandler * This,
            /* [in] */ IUnknown *piUnk);
        
        HRESULT ( STDMETHODCALLTYPE *OnEndPage )( 
            IPageHandler * This);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterNotifyOnEndPage )( 
            IPageHandler * This,
            /* [in] */ ISessionManager *pSessionManager,
            /* [in] */ BSTR bstrSessionId,
            /* [in] */ void *lLockId);
        
        END_INTERFACE
    } IPageHandlerVtbl;

    interface IPageHandler
    {
        CONST_VTBL struct IPageHandlerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPageHandler_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPageHandler_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPageHandler_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPageHandler_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPageHandler_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPageHandler_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPageHandler_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPageHandler_OnStartPage(This,piUnk)	\
    ( (This)->lpVtbl -> OnStartPage(This,piUnk) ) 

#define IPageHandler_OnEndPage(This)	\
    ( (This)->lpVtbl -> OnEndPage(This) ) 

#define IPageHandler_RegisterNotifyOnEndPage(This,pSessionManager,bstrSessionId,lLockId)	\
    ( (This)->lpVtbl -> RegisterNotifyOnEndPage(This,pSessionManager,bstrSessionId,lLockId) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPageHandler_INTERFACE_DEFINED__ */


#ifndef __IInProcSessionStore_INTERFACE_DEFINED__
#define __IInProcSessionStore_INTERFACE_DEFINED__

/* interface IInProcSessionStore */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IInProcSessionStore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1F805DC8-A96F-466E-9487-162695244485")
    IInProcSessionStore : public IASPSessionStoreProvider
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IInProcSessionStoreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IInProcSessionStore * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IInProcSessionStore * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IInProcSessionStore * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IInProcSessionStore * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IInProcSessionStore * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IInProcSessionStore * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IInProcSessionStore * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IInProcSessionStore * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            IInProcSessionStore * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IInProcSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ ExclusiveMode lExclusiveMode,
            /* [in] */ IStream *pStream,
            /* [out] */ void **lLockId,
            /* [out] */ long *lLockAge,
            /* [out] */ VARIANT_BOOL *lLocked);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItem )( 
            IInProcSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ long lTimeout,
            /* [in] */ void *lLockId,
            /* [in] */ IStream *pStream);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseItemExclusive )( 
            IInProcSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lockId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RemoveItem )( 
            IInProcSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lLockId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetItemTimeout )( 
            IInProcSessionStore * This,
            /* [in] */ BSTR bstrKey);
        
        END_INTERFACE
    } IInProcSessionStoreVtbl;

    interface IInProcSessionStore
    {
        CONST_VTBL struct IInProcSessionStoreVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IInProcSessionStore_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IInProcSessionStore_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IInProcSessionStore_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IInProcSessionStore_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IInProcSessionStore_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IInProcSessionStore_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IInProcSessionStore_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IInProcSessionStore_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#define IInProcSessionStore_Terminate(This)	\
    ( (This)->lpVtbl -> Terminate(This) ) 

#define IInProcSessionStore_GetItem(This,bstrKey,lExclusiveMode,pStream,lLockId,lLockAge,lLocked)	\
    ( (This)->lpVtbl -> GetItem(This,bstrKey,lExclusiveMode,pStream,lLockId,lLockAge,lLocked) ) 

#define IInProcSessionStore_SetItem(This,bstrKey,lTimeout,lLockId,pStream)	\
    ( (This)->lpVtbl -> SetItem(This,bstrKey,lTimeout,lLockId,pStream) ) 

#define IInProcSessionStore_ReleaseItemExclusive(This,bstrKey,lockId)	\
    ( (This)->lpVtbl -> ReleaseItemExclusive(This,bstrKey,lockId) ) 

#define IInProcSessionStore_RemoveItem(This,bstrKey,lLockId)	\
    ( (This)->lpVtbl -> RemoveItem(This,bstrKey,lLockId) ) 

#define IInProcSessionStore_ResetItemTimeout(This,bstrKey)	\
    ( (This)->lpVtbl -> ResetItemTimeout(This,bstrKey) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IInProcSessionStore_INTERFACE_DEFINED__ */


#ifndef __ICouchBaseSessionStore_INTERFACE_DEFINED__
#define __ICouchBaseSessionStore_INTERFACE_DEFINED__

/* interface ICouchBaseSessionStore */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICouchBaseSessionStore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("56C5E856-1587-483B-A8A9-7C89DF3E73AD")
    ICouchBaseSessionStore : public IASPSessionStoreProvider
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct ICouchBaseSessionStoreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICouchBaseSessionStore * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICouchBaseSessionStore * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICouchBaseSessionStore * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICouchBaseSessionStore * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICouchBaseSessionStore * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICouchBaseSessionStore * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICouchBaseSessionStore * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ICouchBaseSessionStore * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            ICouchBaseSessionStore * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            ICouchBaseSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ ExclusiveMode lExclusiveMode,
            /* [in] */ IStream *pStream,
            /* [out] */ void **lLockId,
            /* [out] */ long *lLockAge,
            /* [out] */ VARIANT_BOOL *lLocked);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItem )( 
            ICouchBaseSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ long lTimeout,
            /* [in] */ void *lLockId,
            /* [in] */ IStream *pStream);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseItemExclusive )( 
            ICouchBaseSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lockId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RemoveItem )( 
            ICouchBaseSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lLockId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetItemTimeout )( 
            ICouchBaseSessionStore * This,
            /* [in] */ BSTR bstrKey);
        
        END_INTERFACE
    } ICouchBaseSessionStoreVtbl;

    interface ICouchBaseSessionStore
    {
        CONST_VTBL struct ICouchBaseSessionStoreVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICouchBaseSessionStore_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICouchBaseSessionStore_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICouchBaseSessionStore_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICouchBaseSessionStore_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICouchBaseSessionStore_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICouchBaseSessionStore_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICouchBaseSessionStore_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICouchBaseSessionStore_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#define ICouchBaseSessionStore_Terminate(This)	\
    ( (This)->lpVtbl -> Terminate(This) ) 

#define ICouchBaseSessionStore_GetItem(This,bstrKey,lExclusiveMode,pStream,lLockId,lLockAge,lLocked)	\
    ( (This)->lpVtbl -> GetItem(This,bstrKey,lExclusiveMode,pStream,lLockId,lLockAge,lLocked) ) 

#define ICouchBaseSessionStore_SetItem(This,bstrKey,lTimeout,lLockId,pStream)	\
    ( (This)->lpVtbl -> SetItem(This,bstrKey,lTimeout,lLockId,pStream) ) 

#define ICouchBaseSessionStore_ReleaseItemExclusive(This,bstrKey,lockId)	\
    ( (This)->lpVtbl -> ReleaseItemExclusive(This,bstrKey,lockId) ) 

#define ICouchBaseSessionStore_RemoveItem(This,bstrKey,lLockId)	\
    ( (This)->lpVtbl -> RemoveItem(This,bstrKey,lLockId) ) 

#define ICouchBaseSessionStore_ResetItemTimeout(This,bstrKey)	\
    ( (This)->lpVtbl -> ResetItemTimeout(This,bstrKey) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICouchBaseSessionStore_INTERFACE_DEFINED__ */


#ifndef __IMemcachedSessionStore_INTERFACE_DEFINED__
#define __IMemcachedSessionStore_INTERFACE_DEFINED__

/* interface IMemcachedSessionStore */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IMemcachedSessionStore;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7479B092-3C5D-4803-A876-FD6D73877897")
    IMemcachedSessionStore : public IASPSessionStoreProvider
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IMemcachedSessionStoreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMemcachedSessionStore * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMemcachedSessionStore * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMemcachedSessionStore * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMemcachedSessionStore * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMemcachedSessionStore * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMemcachedSessionStore * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMemcachedSessionStore * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IMemcachedSessionStore * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            IMemcachedSessionStore * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IMemcachedSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ ExclusiveMode lExclusiveMode,
            /* [in] */ IStream *pStream,
            /* [out] */ void **lLockId,
            /* [out] */ long *lLockAge,
            /* [out] */ VARIANT_BOOL *lLocked);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetItem )( 
            IMemcachedSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ long lTimeout,
            /* [in] */ void *lLockId,
            /* [in] */ IStream *pStream);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ReleaseItemExclusive )( 
            IMemcachedSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lockId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RemoveItem )( 
            IMemcachedSessionStore * This,
            /* [in] */ BSTR bstrKey,
            /* [in] */ void *lLockId);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ResetItemTimeout )( 
            IMemcachedSessionStore * This,
            /* [in] */ BSTR bstrKey);
        
        END_INTERFACE
    } IMemcachedSessionStoreVtbl;

    interface IMemcachedSessionStore
    {
        CONST_VTBL struct IMemcachedSessionStoreVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMemcachedSessionStore_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMemcachedSessionStore_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMemcachedSessionStore_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMemcachedSessionStore_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMemcachedSessionStore_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMemcachedSessionStore_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMemcachedSessionStore_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMemcachedSessionStore_Initialize(This)	\
    ( (This)->lpVtbl -> Initialize(This) ) 

#define IMemcachedSessionStore_Terminate(This)	\
    ( (This)->lpVtbl -> Terminate(This) ) 

#define IMemcachedSessionStore_GetItem(This,bstrKey,lExclusiveMode,pStream,lLockId,lLockAge,lLocked)	\
    ( (This)->lpVtbl -> GetItem(This,bstrKey,lExclusiveMode,pStream,lLockId,lLockAge,lLocked) ) 

#define IMemcachedSessionStore_SetItem(This,bstrKey,lTimeout,lLockId,pStream)	\
    ( (This)->lpVtbl -> SetItem(This,bstrKey,lTimeout,lLockId,pStream) ) 

#define IMemcachedSessionStore_ReleaseItemExclusive(This,bstrKey,lockId)	\
    ( (This)->lpVtbl -> ReleaseItemExclusive(This,bstrKey,lockId) ) 

#define IMemcachedSessionStore_RemoveItem(This,bstrKey,lLockId)	\
    ( (This)->lpVtbl -> RemoveItem(This,bstrKey,lLockId) ) 

#define IMemcachedSessionStore_ResetItemTimeout(This,bstrKey)	\
    ( (This)->lpVtbl -> ResetItemTimeout(This,bstrKey) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMemcachedSessionStore_INTERFACE_DEFINED__ */


#ifndef __IASPSampleObject_INTERFACE_DEFINED__
#define __IASPSampleObject_INTERFACE_DEFINED__

/* interface IASPSampleObject */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IASPSampleObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("68DC0D9A-79B5-4536-A4B6-D518B57DAE14")
    IASPSampleObject : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStartPage( 
            /* [in] */ IUnknown *piUnk) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEndPage( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IASPSampleObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IASPSampleObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IASPSampleObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IASPSampleObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IASPSampleObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IASPSampleObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IASPSampleObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IASPSampleObject * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *OnStartPage )( 
            IASPSampleObject * This,
            /* [in] */ IUnknown *piUnk);
        
        HRESULT ( STDMETHODCALLTYPE *OnEndPage )( 
            IASPSampleObject * This);
        
        END_INTERFACE
    } IASPSampleObjectVtbl;

    interface IASPSampleObject
    {
        CONST_VTBL struct IASPSampleObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IASPSampleObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IASPSampleObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IASPSampleObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IASPSampleObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IASPSampleObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IASPSampleObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IASPSampleObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IASPSampleObject_OnStartPage(This,piUnk)	\
    ( (This)->lpVtbl -> OnStartPage(This,piUnk) ) 

#define IASPSampleObject_OnEndPage(This)	\
    ( (This)->lpVtbl -> OnEndPage(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IASPSampleObject_INTERFACE_DEFINED__ */



#ifndef __ASPUtilsLib_LIBRARY_DEFINED__
#define __ASPUtilsLib_LIBRARY_DEFINED__

/* library ASPUtilsLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ASPUtilsLib;

EXTERN_C const CLSID CLSID_Cache;

#ifdef __cplusplus

class DECLSPEC_UUID("EF6AFC90-1C08-4AC1-B519-25F748EB2DD2")
Cache;
#endif

EXTERN_C const CLSID CLSID_HashMap;

#ifdef __cplusplus

class DECLSPEC_UUID("A6893607-D7BE-4472-ADB4-C6E3707292E1")
HashMap;
#endif

EXTERN_C const CLSID CLSID_PageHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("5BC738E6-F0E2-42DE-B74C-80E0906AA7EC")
PageHandler;
#endif

EXTERN_C const CLSID CLSID_CustomSession;

#ifdef __cplusplus

class DECLSPEC_UUID("7D59567B-54A4-4FFF-93D2-60BDBB48C046")
CustomSession;
#endif

EXTERN_C const CLSID CLSID_SessionManager;

#ifdef __cplusplus

class DECLSPEC_UUID("757BCA77-5027-4FFA-981C-1B9820520ABB")
SessionManager;
#endif

EXTERN_C const CLSID CLSID_VariantDictionary;

#ifdef __cplusplus

class DECLSPEC_UUID("E230EB51-4C85-48C2-ACA4-DC636F6F3231")
VariantDictionary;
#endif

EXTERN_C const CLSID CLSID_InProcSessionStore;

#ifdef __cplusplus

class DECLSPEC_UUID("25511CDC-CADC-4DEE-8561-7F2CD7AF9E94")
InProcSessionStore;
#endif

EXTERN_C const CLSID CLSID_CouchBaseSessionStore;

#ifdef __cplusplus

class DECLSPEC_UUID("EF8FD5BD-10F5-4C1B-AFFC-DD6EA1E5A1A1")
CouchBaseSessionStore;
#endif

EXTERN_C const CLSID CLSID_MemcachedSessionStore;

#ifdef __cplusplus

class DECLSPEC_UUID("739EAD5F-7EF1-4FFB-B73E-9E6E30642F47")
MemcachedSessionStore;
#endif

EXTERN_C const CLSID CLSID_ASPSampleObject;

#ifdef __cplusplus

class DECLSPEC_UUID("2EB20D67-4B53-4709-AE62-A657EF5BB7CC")
ASPSampleObject;
#endif
#endif /* __ASPUtilsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


