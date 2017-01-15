

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Jan 15 14:11:05 2017
 */
/* Compiler settings for BaseAtlComSvc.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.00.0603 
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

#ifndef __BaseAtlComSvc_i_h__
#define __BaseAtlComSvc_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISvcVersion_FWD_DEFINED__
#define __ISvcVersion_FWD_DEFINED__
typedef interface ISvcVersion ISvcVersion;

#endif 	/* __ISvcVersion_FWD_DEFINED__ */


#ifndef ___ISvcVersionEvents_FWD_DEFINED__
#define ___ISvcVersionEvents_FWD_DEFINED__
typedef interface _ISvcVersionEvents _ISvcVersionEvents;

#endif 	/* ___ISvcVersionEvents_FWD_DEFINED__ */


#ifndef __SvcVersion_FWD_DEFINED__
#define __SvcVersion_FWD_DEFINED__

#ifdef __cplusplus
typedef class SvcVersion SvcVersion;
#else
typedef struct SvcVersion SvcVersion;
#endif /* __cplusplus */

#endif 	/* __SvcVersion_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISvcVersion_INTERFACE_DEFINED__
#define __ISvcVersion_INTERFACE_DEFINED__

/* interface ISvcVersion */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISvcVersion;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34E1B687-CCCE-4AC4-A91D-C0FF0AA57EBB")
    ISvcVersion : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [out] */ LONG *pMajor,
            /* [out] */ LONG *pMinor,
            /* [out] */ LONG *pRev) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ISvcVersionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISvcVersion * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISvcVersion * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISvcVersion * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISvcVersion * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISvcVersion * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISvcVersion * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISvcVersion * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            ISvcVersion * This,
            /* [out] */ LONG *pMajor,
            /* [out] */ LONG *pMinor,
            /* [out] */ LONG *pRev);
        
        END_INTERFACE
    } ISvcVersionVtbl;

    interface ISvcVersion
    {
        CONST_VTBL struct ISvcVersionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISvcVersion_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISvcVersion_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISvcVersion_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISvcVersion_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISvcVersion_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISvcVersion_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISvcVersion_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISvcVersion_GetVersion(This,pMajor,pMinor,pRev)	\
    ( (This)->lpVtbl -> GetVersion(This,pMajor,pMinor,pRev) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISvcVersion_INTERFACE_DEFINED__ */



#ifndef __BaseAtlComSvcLib_LIBRARY_DEFINED__
#define __BaseAtlComSvcLib_LIBRARY_DEFINED__

/* library BaseAtlComSvcLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_BaseAtlComSvcLib;

#ifndef ___ISvcVersionEvents_DISPINTERFACE_DEFINED__
#define ___ISvcVersionEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ISvcVersionEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__ISvcVersionEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0C04C14F-ACF5-4F3A-BB5C-2B9628C17AEF")
    _ISvcVersionEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ISvcVersionEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ISvcVersionEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ISvcVersionEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ISvcVersionEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ISvcVersionEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ISvcVersionEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ISvcVersionEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ISvcVersionEvents * This,
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
        
        END_INTERFACE
    } _ISvcVersionEventsVtbl;

    interface _ISvcVersionEvents
    {
        CONST_VTBL struct _ISvcVersionEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISvcVersionEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ISvcVersionEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ISvcVersionEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ISvcVersionEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ISvcVersionEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ISvcVersionEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ISvcVersionEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISvcVersionEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SvcVersion;

#ifdef __cplusplus

class DECLSPEC_UUID("05F12D72-A394-4FED-A515-B723CC9D1EBE")
SvcVersion;
#endif
#endif /* __BaseAtlComSvcLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


