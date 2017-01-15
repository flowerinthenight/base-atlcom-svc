#pragma once

struct __declspec(uuid("464C0A7E-801F-4009-B762-E3791F6EAF52")) IWinProcSupport;

struct IWinProcSupport : public IUnknown {
    virtual BOOL Initialize(WNDPROC pfnWindowProc) = 0;
    virtual void Close() = 0;
};

HRESULT CreateWinProcSupportInstance(IWinProcSupport **ppObj);