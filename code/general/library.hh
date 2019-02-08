// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Defines a process interface from own process (inside view).
//			The API allows complete control of the available OS process services.
//
// *****************************************************************************************

#ifndef OSAPI_LIBRARY_HH_
#define OSAPI_LIBRARY_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers

// Import Module declarations
#include "general/baseline.hh"

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

class library
{
public:
		static unsigned long 	getRelease() 			noexcept;
		static unsigned long 	getVersion() 			noexcept;
		static const char 	*	getReleaseString()		noexcept;
		static const char 	*	getVersionString()		noexcept;
		static bool				verifyBaseline()		noexcept;

private:
		static bool				cppBaseline()			noexcept;
		library() 										noexcept;		// Private for now
};


}	// End of namespace "osapi"


#endif	// OSAPI_LIBRARY_HH_
