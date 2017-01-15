#pragma once
#include "resource.h"
#include "BaseAtlComSvc_i.h"
#include "_INotifyEvents_CP.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;

class ATL_NO_VTABLE CNotify :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CNotify, &CLSID_Notify>,
	public IConnectionPointContainerImpl<CNotify>,
	public CProxy_INotifyEvents<CNotify>,
	public IDispatchImpl<INotify, &IID_INotify, &LIBID_BaseAtlComSvcLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CNotify()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_NOTIFY)

BEGIN_COM_MAP(CNotify)
	COM_INTERFACE_ENTRY(INotify)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CNotify)
	CONNECTION_POINT_ENTRY(__uuidof(_INotifyEvents))
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
    STDMETHOD(SetNotifyValue)(ULONG lValue);
};

OBJECT_ENTRY_AUTO(__uuidof(Notify), CNotify)
