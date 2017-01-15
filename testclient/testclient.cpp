#include "stdafx.h"
#include <Windows.h>
#include "../BaseAtlComSvc/BaseAtlComSvc_i.h"
#include <comdef.h>
#include <strsafe.h>
#include <initguid.h>

DEFINE_GUID(IID_ISvcVersion, 0x34E1B687, 0xCCCE, 0x4AC4, 0xA9, 0x1D, 0xC0, 0xFF, 0x0A, 0xA5, 0x7E, 0xBB);
DEFINE_GUID(CLSID_SvcVersion, 0x05F12D72, 0xA394, 0x4FED, 0xA5, 0x15, 0xB7, 0x23, 0xCC, 0x9D, 0x1E, 0xBE);

void PrintComError(HRESULT hr, TCHAR *pStr)
{
    _com_error err(hr);
    LPCTSTR szErrorText = err.ErrorMessage();
    wchar_t m[MAX_PATH];
    StringCchPrintf(m, MAX_PATH, L"%s: %s (0x%x)\n", pStr, szErrorText, hr);
    _tprintf(m);
}

void GetServiceVersion()
{
    CoInitialize(NULL);

    ISvcVersion *pSvcVer;
    HRESULT hr;

    hr = CoCreateInstance(CLSID_SvcVersion, NULL, CLSCTX_LOCAL_SERVER, IID_ISvcVersion, (VOID**)&pSvcVer);

    if (FAILED(hr)) {
        PrintComError(hr, L"CoCreateInstance");
        CoUninitialize();
        return;
    }

    LONG maj, min, rev;

    hr = pSvcVer->GetVersion(&maj, &min, &rev);
    _tprintf(L"Service version: %d.%d.%d", maj, min, rev);
    
    pSvcVer->Release();

    CoUninitialize();
}

DEFINE_GUID(IID_INotify, 0x957CE93B, 0x62E9, 0x4174, 0x8E, 0x23, 0x49, 0xF3, 0xBB, 0x27, 0xFE, 0x26);
DEFINE_GUID(CLSID_Notify, 0xC6C3DE81, 0x67BC, 0x4694, 0x92, 0x74, 0x03, 0xF4, 0x94, 0x26, 0xAB, 0xB0);
DEFINE_GUID(DIID__INotifyEvents, 0xDB021548, 0x0779, 0x4156, 0xBE, 0x34, 0xAF, 0x43, 0x59, 0x47, 0xD2, 0x68);

class CNotifySink : _INotifyEvents {
public:
    CNotifySink::CNotifySink() :
        m_dwRefCount(0) {}

    CNotifySink::~CNotifySink() {}

    // IUnknown
    IFACEMETHODIMP QueryInterface(const IID& iid, void** ppUnk)
    {
        if ((iid == __uuidof(IUnknown)) || (iid == __uuidof(_INotifyEvents))) {
            *ppUnk = static_cast<CNotifySink*>(this);
        } else {
            *ppUnk = NULL;
            return E_NOINTERFACE;
        }

        AddRef();
        return S_OK;
    }

    IFACEMETHODIMP_(ULONG) AddRef()
    {
        return InterlockedIncrement(&m_dwRefCount);
    }

    IFACEMETHODIMP_(ULONG) Release()
    {
        LONG _lRef = InterlockedDecrement(&m_dwRefCount);

        if (_lRef == 0) {
            delete this;
        }

        return _lRef;
    }

    // IDispatch
    HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pI)
    {
        return E_NOTIMPL;
    };

    HRESULT STDMETHODCALLTYPE GetIDsOfNames(
        REFIID riid,
        OLECHAR FAR* FAR* rgszNames,
        unsigned int  cNames,
        LCID   lcid,
        DISPID FAR*  rgDispId)
    {
        return E_NOTIMPL;
    }

    HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTinfo, LCID lcid, ITypeInfo FAR **ppTIinfo)
    {
        return E_NOTIMPL;
    }

    HRESULT STDMETHODCALLTYPE Invoke(DISPID  dispIdMember,
        REFIID  riid,
        LCID  lcid,
        WORD  wFlags,
        DISPPARAMS FAR*  pDispParams,
        VARIANT FAR*  pVarResult,
        EXCEPINFO FAR*  pExcepInfo,
        unsigned int FAR*  puArgErr)
    {
        HRESULT hr = S_OK;
        VARIANT_BOOL bTrue = VARIANT_TRUE;

        if (pDispParams) {
            switch (dispIdMember) {
            case 1:
                return NotifyUpdated(pDispParams->rgvarg[1].ulVal, &bTrue);

            default:
                return E_NOTIMPL;
            }
        }

        return E_NOTIMPL;
    }

    // _INotifyEvents
    HRESULT STDMETHODCALLTYPE NotifyUpdated(ULONG ulNewValue, VARIANT_BOOL *pCancel)
    {
        _tprintf(L"[Event from service] value = %d\n", ulNewValue);
        return S_OK;
    };

private:
    DWORD m_dwRefCount;
};

void TestNotify()
{
    CoInitialize(NULL);

    INotify *pNotify;
    IConnectionPointContainer *pConPointCont = NULL;
    IConnectionPoint *pConPoint = NULL;
    CNotifySink *pSink = NULL;
    IUnknown *pUnk = NULL;
    DWORD dwCookie = 0;

    HRESULT hr = CoCreateInstance(CLSID_Notify, NULL, CLSCTX_LOCAL_SERVER, IID_INotify, (VOID**)&pNotify);
    if (FAILED(hr)) PrintComError(hr, L"CoCreateInstance");

    hr = pNotify->QueryInterface(__uuidof(IConnectionPointContainer), (void**)&pConPointCont);

    if (SUCCEEDED(hr)) {
        _tprintf(L"Connection container okay.\n");
        hr = pConPointCont->FindConnectionPoint(DIID__INotifyEvents, &pConPoint);

        if (SUCCEEDED(hr)) {
            _tprintf(L"Connection okay.\n");
            pSink = new CNotifySink();

            if (pSink) {
                pSink->QueryInterface(IID_IUnknown, (void**)&pUnk);

                if (pUnk) {
                    hr = pConPoint->Advise(pUnk, &dwCookie);
                    if (SUCCEEDED(hr)) _tprintf(L"Advise okay.\n");
                }
            }
        }
    } else {
        _tprintf(L"[Error: QueryInterface] hr = %x\n", hr);
    }

    _tprintf(L"Set notify value to 200\n");
    pNotify->SetNotifyValue(200);
    system("pause");

    pNotify->Release();
    delete pSink;

    CoUninitialize();
}

int _tmain(int argc, _TCHAR* argv[])
{
    if (argc >= 2) {
        if (_wcsicmp(argv[1], L"event") == 0) {
            TestNotify();
            return 0;
        }
    }

    GetServiceVersion();
    return 0;
}

