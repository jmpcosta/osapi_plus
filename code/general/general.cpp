// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Implementation of the OSAPI+ library interface
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "general/general.h"

// Import C++ system headers
#include <map>
#include <iostream>

// Import own module declarations
#include "general/library.hh"
#include "general/mappings/release.hh"
#include "general/mappings/version.hh"

// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{

std::map<int, const char*> releaseMap = { { library_release, "0" } };
std::map<int, const char*> versionMap = { { library_version, "5" } };


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


unsigned long library::getRelease() noexcept
{
 return library_release;
}

unsigned long library::getVersion() noexcept
{
 return library_version;
}

const char * library::getReleaseString() noexcept
{
 return releaseMap[ library_release ];
}

const char * library::getVersionString() noexcept
{
 return versionMap[ library_version ];
}

// To check the runtime baseline:
bool library::verifyBaseline() noexcept
{
 // First check that the OSAPI C library runtime baseline is correct
 if( ! osapi_verify_baseline() ) return false;

 // Second, verify the C++ library
 if( ! library::cppBaseline() ) return false;

 return true;
}

}	// End of namespace "osapi"
