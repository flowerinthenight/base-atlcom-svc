#include "stdafx.h"
#include "SvcVersion.h"

STDMETHODIMP CSvcVersion::GetVersion(LONG *pMajor, LONG *pMinor, LONG *pRev)
{
    *pMajor = 1;
    *pMinor = 0;
    *pRev = 0;
    return S_OK;
}