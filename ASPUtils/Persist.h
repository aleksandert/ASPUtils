// Persist.h : Declaration of the generic CPersist 

#ifndef _PERSIST_H_
#define _PERSIST_H_

#include "stdafx.h"       // main symbols

#define _PERSIST_VER 0x0100


typedef enum
	{
		NONE,
		PERSIST_STREAM_INIT,
		PERSIST_STREAM
	} _InterfacePersistMethod;

// _Persist<>
// The basic persistence policy class.
template <class T>
class _Persist
{
public:
	static HRESULT Load(T *pT, LPSTREAM pStm) 
	{
		return pStm->Read(pT, sizeof(T), NULL);
	}
	static HRESULT Save(T *pT, LPSTREAM pStm)	
	{
		return pStm->Write(pT, sizeof(T), NULL);
	}
	static HRESULT GetSizeMax(T *pT, ULARGE_INTEGER *pcbSize)	
	{
		pcbSize->QuadPart = sizeof(T); 
		return S_OK;
	}
	static void init(T*) {}
	static void destroy(T*) {}
}; // class _Persist


template<>
class _Persist<IUnknown>
{
public:
	static HRESULT Load(IUnknown **pT, LPSTREAM pStm)
	{
		ATLASSERT(pT != NULL && *pT == NULL);
		ATLASSERT(pStm != NULL);
		
		_InterfacePersistMethod persistMethod(NONE);

		// First read the persisting method.
		TestHR(pStm->Read(&persistMethod, sizeof(_InterfacePersistMethod), NULL));

		switch (persistMethod)
		{
			// No Interface.
			case NONE:
				*pT = NULL;
				break;

			// IPersistStreamInit
			case PERSIST_STREAM_INIT:
				{
					// Can't use the V-Table trick here.
					CLSID clsid;
					CComPtr<IPersistStreamInit> ccpIPSI;
					TestHR(ReadClassStm(pStm, &clsid));
					TestHR(ccpIPSI.CoCreateInstance(clsid));
					TestHR(ccpIPSI->Load(pStm));
					TestHR(ccpIPSI->QueryInterface(__uuidof(IUnknown), (void**)pT));
				}
				break;

			// IPersistStream
			case PERSIST_STREAM:
				TestHR(OleLoadFromStream(pStm, __uuidof(IUnknown), (void**)pT))
				break;

			// Unsupported method.
			default:
				return E_FAIL;
		}
		return S_OK;
	}

	static HRESULT Save(IUnknown **pT, LPSTREAM pStm)
	{
		ATLASSERT(pT != NULL);
		ATLASSERT(pStm != NULL);

		_InterfacePersistMethod persistMethod(NONE);
	
		if ( *pT == NULL ) // Nothing to persist.
			return pStm->Write(&persistMethod, sizeof(_InterfacePersistMethod), NULL);

		CComPtr<IPersistStream> ccpIPS;
		CComQIPtr<IPersistStreamInit> ccpIPSI(*pT);

		if ( ccpIPSI ) // Look for IPersistStreamInit.
		{
			persistMethod = PERSIST_STREAM_INIT;
			ccpIPS = reinterpret_cast<IPersistStream*>(ccpIPSI.p); // Same V-Table.
		}
		else // Look for IPersistStream.
		{
			CComQIPtr<IPersistStream> ccpIPS2(*pT);
			if ( ccpIPS2 )
			{
				persistMethod = PERSIST_STREAM;
				ccpIPS.Attach( ccpIPS2.Detach() );
			}
		}
	
		// Commit IPersistStream / IPersistStreamInit to stream.
		if ( ccpIPS )
		{
			TestHR(pStm->Write(&persistMethod, sizeof(_InterfacePersistMethod), NULL))
			return OleSaveToStream(ccpIPS, pStm);
		}
	
		// No operation possible.
		return STG_E_CANTSAVE;
	}


	static HRESULT GetSizeMax(IUnknown **pT, ULARGE_INTEGER *pcbSize)
	{
		ATLASSERT(pT != NULL);
		ATLASSERT(pcbSize != NULL);

		if ( *pT == NULL ) // Nothing to persist.
		{
			pcbSize->QuadPart = sizeof(_InterfacePersistMethod);
			return S_OK;
		}

		CComPtr<IPersistStream> ccpIPS;
		CComQIPtr<IPersistStreamInit> ccpIPSI(*pT);

		if ( ccpIPSI ) // Look for IPersistStreamInit.
			ccpIPS = reinterpret_cast<IPersistStream*>(ccpIPSI.p); // Same V-Table
		else // Look for IPersistStream.
		{
			CComQIPtr<IPersistStream> ccpIPS2(*pT);
			if ( ccpIPS2 )
				ccpIPS.Attach( ccpIPS2.Detach() );
		}
	
		// Get the IPersistStream / IPersistStreamInit required size.
		if ( ccpIPS )
		{
			TestHR(ccpIPS->GetSizeMax(pcbSize))
			pcbSize->QuadPart += sizeof(CLSID) + sizeof(_InterfacePersistMethod);
			return S_OK;
		}
	
		// No operation possible.
		return STG_E_CANTSAVE;
	}
};


template<>
class _Persist<IDispatch>
{
public:
	static HRESULT Load(IDispatch **pT, LPSTREAM pStm)
	{
		ATLASSERT(pT != NULL && *pT == NULL);
		ATLASSERT(pStm != NULL);
		
		_InterfacePersistMethod persistMethod(NONE);

		// First read the persisting method.
		TestHR(pStm->Read(&persistMethod, sizeof(_InterfacePersistMethod), NULL));

		switch (persistMethod)
		{
			// No Interface.
			case NONE:
				*pT = NULL;
				break;

			// IPersistStreamInit
			case PERSIST_STREAM_INIT:
				{
					// Can't use the V-Table trick here.
					CLSID clsid;
					CComPtr<IPersistStreamInit> ccpIPSI;
					TestHR(ReadClassStm(pStm, &clsid));
					TestHR(ccpIPSI.CoCreateInstance(clsid));
					TestHR(ccpIPSI->Load(pStm));
					TestHR(ccpIPSI->QueryInterface(__uuidof(IDispatch), (void**)pT));
				}
				break;

			// IPersistStream
			case PERSIST_STREAM:
				TestHR(OleLoadFromStream(pStm, __uuidof(IDispatch), (void**)pT))
				break;

			// Unsupported method.
			default:
				return E_FAIL;
		}
		return S_OK;
	}

	static HRESULT Save(IDispatch **pT, LPSTREAM pStm)
	{
		ATLASSERT(pT != NULL);
		ATLASSERT(pStm != NULL);

		_InterfacePersistMethod persistMethod(NONE);
	
		if ( *pT == NULL ) // Nothing to persist.
			return pStm->Write(&persistMethod, sizeof(_InterfacePersistMethod), NULL);

		CComPtr<IPersistStream> ccpIPS;
		CComQIPtr<IPersistStreamInit> ccpIPSI(*pT);

		if ( ccpIPSI ) // Look for IPersistStreamInit.
		{
			persistMethod = PERSIST_STREAM_INIT;
			ccpIPS = reinterpret_cast<IPersistStream*>(ccpIPSI.p); // Same V-Table.
		}
		else // Look for IPersistStream.
		{
			CComQIPtr<IPersistStream> ccpIPS2(*pT);
			if ( ccpIPS2 )
			{
				persistMethod = PERSIST_STREAM;
				ccpIPS.Attach( ccpIPS2.Detach() );
			}
		}
	
		// Commit IPersistStream / IPersistStreamInit to stream.
		if ( ccpIPS )
		{
			TestHR(pStm->Write(&persistMethod, sizeof(_InterfacePersistMethod), NULL))
			return OleSaveToStream(ccpIPS, pStm);
		}
	
		// No operation possible.
		return STG_E_CANTSAVE;
	}


	static HRESULT GetSizeMax(IDispatch **pT, ULARGE_INTEGER *pcbSize)
	{
		ATLASSERT(pT != NULL);
		ATLASSERT(pcbSize != NULL);

		if ( *pT == NULL ) // Nothing to persist.
		{
			pcbSize->QuadPart = sizeof(_InterfacePersistMethod);
			return S_OK;
		}

		CComPtr<IPersistStream> ccpIPS;
		CComQIPtr<IPersistStreamInit> ccpIPSI(*pT);

		if ( ccpIPSI ) // Look for IPersistStreamInit.
			ccpIPS = reinterpret_cast<IPersistStream*>(ccpIPSI.p); // Same V-Table
		else // Look for IPersistStream.
		{
			CComQIPtr<IPersistStream> ccpIPS2(*pT);
			if ( ccpIPS2 )
				ccpIPS.Attach( ccpIPS2.Detach() );
		}
	
		// Get the IPersistStream / IPersistStreamInit required size.
		if ( ccpIPS )
		{
			TestHR(ccpIPS->GetSizeMax(pcbSize))
			pcbSize->QuadPart += sizeof(CLSID) + sizeof(_InterfacePersistMethod);
			return S_OK;
		}
	
		// No operation possible.
		return STG_E_CANTSAVE;
	}
};


template <>
class _Persist<BSTR>
{
public:
	static HRESULT Load(BSTR *pT, LPSTREAM pStm)
	{
		// Based on CComBSTR::ReadFromStream.
		ATLASSERT(pT != NULL);
		ATLASSERT(pStm != NULL);

		CComBSTR bstrRead;
		TestHR(bstrRead.ReadFromStream(pStm))
		*pT = bstrRead.Detach();
		return S_OK;
	}

	static HRESULT Save(BSTR *pT, LPSTREAM pStm)
	{
		// Based on CComBSTR::WriteToStream.
		ATLASSERT(pT != NULL);
		ATLASSERT(pStm != NULL);

		CComBSTR bstrWrite;
		bstrWrite.Attach(*pT);
		TestHR(bstrWrite.WriteToStream(pStm))
		bstrWrite.Detach();
		return S_OK;
	}


	static HRESULT GetSizeMax(BSTR *pT, ULARGE_INTEGER *pcbSize)
	{
		// Based on CComBSTR::WriteToStream.
		ATLASSERT(pT != NULL);
		ATLASSERT(pcbSize != NULL);

		pcbSize->QuadPart = sizeof(ULONG);
		pcbSize->QuadPart += *pT ? SysStringByteLen(*pT) + sizeof(OLECHAR) : 0;
		return S_OK;
	}
};

template <>
class _Persist<VARIANT>
{
public:
	static HRESULT Load(VARIANT *pT, LPSTREAM pStm)
	{
		// Based on CComVariant::ReadFromStream.
		ATLASSERT(pT != NULL);
		ATLASSERT(pStm != NULL);

		TestHR(VariantClear(pT))

		VARTYPE vtRead;
		TestHR(pStm->Read(&vtRead, sizeof(VARTYPE), NULL))

		int cbRead(0);
		pT->vt = vtRead;
		pT->punkVal = NULL; // Set internal value to 0.

		switch (vtRead)
		{
			case VT_UNKNOWN:
				return _Persist<IUnknown>::Load( &pT->punkVal, pStm );
			case VT_DISPATCH:
				return _Persist<IDispatch>::Load( &pT->pdispVal, pStm );
			case VT_UI1:
			case VT_I1:
				cbRead = sizeof(BYTE);
				break;
			case VT_I2:
			case VT_UI2:
			case VT_BOOL:
				cbRead = sizeof(short);
				break;
			case VT_I4:
			case VT_UI4:
			case VT_R4:
			case VT_INT:
			case VT_UINT:
			case VT_ERROR:
				cbRead = sizeof(long);
				break;
			case VT_R8:
			case VT_CY:
			case VT_DATE:
				cbRead = sizeof(double);
				break;
			default:
				break;
		}

		if (cbRead != 0)
			TestHR(pStm->Read((void*) &pT->bVal, cbRead, NULL))
		else
		{
			TestHR(_Persist<BSTR>::Load(&pT->bstrVal, pStm))
			pT->vt = VT_BSTR;
			if (vtRead != VT_BSTR)
				return VariantChangeType(pT, pT, VARIANT_NOVALUEPROP, vtRead);
		}

		return S_OK;
	}

	static HRESULT Save(VARIANT *pT, LPSTREAM pStm)
	{
		// Based on CComVariant::WriteToStream.
		ATLASSERT(pT != NULL);
		ATLASSERT(pStm != NULL);

		TestHR(pStm->Write(&pT->vt, sizeof(VARTYPE), NULL))

		int cbWrite = 0;
		switch (pT->vt)
		{
			case VT_UNKNOWN:
				return _Persist<IUnknown>::Save(&pT->punkVal, pStm);
			case VT_DISPATCH:
				return _Persist<IDispatch>::Save(&pT->pdispVal, pStm);
			case VT_UI1:
			case VT_I1:
				cbWrite = sizeof(BYTE);
				break;
			case VT_I2:
			case VT_UI2:
			case VT_BOOL:
				cbWrite = sizeof(short);
				break;
			case VT_I4:
			case VT_UI4:
			case VT_R4:
			case VT_INT:
			case VT_UINT:
			case VT_ERROR:
				cbWrite = sizeof(long);
				break;
			case VT_R8:
			case VT_CY:
			case VT_DATE:
				cbWrite = sizeof(double);
				break;
			default:
				break;
		}
		if (cbWrite != 0)
			return pStm->Write((void*) &pT->bVal, cbWrite, NULL);

		if (pT->vt != VT_BSTR)
		{
			CComVariant varBSTR;
			TestHR(VariantChangeType(&varBSTR, pT, VARIANT_NOVALUEPROP, VT_BSTR))
			return _Persist<BSTR>::Save(&varBSTR.bstrVal, pStm);
		}
		else
			return _Persist<BSTR>::Save(&pT->bstrVal, pStm);
	}

	static HRESULT GetSizeMax(VARIANT *pT, ULARGE_INTEGER *pcbSize)	
	{
		// Based on CComVariant::WriteToStream.
		ATLASSERT(pT != NULL);
		ATLASSERT(pcbSize != NULL);

		switch (pT->vt)
		{
			case VT_UNKNOWN:
				TestHR(_Persist<IUnknown>::GetSizeMax(&pT->punkVal, pcbSize))
				break;
			case VT_DISPATCH:
				TestHR((_Persist<IDispatch>::GetSizeMax(&pT->pdispVal, pcbSize)))
				break;
			case VT_UI1:
			case VT_I1:
				pcbSize->QuadPart = sizeof(BYTE);
				break;
			case VT_I2:
			case VT_UI2:
			case VT_BOOL:
				pcbSize->QuadPart = sizeof(short);
				break;
			case VT_I4:
			case VT_UI4:
			case VT_R4:
			case VT_INT:
			case VT_UINT:
			case VT_ERROR:
				pcbSize->QuadPart = sizeof(long);
				break;
			case VT_R8:
			case VT_CY:
			case VT_DATE:
				pcbSize->QuadPart = sizeof(double);
				break;
			default:
				{
					if (pT->vt != VT_BSTR)
					{
						CComVariant varBSTR;
						TestHR(VariantChangeType(&varBSTR, pT, VARIANT_NOVALUEPROP, VT_BSTR))
						return _Persist<BSTR>::GetSizeMax(&varBSTR.bstrVal, pcbSize);
					}
					else
						return _Persist<BSTR>::GetSizeMax(&pT->bstrVal, pcbSize);
				}
				break;
		}

		pcbSize->QuadPart += sizeof(VARTYPE);

		return S_OK;
	}
};
#endif // !_PERSIST_H_