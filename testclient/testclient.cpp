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

int _tmain(int argc, _TCHAR* argv[])
{
    if (argc >= 2) {
        if (_wcsicmp(argv[1], L"event") == 0) {
            _tprintf(L"test event\n");
            return 0;
        }
    }

    GetServiceVersion();
    return 0;
}

