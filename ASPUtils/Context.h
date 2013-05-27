
#pragma once
#ifndef _CONTEXT_H_
#define _CONTEXT_H_

//#include "ASPTest_i.h"
#include <Mtx.h>
#include <InitGuid.h>
#include <asptlb.h>         // Active Server Pages Definitions

using namespace ATL;

class CContext
{
private:
	CComPtr<IRequest>			m_piRequest;			//Request Object
	CComPtr<IResponse>			m_piResponse;			//Response Object
	CComPtr<ISessionObject>		m_piSession;			//Session Object
	CComPtr<IServer>			m_piServer;				//Server Object
	CComPtr<IApplicationObject> m_piApplication;		//Application Object

public:
	enum {
		get_Server		= 0x0001,
		get_Response	= 0x0002,
		get_Request		= 0x0004,
		get_Session		= 0x0008,
		get_Application	= 0x0010,
		get_All         = 0xFFFF
	};
	
	HRESULT	            Init( DWORD );

	IRequest*			Request(){ _ASSERT(m_piRequest!=NULL); return m_piRequest; }
	IResponse*			Response(){ _ASSERT(m_piResponse!=NULL); return m_piResponse; }
	ISessionObject*		Session(){ _ASSERT(m_piSession!=NULL); return m_piSession; }
	IServer*			Server(){ _ASSERT(m_piServer!=NULL); return m_piServer; }
	IApplicationObject*	Application(){ _ASSERT(m_piApplication!=NULL); return m_piApplication; }

	static HRESULT		GetServerObject( IGetContextProperties*, BSTR, const IID&, void** );


};


#endif	// !_CONTEXT_H_
