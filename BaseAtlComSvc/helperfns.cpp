#include "stdafx.h"
#include "helperfns.h"

BOOL WaitForWtsService(DWORD dwWaitMs)
{
    BOOL bReturn = FALSE;

    // Try to wait for the needed service(s) to be started.
    HANDLE hWtsEvent = OpenEvent(SYNCHRONIZE, FALSE, L"Global\\TermSrvReadyEvent");

    if (hWtsEvent) {
        if (WaitForSingleObject(hWtsEvent, dwWaitMs) == WAIT_OBJECT_0) {
            bReturn = TRUE;
        }

        CloseHandle(hWtsEvent);
    }

    return bReturn;
}