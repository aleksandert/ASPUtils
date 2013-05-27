// ASPUtilsConsoleTestWin32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#pragma comment(lib,"ASPUtils")

int _tmain(int argc, _TCHAR* argv[])
{

	ReadConsole(NULL, NULL, 0, 0, NULL);

	HRESULT hr;
	IResourceProviderProxy* pIResourceProviderProxy;
	

	CoInitialize(NULL);
	
	hr = CoCreateInstance ( CLSID_ResourceProviderProxy,
                            NULL,
                            CLSCTX_INPROC_SERVER,
                            IID_IResourceProviderProxy,
                            (void**) &pIResourceProviderProxy );


	if (SUCCEEDED(hr))
    {
		CComVariant key("text");
		CComVariant value("headerTextLogIn");

		
		
		CComVariant out;
		pIResourceProviderProxy->GetGlobalResourceObject(key, value, &out);


		

		

		pIResourceProviderProxy->Release();
    }

	CoUninitialize();

	return 0;
}

