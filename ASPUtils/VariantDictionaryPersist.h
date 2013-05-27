
#pragma once
#ifndef _VARIANTDICTIONARYPERSIST_H_
#define _VARIANTDICTIONARYPERSIST_H_

#include "Persist.h"
#include "VariantDictionaryDef.h"

#include "ASPUtils_i.h"

using namespace VariantDictionaryDef;
using namespace ATL;

template <>
class _Persist<ItemType>
{
public:
	static HRESULT Load(ItemType *pT, LPSTREAM pStm)	
	{
		TestHR(_Persist<VARIANT>::Load(const_cast<KeyType*>(&pT->first), pStm));
		TestHR(_Persist<VARIANT>::Load(&pT->second, pStm));

		return S_OK;
	}

	static HRESULT Save(ItemType *pT, LPSTREAM pStm)	
	{
		TestHR(_Persist<VARIANT>::Save(const_cast<KeyType*>(&pT->first), pStm));
		TestHR(_Persist<VARIANT>::Save(&pT->second, pStm));

		return S_OK;
	}

	static HRESULT GetSizeMax(ItemType *pT, ULARGE_INTEGER *pcbSize)	
	{
		ULARGE_INTEGER secSize = {0};

		TestHR(_Persist<VARIANT>::GetSizeMax(const_cast<KeyType*>(&pT->first), pcbSize));
		TestHR(_Persist<VARIANT>::GetSizeMax(&pT->second, &secSize));

		pcbSize->QuadPart += secSize.QuadPart;

		return S_OK;
	}
	static void init(ItemType*) {}
	static void destroy(ItemType *pT) 
	{
		
		(pT->second).Clear();
	}
	
}; 

template<>
class _Persist<ContainerType>
{
public:
	static HRESULT Load(LPSTREAM pStm, ContainerType *pColl)
	{
		ATLASSERT(pStm != NULL);
		ATLASSERT(pColl != NULL);

		ContainerType::iterator it;

		// Clear the collection properly.
		if (!pColl->empty())
		{
			for (it = pColl->begin(); it != pColl->end(); it++)
				_Persist<ItemType>::destroy(&*it);
			pColl->clear();
		}

		// Load the version number.
		DWORD dwVersion(0);
		TestHR(pStm->Read(&dwVersion, sizeof(DWORD), NULL))
		if (dwVersion > _PERSIST_VER)
			return E_FAIL; // Unsupported version.

		// Load the number of items in the collection
		ContainerType::size_type size(0);
		TestHR(pStm->Read(&size, sizeof(ContainerType::size_type), NULL))

		// Load the collection
		HRESULT hr(S_OK);
		ItemType item; // Temporary item
		for (ContainerType::size_type i(0); i < size; i++)
		{
			_Persist<ItemType>::init(&item);
			hr = _Persist<ItemType>::Load(&item, pStm);
			if (FAILED(hr))
			{
				// Clear the data properly.
				_Persist<ItemType>::destroy(&item);
				for (it = pColl->begin(); it != pColl->end(); it++)
					_Persist<ItemType>::destroy(&*it);
				pColl->clear();
				return hr;
			}
			it = pColl->insert(pColl->begin(), item);
			_Persist<ItemType>::destroy(&item);
		}
	
		return hr;
	}

	static HRESULT Save(LPSTREAM pStm, BOOL /*fClearDirty*/, ContainerType *pColl)
	{ 
		ATLASSERT(pStm != NULL);
		ATLASSERT(pColl != NULL);

		// Save the version number.
		DWORD dwVersion = _PERSIST_VER;
		TestHR(pStm->Write(&dwVersion, sizeof(DWORD), NULL))

		// Save the number of items in the collection.
		ContainerType::size_type size(pColl->size());
		TestHR(pStm->Write(&size, sizeof(ContainerType::size_type), NULL))

		// Save the collection.
		ContainerType::reverse_iterator it;
		for (it = pColl->rbegin(); it != pColl->rend(); it++)
			TestHR(_Persist<ItemType>::Save(&*it, pStm))
	
		return S_OK;
	}


	static HRESULT GetSizeMax(ULARGE_INTEGER FAR *pcbSize, ContainerType *pColl)
	{

		ATLASSERT(pcbSize != NULL);
		ATLASSERT(pColl != NULL);

		// The version number.
		pcbSize->QuadPart = sizeof(DWORD);

		// The number of items in the collection.
		pcbSize->QuadPart += sizeof(ContainerType::size_type);

		// The collection.
		ULARGE_INTEGER ulnItemSize;
		ContainerType::iterator it = pColl->begin();
		for (it; it != pColl->end(); it++)
		{
			ulnItemSize.QuadPart = 0;
			TestHR(_Persist<ItemType>::GetSizeMax(&*it, &ulnItemSize))
			pcbSize->QuadPart += ulnItemSize.QuadPart;
		}

		return S_OK;
	}
};

#endif // !_VARIANTDICTIONARYPERSIST_H_