// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Define the compiler baseline
//
// *****************************************************************************************

#ifndef OSAPI_BASELINE_COMPILER_HH_
#define OSAPI_BASELINE_COMPILER_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

#include "general/compiler.hh"
#include "general/language.hh"


// *****************************************************************************************
//
// Section: Compiler Baseline definition
//
// *****************************************************************************************

#ifndef OSAPI_BASELINE_COMPILER_DISABLE

static_assert( OSAPI_COMPILER != OSAPI_COMPILER_UNKNOWN, 	"Baseline error: Unknown compiler" );

// GNU version 6.5 (at least), supports C11
#if OSAPI_COMPILER == OSAPI_COMPILER_GNU

  static_assert( OSAPI_COMPILER_VERSION_MAJOR >= 6 , 										" Baseline error: Compiler major version bellow requirements" 	);
  static_assert( OSAPI_COMPILER_VERSION_MAJOR > 7 || OSAPI_COMPILER_VERSION_MINOR >= 5 , 	" Baseline error: Compiler version bellow requirements" 		);

#elif  OSAPI_COMPILER == OSAPI_COMPILER_CLANG

  // What is the baseline for CLANG?
#endif

#endif	// If compiler baseline is not disabled

#endif /* OSAPI_BASELINE_COMPILER_HH_ */
