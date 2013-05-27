// ASPContext.cpp : Implementation of CASPContext

#include "stdafx.h"

#include "ASPContext.h"


// CASPContext

HRESULT CASPContext::GetServerObject(IGetContextProperties*	pProps,	BSTR bstrObjName, const IID& iid, void** ppObj)
{
	HRESULT hr = E_FAIL;
	_ASSERT( pProps );
	_ASSERT( bstrObjName );
	_ASSERT( ppObj );
	if ( pProps && bstrObjName && ppObj )
	{
		*ppObj = NULL;
		CComVariant vt;
		if ( !FAILED( pProps->GetProperty( bstrObjName, &vt ) ) )
		{
			if ( V_VT(&vt) == VT_DISPATCH )
			{
				IDispatch* pDispatch = V_DISPATCH(&vt);
				if ( pDispatch )
				{
					hr = pDispatch->QueryInterface( iid, ppObj );
				}
			}
		}
	}
	return hr;
}

HRESULT CASPContext::Init(DWORD	dwFlags) // which instrinsics to initialize
{
	HRESULT hr = E_FAIL;
	CComPtr<IObjectContext> pObjContext;

	hr = GetObjectContext( &pObjContext );
	if ( !FAILED( hr ) )
	{
		CComPtr<IGetContextProperties> pProps;
		hr = pObjContext->QueryInterface( IID_IGetContextProperties, (void**)&pProps );
		if ( !FAILED( hr ) )
		{
			CComBSTR bstrObj;
			if ( dwFlags & get_Request )
			{
				bstrObj = "Request";
				hr = GetServerObject( pProps, bstrObj, IID_IRequest, (void**)&m_piRequest );
			}
			if ( !FAILED(hr) && ( dwFlags & get_Response ) )
			{
				bstrObj = "Response";
				hr = GetServerObject( pProps, bstrObj, IID_IResponse, (void**)&m_piResponse );
			}

			if ( !FAILED(hr) && ( dwFlags & get_Session ) )
			{
				bstrObj = "Session";
				hr = GetServerObject( pProps, bstrObj, IID_ISessionObject, (void**)&m_piSession );
			}

			if ( !FAILED(hr) && ( dwFlags & get_Server ) )
			{
				bstrObj = "Server";
				hr = GetServerObject( pProps, bstrObj, IID_IServer, (void**)&m_piServer );
			}

			if ( !FAILED(hr) && ( dwFlags & get_Application ) )
			{
				bstrObj = "Application";
				hr = GetServerObject( pProps, bstrObj, IID_IApplicationObject, (void**)&m_piApplication );
			}
		}
	}
	return hr;
}
