// **************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General language definitions
//		The purpose is to wrapper C++ definitions to avoid spreading these in every module
//
// **************************************************************************************************

#ifndef OSAPI_LANGUAGE_HH_
#define OSAPI_LANGUAGE_HH_

// *****************************************************************************************
//
// Section: Define language settings
//
// *****************************************************************************************

#ifdef __cplusplus

// *****************************************************************************************
// C++ definitions
// *****************************************************************************************

namespace osapi
{

#define OSAPI_LANGUAGE_VERSION		__cplusplus

}	// End of namespace "osapi"

#elif	defined (__STDC__)			// C code

// *****************************************************************************************
// C definitions
// *****************************************************************************************
#error "C language is not supported"

#else

// *****************************************************************************************
// Unknown language - Exit
// *****************************************************************************************

#error	"Unknown programming language."

#endif	// Language definitions

#endif /* OSAPI_LANGUAGE_HH_ */
