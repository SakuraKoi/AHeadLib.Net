// @generated
// AHeadLib.Net
// https://github.com/SakuraKoi/AHeadLib.Net
// Powered by bodong | Modified by.SakuraKooi

#include <windows.h>

#if defined(_WIN64) || defined(_X64) || defined(WIN64) || defined( __LP64__ )
#define __X64_BUILD__ 1
#else
#define __X64_BUILD__ 0
#endif

// checked get function in native dll
static void* __CheckedGetFunction(HMODULE module, const char* methodName)
{
    void* Result = GetProcAddress(module, methodName);

    if (Result == NULL)
    {
        char szMessage[256];
        wsprintfA(szMessage, "Failed bind method:%s", methodName);

        OutputDebugStringA(szMessage);

#if DEBUG
        MessageBoxA(0, szMessage, "AHeadLib.Net Error", 0);
        ExitProcess(-1);
#endif
    }

    return Result;
}

// ${EXPORTED_POINTERS}

// ${EXPORTED_FUNCTIONS}

// ${EXPORTED_LINKERS}

// bind native dll first
extern void GetOrignalLibraryPath(TCHAR* bufferPtr, int bufferLength, const TCHAR* libName);

void __CheckedLoad()
{
    TCHAR szPath[MAX_PATH];

    GetOrignalLibraryPath(szPath, MAX_PATH, TEXT("${LIBRARY_NAME}"));

    // if your dll is not in system path
    // please reset szPath here
    HMODULE module = LoadLibrary(szPath);

    if (module == NULL)
    {
        TCHAR szMessage[MAX_PATH];
        wsprintf(szMessage, TEXT("Failed load dll from:%s"), szPath);
        MessageBox(0, szMessage, TEXT("AHeadLib.Net Error"), 0);
        
        ExitProcess(1);
        return;
    }

    // ${BIND_POINTERS}
}
