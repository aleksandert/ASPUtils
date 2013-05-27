#pragma once

#include "asptlb.h"

//  Which dictionary type a particular object is (corresponds to collection objects) 
typedef enum  
{		  
	QUERY_STRING_TYPE,				 
	FORM_TYPE, 
	REQUEST_COOKIE_TYPE,	 
	RESPONSE_COOKIE_TYPE, 
	SERVER_VARIABLE_TYPE, 
	EMPTY_TYPE						// No data associated with object. 
									// This is used for the empty string object. 
} DICT_TYPE; 


#include "request.h"
//#include "RequestDictionary.h"

