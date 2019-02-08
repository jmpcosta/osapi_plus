// ******************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General compiler definitions
//		The purpose is to wrapper compiler definitions to avoid spreading these in every module
//
// ******************************************************************************************************

#ifndef OSAPI_COMPILER_HH_
#define OSAPI_COMPILER_HH_

// *****************************************************************************************
//
// Section: Define list of compilers
//
// *****************************************************************************************

namespace osapi
{

// List of compilers
#define OSAPI_COMPILER_GNU			1
#define OSAPI_COMPILER_CLANG		2
#define OSAPI_COMPILER_UNKNOWN		0


// *****************************************************************************************
//
// Section: Define compiler settings
//
// *****************************************************************************************

#ifdef __clang__

// *****************************************************************************************
// CLANG Compiler settings. CLANG must be before GCC since it exports the same gcc macros
// *****************************************************************************************

  #define OSAPI_COMPILER 					OSAPI_COMPILER_CLANG
  #define OSAPI_COMPILER_VERSION_MAJOR		__clang_major__
  #define OSAPI_COMPILER_VERSION_MINOR		__clang_minor__


// *****************************************************************************************
// GNU Compiler settings
// *****************************************************************************************
#elif __GNUC__
  #define OSAPI_COMPILER 					OSAPI_COMPILER_GNU
  #define OSAPI_COMPILER_VERSION_MAJOR		__GNUC__
  #define OSAPI_COMPILER_VERSION_MINOR		__GNUC_MINOR__

#else
  #define OSAPI_COMPILER		OSAPI_COMPILER_UNKNOWN
#endif


}	// End of namespace "osapi"

#endif /* OSAPI_COMPILER_HH_ */
