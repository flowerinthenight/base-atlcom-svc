#pragma once
#include "resource.h"
#include "BaseAtlComSvc_i.h"
#include "_ISvcVersionEvents_CP.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

class ATL_NO_VTABLE CSvcVersion :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSvcVersion, &CLSID_SvcVersion>,
	public IConnectionPointContainerImpl<CSvcVersion>,
	public CProxy_ISvcVersionEvents<CSvcVersion>,
	public IDispatchImpl<ISvcVersion, &IID_ISvcVersion, &LIBID_BaseAtlComSvcLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CSvcVersion()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SVCVERSION)

BEGIN_COM_MAP(CSvcVersion)
	COM_INTERFACE_ENTRY(ISvcVersion)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CSvcVersion)
	CONNECTION_POINT_ENTRY(__uuidof(_ISvcVersionEvents))
END_CONNECTION_POINT_MAP()

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
    STDMETHOD(GetVersion)(LONG *pMajor, LONG *pMinor, LONG *pRev);
};

OBJECT_ENTRY_AUTO(__uuidof(SvcVersion), CSvcVersion)
