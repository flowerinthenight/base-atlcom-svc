#include "stdafx.h"
#include <Windows.h>
#include <WtsApi32.h>
#include "WinProcSupport.h"
#include "helperfns.h"
#include "..\include\jytrace.h"

class CWinProcSupport : public IWinProcSupport
{
public:
    CWinProcSupport() :
        m_lRefCount(0),
        m_bInitialized(FALSE),
        m_hWnd(NULL),
        m_hThread(NULL),
        m_hTermEvent(NULL),
        m_pfnWndProc(NULL) {};

    ~CWinProcSupport()
    {
        EventWriteFunctionEntry(M, FL, FN);
        Close();
    };

    // IUnknown methods.
    STDMETHODIMP QueryInterface(REFIID iid, void** ppv)
    {
        if ((iid == __uuidof(IUnknown)) || (iid == __uuidof(IWinProcSupport))) {
            *ppv = static_cast<CWinProcSupport*>(this);
        } else {
            *ppv = NULL;
            return E_NOINTERFACE;
        }

        AddRef();
        return S_OK;
    }

    STDMETHODIMP_(ULONG) AddRef()
    {
        return InterlockedIncrement(&m_lRefCount);
    }

    STDMETHODIMP_(ULONG) Release()
    {
        ULONG uCount = InterlockedDecrement(&m_lRefCount);

        if (uCount == 0) {
            delete this;
        }

        return uCount;
    }

    // IWinProcSupport methods.
    BOOL Initialize(WNDPROC pfnWindowProc)
    {
        if (!pfnWindowProc) {
            return FALSE;
        }

        m_pfnWndProc = pfnWindowProc;
        m_hTermEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

        m_hThread = CreateThread(
            NULL,
            0,
            DispatchWndProcThreadFunction,
            (PVOID)this,
            0,
            NULL);

        if (m_hTermEvent && m_hThread) {
            EventWritePointerInfo(M, FL, FN, L"TermEvent", m_hTermEvent);
            EventWritePointerInfo(M, FL, FN, L"WndProc thread", m_hThread);
            m_bInitialized = TRUE;
        }

        return m_bInitialized;
    }

    void Close()
    {
        if (m_bInitialized) {
            if (m_hWnd) {
                DestroyWindow(m_hWnd);
            }

            if (m_hTermEvent) {
                SetEvent(m_hTermEvent);
                CloseHandle(m_hTermEvent);
            }

            WaitForSingleObject(m_hThread, 10000);
            m_bInitialized = FALSE;
        }
    }

private:
    static DWORD WINAPI DispatchWndProcThreadFunction(LPVOID lpData)
    {
        return static_cast<CWinProcSupport*>(lpData)->WndProcThreadFunction();
    }

    DWORD WINAPI WndProcThreadFunction(VOID)
    {
        MSG m;
        BOOL bWts;
        WNDCLASSEX c;
        c.cbSize = sizeof(WNDCLASSEX);
        c.style = CS_HREDRAW | CS_VREDRAW;;
        c.lpfnWndProc = m_pfnWndProc;
        c.cbClsExtra = 0;
        c.cbWndExtra = 0;
        c.hInstance = GetModuleHandle(NULL);
        c.hIcon = NULL;
        c.hCursor = NULL;
        c.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);;
        c.lpszMenuName = NULL;
        c.lpszClassName = L"ClassHidden";
        c.hIconSm = NULL;

        if (!RegisterClassEx(&c)) {
            EventWriteLastError(M, FL, FN, L"Error RegisterClassEx", GetLastError());
            return FALSE;
        }

        m_hWnd = CreateWindow(
            L"ClassHidden",
            L"ClassHidden",
            WS_OVERLAPPEDWINDOW,
            10,
            10,
            400,
            200,
            NULL,
            NULL,
            GetModuleHandle(NULL),
            NULL);

        if (m_hWnd) {
            // Register for session notifications. Try to wait for the need services to be started.
            if (WaitForWtsService(60000)) {
                bWts = WTSRegisterSessionNotification(m_hWnd, NOTIFY_FOR_ALL_SESSIONS);
            }
        }

        while (GetMessage(&m, NULL, 0, 0)) {
            if (WaitForSingleObject(m_hTermEvent, 0) == WAIT_OBJECT_0) {
                break;
            }

            TranslateMessage(&m);
            DispatchMessage(&m);
        }

        if (bWts) {
            WTSUnRegisterSessionNotification(m_hWnd);
        }

        return NOERROR;
    }

private:
    LONG m_lRefCount;
    BOOL m_bInitialized;
    HWND m_hWnd;
    HANDLE m_hThread;
    HANDLE m_hTermEvent;
    WNDPROC m_pfnWndProc;
};

HRESULT CreateWinProcSupportInstance(IWinProcSupport **ppObj)
{
    if (ppObj == NULL) return E_POINTER;

    IWinProcSupport *pObj = new (std::nothrow) CWinProcSupport();

    if (pObj == NULL) return E_OUTOFMEMORY;

    *ppObj = pObj;
    (*ppObj)->AddRef();

    return S_OK;
}