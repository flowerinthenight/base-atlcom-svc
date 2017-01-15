#include "stdafx.h"
#include <Windows.h>
#include "WinProcSupport.h"
#include "helperfns.h"
#include "resource.h"
#include "BaseAtlComSvc_i.h"
using namespace ATL;
#include <stdio.h>
#include <strsafe.h>
#include "..\include\jytrace.h"

#pragma comment(lib, "wtsapi32.lib")

class CBaseAtlComSvcModule : public ATL::CAtlServiceModuleT< CBaseAtlComSvcModule, IDS_SERVICENAME >
{
public:
    DECLARE_LIBID(LIBID_BaseAtlComSvcLib)
    DECLARE_REGISTRY_APPID_RESOURCEID(IDR_BASEATLCOMSVC, "{FA46DBF3-6E50-4DC9-AAA8-10DFDC6AF7BF}")
    HRESULT InitializeSecurity() throw()
    {
        // TODO : Call CoInitializeSecurity and provide the appropriate security settings for your service
        // Suggested - PKT Level Authentication, 
        // Impersonation Level of RPC_C_IMP_LEVEL_IDENTIFY 
        // and an appropriate Non NULL Security Descriptor.

        CSecurityDescriptor sd;
        sd.InitializeFromThreadToken();

        return CoInitializeSecurity(
            sd,
            -1,
            NULL,
            NULL,
            RPC_C_AUTHN_LEVEL_PKT,
            RPC_C_IMP_LEVEL_IMPERSONATE,
            NULL,
            EOAC_NONE,
            NULL);
    }

    void ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
    HRESULT PreMessageLoop(int nShowCmd);
    HRESULT PostMessageLoop();
    void Handler(DWORD dwOpcode);

private:
    IWinProcSupport *pWTSWndProc;
};

CBaseAtlComSvcModule _AtlModule;

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}

void CBaseAtlComSvcModule::ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv)
{
    CAtlServiceModuleT<CBaseAtlComSvcModule, 100>::ServiceMain(dwArgc, lpszArgv);
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam);

HRESULT CBaseAtlComSvcModule::PreMessageLoop(int nShowCmd)
{
    EventRegisterJyTrace();
    EventWriteFunctionEntry(M, FL, FN);

    // Our internal window for normal window messages in service code.
    CreateWinProcSupportInstance(&pWTSWndProc);

    if (pWTSWndProc) {
        EventWriteInfoW(M, FL, FN, L"Initialize internal window procedure.");
        pWTSWndProc->Initialize(WindowProc);
    }

    return CAtlServiceModuleT<CBaseAtlComSvcModule, 100>::PreMessageLoop(nShowCmd);
}

HRESULT CBaseAtlComSvcModule::PostMessageLoop()
{
    EventWriteFunctionEntry(M, FL, FN);

    if (pWTSWndProc) {
        pWTSWndProc->Release();
    }

    EventUnregisterJyTrace();
    return CAtlServiceModuleT<CBaseAtlComSvcModule, 100>::PostMessageLoop();
}

void CBaseAtlComSvcModule::Handler(DWORD dwOpcode)
{
    wchar_t m[MAX_PATH];

    StringCchPrintf(m, MAX_PATH, L"ControlCode: %d", dwOpcode);
    EventWriteInfoW(M, FL, FN, m);

    switch (dwOpcode) {
    default:
        break;
    }

    CAtlServiceModuleT<CBaseAtlComSvcModule, 100>::Handler(dwOpcode);
}

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam)
{
    switch (uMessage) {
    case WM_QUIT:
        EventWriteInfoW(M, FL, FN, L"WM_QUIT:");
        return 0;

    case WM_DESTROY:
        EventWriteInfoW(M, FL, FN, L"WM_DESTROY:");
        PostQuitMessage(0);
        return 0;

    case WM_WTSSESSION_CHANGE:
        EventWriteInfoW(M, FL, FN, L"WM_WTSSESSION_CHANGE:");

        if (wParam == WTS_SESSION_LOGOFF) {
            EventWriteWideStrInfo(M, FL, FN, L"WM_WTSSESSION_CHANGE", L"WTS_SESSION_LOGOFF");
        }
        else if (wParam == WTS_SESSION_LOGON) {
            EventWriteWideStrInfo(M, FL, FN, L"WM_WTSSESSION_CHANGE", L"WTS_SESSION_LOGON");
        }
    }

    return DefWindowProc(hWnd, uMessage, wParam, lParam);
}