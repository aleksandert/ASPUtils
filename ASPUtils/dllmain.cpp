// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "ASPUtils_i.h"
#include "dllmain.h"

CASPUtilsModule _AtlModule;

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	/*if (dwReason == DLL_PROCESS_DETACH)
	{
		ATL::AtlDumpMemoryLeaks();
	}*/
	hInstance;
	return _AtlModule.DllMain(dwReason, lpReserved); 
}
