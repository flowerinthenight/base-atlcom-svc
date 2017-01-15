#include "stdafx.h"
#include "Notify.h"
#include <strsafe.h>
#include "../include/jytrace.h"

STDMETHODIMP CNotify::SetNotifyValue(ULONG lValue)
{
    VARIANT_BOOL cancel = VARIANT_FALSE;
    Fire_NotifyValueUpdated(lValue, &cancel);

    if (cancel == VARIANT_FALSE)
    {
        wchar_t m[MAX_PATH];
        StringCchPrintf(m, MAX_PATH, L"Value from client: %d", lValue);
        EventWriteInfoW(M, FL, FN, m);
    }

    return S_OK;
}