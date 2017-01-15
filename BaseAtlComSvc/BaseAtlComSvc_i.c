

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Sun Jan 15 16:29:10 2017
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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_ISvcVersion,0x34E1B687,0xCCCE,0x4AC4,0xA9,0x1D,0xC0,0xFF,0x0A,0xA5,0x7E,0xBB);


MIDL_DEFINE_GUID(IID, IID_INotify,0x957CE93B,0x62E9,0x4174,0x8E,0x23,0x49,0xF3,0xBB,0x27,0xFE,0x26);


MIDL_DEFINE_GUID(IID, LIBID_BaseAtlComSvcLib,0x44D1FD4A,0xA21A,0x47F6,0xA3,0x39,0x71,0x35,0x08,0x52,0x0C,0xD7);


MIDL_DEFINE_GUID(IID, DIID__ISvcVersionEvents,0x0C04C14F,0xACF5,0x4F3A,0xBB,0x5C,0x2B,0x96,0x28,0xC1,0x7A,0xEF);


MIDL_DEFINE_GUID(CLSID, CLSID_SvcVersion,0x05F12D72,0xA394,0x4FED,0xA5,0x15,0xB7,0x23,0xCC,0x9D,0x1E,0xBE);


MIDL_DEFINE_GUID(IID, DIID__INotifyEvents,0xDB021548,0x0779,0x4156,0xBE,0x34,0xAF,0x43,0x59,0x47,0xD2,0x68);


MIDL_DEFINE_GUID(CLSID, CLSID_Notify,0xC6C3DE81,0x67BC,0x4694,0x92,0x74,0x03,0xF4,0x94,0x26,0xAB,0xB0);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



