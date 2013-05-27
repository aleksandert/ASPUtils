// ScriptParser.cpp : Implementation of CScriptParser

#include "stdafx.h"
#include "ScriptParser.h"

// CScriptParser

STDMETHODIMP CScriptParser::Initialize()
{
	HRESULT hr = CoInitialize(NULL);

	//MSScriptControl::IScriptControlPtr m_piScriptControl(__uuidof(MSScriptControl::ScriptControl));
	
//	IRequest* request = new CRequest();

	//m_piScriptControl->AddObject(""

	return S_OK;
}

STDMETHODIMP CScriptParser::Terminate()
{

	m_piScriptControl.Release();

	CoUninitialize();

	return S_OK;
}

/// <summary>
///	Parses ASP script.
/// </summary>
/// <param name="script">Script to parse.</param>
/// <param name="pExpires">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CScriptParser::ParseScript(VARIANT script, VARIANT* pResult)
{
	
	return S_OK;
}

/// <summary>
///	Parses ASP file.
/// </summary>
/// <param name="script">File to parse.</param>
/// <param name="pExpires">Variable that receives the result.</param>
/// <returns>Returns <b>S_OK</b> on success, or an error <b>HRESULT</b> on failure.</returns>
STDMETHODIMP CScriptParser::ParseFile(VARIANT path, VARIANT* pResult)
{
	return S_OK;
}