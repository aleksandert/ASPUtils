// PageHandler.cpp : Implementation of CPageHandler

#include "stdafx.h"
#include "PageHandler.h"


// CPageHandler

STDMETHODIMP CPageHandler::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_IPageHandler
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CPageHandler::OnStartPage (IUnknown* pUnk)  
{
	//if(!pUnk)
	//	return E_POINTER;

	//CComPtr<IScriptingContext> spContext;
	//HRESULT hr;

	//// Get the IScriptingContext Interface
	//hr = pUnk->QueryInterface(__uuidof(IScriptingContext), (void **)&spContext);
	//if(FAILED(hr))
	//	return hr;

	//// Get Request Object Pointer
	//hr = spContext->get_Request(&m_piRequest);
	//if(FAILED(hr))
	//{
	//	return hr;
	//}

	//// Get Response Object Pointer
	//hr = spContext->get_Response(&m_piResponse);
	//if(FAILED(hr))
	//{
	//	m_piRequest.Release();
	//	return hr;
	//}
	//
	//// Get Server Object Pointer
	//hr = spContext->get_Server(&m_piServer);
	//if(FAILED(hr))
	//{
	//	m_piRequest.Release();
	//	m_piResponse.Release();
	//	return hr;
	//}
	//
	//// Get Session Object Pointer
	//hr = spContext->get_Session(&m_piSession);
	//if(FAILED(hr))
	//{
	//	m_piRequest.Release();
	//	m_piResponse.Release();
	//	m_piServer.Release();
	//	return hr;
	//}

	//// Get Application Object Pointer
	//hr = spContext->get_Application(&m_piApplication);
	//if(FAILED(hr))
	//{
	//	m_piRequest.Release();
	//	m_piResponse.Release();
	//	m_piServer.Release();
	//	m_piSession.Release();
	//	return hr;
	//}
	//m_bOnStartPageCalled = TRUE;

	return S_OK;
}

STDMETHODIMP CPageHandler::OnEndPage ()  
{
	HRESULT hr = m_SessionManager->OnEndPage(m_SessionId, m_LockId);

	m_SessionManager.Release();
	m_SessionId.Empty();

	//m_bOnStartPageCalled = FALSE;
	//// Release all interfaces
	//m_piRequest.Release();
	//m_piResponse.Release();
	//m_piServer.Release();
	//m_piSession.Release();
	//m_piApplication.Release();

	return hr;
}

STDMETHODIMP CPageHandler::RegisterNotifyOnEndPage(ISessionManager *pSessionManager, BSTR bstrSessionId, void* lLockId)
{
	CComPtr<ISessionManager> piSessionManager(pSessionManager); //AddRef

	m_SessionManager = piSessionManager;
	m_SessionId.AssignBSTR(bstrSessionId);
	m_LockId = lLockId;

	return S_OK;
}