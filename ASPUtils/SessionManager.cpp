// SessionManager.cpp : Implementation of CSessionManager

#include "stdafx.h"
#include "comip.h"
#include "SessionManager.h"
#include <thread>

// CSessionManager

STDMETHODIMP CSessionManager::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_ISessionManager
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CSessionManager::Initialize()
{
	HRESULT hr;

	LPOLESTR progId;
	
	hr = ProgIDFromCLSID(CLSID_PageHandler, &progId);

	if(SUCCEEDED(hr))
	{
		m_PageHandlerProgId = progId;
	}
	
	CoTaskMemFree(progId); 

	if (FAILED(hr))
	{
		return hr;
	}

	//TestHR(m_piStoreProvider.CoCreateInstance(__uuidof(InProcSessionStore), NULL, CLSCTX_ALL));
	
	//hr = m_piStoreProvider.CoCreateInstance(__uuidof(CouchBaseSessionStore), NULL, CLSCTX_ALL);

	hr = m_piStoreProvider.CoCreateInstance(__uuidof(MemcachedSessionStore), NULL, CLSCTX_ALL);

	if (FAILED(hr))
	{
		return hr;
	}

	hr = m_piStoreProvider->Initialize();

	if (FAILED(hr))
	{
		return hr;
	}

	return S_OK;
}

STDMETHODIMP CSessionManager::Terminate()
{
	m_Sessions.RemoveAll();

	m_piStoreProvider.Release();

	return S_OK;
}

STDMETHODIMP CSessionManager::StartSession()
{
	//get asp context
	CASPContext cxt;

	TestHR(cxt.Init( CASPContext::get_Response | CASPContext::get_Session | CASPContext::get_Server ));

	std::chrono::milliseconds dura( 10000 );
	std::this_thread::sleep_for( dura );

	//create and initialize custom session object
	CComPtr<ICustomSession> piCustomSession;
	TestHR(piCustomSession.CoCreateInstance(__uuidof(CustomSession), NULL, CLSCTX_ALL));
	TestHR(piCustomSession->Init(cxt.Session()));
	
	//write custom session cookie
	CComBSTR bstrSessionId;
	TestHR(piCustomSession->get_SessionID(&bstrSessionId));
	
	TestHR(RegisterOnPage(bstrSessionId, NULL /*lLockId*/, cxt.Server(), piCustomSession));

	TestHR(WriteSessionCookie(cxt.Response(), bstrSessionId));

	return S_OK;
}

STDMETHODIMP CSessionManager::EndSession()
{
	return S_OK;
}

// returns custom session object
STDMETHODIMP CSessionManager::get_Session(BOOL bReadOnly, ICustomSession **ppSessionObject)
{
	if (ppSessionObject == NULL)
	{
		return E_POINTER;
	}

	CASPContext cxt;

	TestHR(cxt.Init(CASPContext::get_Request | CASPContext::get_Server));

	//read session cookie
	CComBSTR bstrSessionId;

	TestHR(ReadSessionCookie(cxt.Request(), &bstrSessionId));

	//check if session is already loaded for this request
	CComPtr<ICustomSession> piCustomSession;

	if (!m_Sessions.Lookup(bstrSessionId, piCustomSession))
	{
		TestHR(piCustomSession.CoCreateInstance(__uuidof(CustomSession), NULL, CLSCTX_ALL));

		void* lockId;

		TestHR(LoadSessionState(bstrSessionId, bReadOnly, &lockId, piCustomSession));

		TestHR(RegisterOnPage(bstrSessionId, lockId, cxt.Server(), piCustomSession));
	}

	return piCustomSession.CopyTo(ppSessionObject);
}

STDMETHODIMP CSessionManager::RegisterOnPage(BSTR bstrSessionId, void* lockId, IServer* pServer, ICustomSession* pCustomSession)
{
	//create page handler for page events
	CComPtr<IPageHandler> piPageHandler;
	TestHR(CreatePageHandler(pServer, &piPageHandler));

	//register notify
	TestHR(piPageHandler->RegisterNotifyOnEndPage(this, bstrSessionId, lockId));
	
	//persist session in memory until the end of request
	m_Sessions.SetAt(bstrSessionId, pCustomSession);

	return S_OK;
}

STDMETHODIMP CSessionManager::CreatePageHandler(IServer* server, IPageHandler** pageHandler)
{
	CComPtr<IDispatch> piDispatch;
	
	TestHR(server->CreateObject(m_PageHandlerProgId, &piDispatch));

	TestHR(piDispatch->QueryInterface<IPageHandler>(pageHandler));
	
	return S_OK;
}

STDMETHODIMP CSessionManager::OnEndPage(BSTR bstrSessionId, void* lockId)
{
	HRESULT hr = S_OK;

	CComPtr<ICustomSession> piCustomSession;

	if (m_Sessions.Lookup(bstrSessionId, piCustomSession))
	{
		m_Sessions.RemoveKey(bstrSessionId);

		hr = SaveSessionState(bstrSessionId, lockId, piCustomSession);
	}

	return hr;
}

STDMETHODIMP CSessionManager::LoadSessionState(BSTR bstrSessionId, BOOL bReadOnly, void** lockId, ICustomSession* piCustomSession)
{
	CComPtr<IPersistStreamInit> piPersist;
	TestHR(piCustomSession->QueryInterface<IPersistStreamInit>(&piPersist));
	TestHR(piPersist->InitNew());
	
	long lLockAge;
	VARIANT_BOOL bLocked;

	CComPtr<IStream> piStream;
	piStream.Attach(SHCreateMemStream(NULL, 0));

	//get item
	TestHR(m_piStoreProvider->GetItem(bstrSessionId, bReadOnly ? EXC_MODE_NONE : EXC_MODE_ACQUIRE, piStream, lockId, &lLockAge, &bLocked));

	//move seek pointer to start of stream
	LARGE_INTEGER liBeggining = { 0 };
	piStream->Seek(liBeggining, STREAM_SEEK_SET, NULL);

	//load persisted state
	TestHR(piPersist->Load(piStream));
		
	return S_OK;
}

STDMETHODIMP CSessionManager::SaveSessionState(BSTR bstrSessionId, void* lockId, ICustomSession* piCustomSession)
{
	//get IPersistStreamInit interface
	
	CComQIPtr<IPersistStreamInit> piPersist(piCustomSession);
	
	if (!piPersist)
	{
		return E_NOINTERFACE;
	}

	//create memory stream
	CComPtr<IStream> piStream;
	piStream.Attach(SHCreateMemStream(NULL, 0));

	if (!piStream)
	{
		return E_FAIL;
	}

	long lTimeout = 0;

	TestHR(piCustomSession->get_Timeout(&lTimeout));

	//persist session to stream
	TestHR(piPersist->Save(piStream, TRUE));

	//move seek pointer to start of stream
	LARGE_INTEGER liBegining = { 0 };
	
	TestHR(piStream->Seek(liBegining, STREAM_SEEK_SET, NULL));

	TestHR(m_piStoreProvider->SetItem(bstrSessionId, lTimeout, lockId, piStream));

	return S_OK;
}

STDMETHODIMP CSessionManager::ReadSessionCookie(IRequest* pRequest, BSTR* pBstrSessionId)
{
	CComPtr<IRequestDictionary> piReqCookies;

	TestHR(pRequest->get_Cookies(&piReqCookies));

	CComVariant vtCookieDict;

	TestHR(piReqCookies->get_Item(CComVariant("ASPCustomSession"), &vtCookieDict));

	CComPtr<IReadCookie> piReadCookie;
	
	piReadCookie = (IReadCookie*)vtCookieDict.pdispVal;

	CComVariant vtCookieKey;
	vtCookieKey.vt = VT_ERROR;
	vtCookieKey.scode = DISP_E_PARAMNOTFOUND;

	CComVariant vtCookieVal;

	TestHR(piReadCookie->get_Item(vtCookieKey, &vtCookieVal));
	
	TestHR(vtCookieVal.CopyTo(pBstrSessionId));

	return S_OK;
}

STDMETHODIMP CSessionManager::WriteSessionCookie(IResponse* pResponse, BSTR bstrSessionId)
{
	CComPtr<IRequestDictionary> piResDictionary;
	
	TestHR(pResponse->get_Cookies(&piResDictionary));
	
	CComVariant vtCookieName("ASPCustomSession");
	CComVariant vtCookieDict;
	CComPtr<IWriteCookie> piWriteCookie;

	piResDictionary->get_Item(vtCookieName, &vtCookieDict);

	piWriteCookie = (IWriteCookie*)(vtCookieDict.pdispVal);

	CComVariant vtCookieKey;
	vtCookieKey.vt = VT_ERROR;
	vtCookieKey.scode = DISP_E_PARAMNOTFOUND;

	TestHR(piWriteCookie->put_Item(vtCookieKey, bstrSessionId));

	return S_OK;
}
