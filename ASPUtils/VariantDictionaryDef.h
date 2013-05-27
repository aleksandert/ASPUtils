
#pragma once
#ifndef _VARIANTDICTIONARYDEF_H_
#define _VARIANTDICTIONARYDEF_H_

#include "resource.h"       // main symbols

namespace VariantDictionaryDef
{
	// We always need to provide the following information
	typedef std::map<CComVariant, CComVariant>							ContainerType;
	typedef VARIANT														ExposedType;
	typedef IEnumVARIANT												EnumeratorInterface;
	typedef IVariantDictionary											CollectionInterface;
	typedef ContainerType::value_type									ItemType;
	typedef ContainerType::key_type										KeyType;
	typedef ContainerType::mapped_type									MappedType;
};

#endif // !_VARIANTDICTIONARYDEF_H_