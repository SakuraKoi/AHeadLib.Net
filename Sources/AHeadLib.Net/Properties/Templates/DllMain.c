// @generated
// AHeadLib.Net
// https://github.com/SakuraKoi/AHeadLib.Net
// Powered by bodong | Modified by.SakuraKooi

#include <windows.h>

extern void __CheckedLoad();
extern void __ExecuteUserCutomCodes();
extern int __CheckShouldExecuteAttachCode();

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpvReserved)  // reserved
{
    // Perform actions based on the reason for calling.
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        __CheckedLoad();

        if (__CheckShouldExecuteAttachCode() > 0)
        {
            // apply user custom codes
            __ExecuteUserCutomCodes();
        }

        break;

    case DLL_THREAD_ATTACH:
        // Do thread-specific initialization.
        break;

    case DLL_THREAD_DETACH:
        // Do thread-specific cleanup.
        break;

    case DLL_PROCESS_DETACH:

        if (lpvReserved != NULL)
        {
            break; // do not do cleanup if process termination scenario
        }

        // Perform any necessary cleanup.
        break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

