// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED

#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#include <WinSock2.h> //include winsock2 before windows.h

//#include <comsvcs.h>

#define ATL_NO_ASSERT_ON_DESTROY_NONEXISTENT_WINDOW

//#define _ATL_DEGUG_REFCOUNT 
//#define _ATL_DEBUG_INTERFACES
//#define _ATL_DEBUG_QI

#include <initguid.h>

#include "resource.h"
#include <atlbase.h>
#include <atlstr.h>
#include <atlcom.h>
#include <atlctl.h>
#include "variant.h"
//#include <mtx.h>
//#include <comsvcs.h>
//#include <asptlb.h>         // Active Server Pages Definitions
///////////////////
// HRESULT checking
///////////////////
#define TestHR(hr) {HRESULT _hr(hr); if (FAILED(_hr) || _hr == S_FALSE) return _hr == S_FALSE ? E_FAIL : _hr;}
