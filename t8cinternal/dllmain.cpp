// dllmain.cpp : Defines the entry point for the DLL application.
#include "framework.h"
#include "builtins.h"
#include "detours.h"
#include "LazyLink.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        GSCBuiltins::Init();
        ScriptDetours::InstallHooks();
        LazyLink::Init();
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

