// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Define the OSAPI+ required libraries (C++ and OSAPI C)
//
// *****************************************************************************************

#ifndef OSAPI_BASELINE_LIBRARIES_HH_
#define OSAPI_BASELINE_LIBRARIES_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

#ifdef OSAPI_BASELINE_LIBRARY_C

  // OSAPI C headers only for the compilation of the OSAPI C++ library itself
  #include "general/general.h"

#endif

// Own module headers
#include "general/libraries.hh"
#include "general/mappings/release.hh"
#include "general/mappings/version.hh"


#ifndef OSAPI_BASELINE_LIBRARIES_DISABLE


// *****************************************************************************************
//
// Section: OSAPI C Library Baseline definition (Only relevant for the compilation of the
//			OSAPI C++ library itself
//
// *****************************************************************************************

#ifdef OSAPI_BASELINE_LIBRARY_C

  static_assert( e_osapi_release >= OSAPIC_REQUIRED_RELEASE, 	"Baseline error: OSAPI C Release" );
  static_assert( e_osapi_version >= OSAPIC_REQUIRED_VERSION, 	"Baseline error: OSAPI C Version" );

#endif

namespace osapi
{

// *****************************************************************************************
//
// Section: C++ Library Baseline definition
//
// *****************************************************************************************


static_assert( CPP_LIBRARY_RELEASE >= CPP_TARGET_RELEASE, 	"Baseline error: OSAPI C++ Release" );


}	// End of namespace "osapi"

#endif	// If baseline for libraries is not disabled

#endif /* OSAPI_BASELINE_LIBRARIES_HH_ */
