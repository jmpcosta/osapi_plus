// **************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	General C library definitions
//
// **************************************************************************************************

#ifndef OSAPI_LIBRARIES_HH_
#define OSAPI_LIBRARIES_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

#include "general/mappings/release.hh"
#include "general/mappings/version.hh"

// *****************************************************************************************
//
// Section: Define library: GNU Lib C++
//
// *****************************************************************************************

namespace osapi
{

// Previous versions of the GNU C++ library didn't had a release number
// https://gcc.gnu.org/onlinedocs/libstdc++/manual/using_macros.html
#ifdef _GLIBCXX_RELEASE

  /// @brief Define name of Standard C++ library
  constexpr const char * CPP_LIBRARY_NAME	= "libstdc++.so";

  // Map specific GNU C++ library versions to internal versions
  #define	CPP_LIBRARY_RELEASE			_GLIBCXX_RELEASE

	// Define C++ Library baseline: https://gcc.gnu.org/projects/cxx-status.html
	// Need to better fine tune the version according to the required APIs:
	#define CPP_TARGET_RELEASE			5

// When compiling with g++ the C++ library version is the same as the version of the compiler
#elif defined( __GNUC__ )

  // Define name of Standard C++ library
  constexpr const char * CPP_LIBRARY_NAME	= "libstdc++.so";

  // Map specific GNU C++ library versions to internal versions
  #define CPP_LIBRARY_RELEASE			__GNUC__

  // Define C++ Library baseline:
  #define CPP_TARGET_RELEASE			5


// *****************************************************************************************
// Unknown language - Exit
// *****************************************************************************************


#else
  #error	"C++ Library: Unknown."

#endif	// Language definitions


}	// End of namespace "osapi"

#endif /* OSAPI_LIBRARIES_HH_ */
