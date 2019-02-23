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

/// @brief Class responsible for OSAPI library wide definitions
class library
{
public:

		/// @brief Get the Release number of the OSAPI C++ library
		/// @return The Release number
		static unsigned long 	getRelease() 			noexcept;

		/// @brief Get the Version number of the OSAPI C++ library
		/// @return The Version number
		static unsigned long 	getVersion() 			noexcept;

		/// @brief Get the Release number in string format of the OSAPI C++ library
		/// @return The Release number string
		static const char 	*	getReleaseString()		noexcept;

		/// @brief Get the Version number in string format of the OSAPI C++ library
		/// @return The Version number string
		static const char 	*	getVersionString()		noexcept;

		/// @brief Test the current OSAPI baseline, i.e. all requirements for OSAPI runtime operations
		/// @return Meets the required baseline (true) or not (false).
		static bool				verifyBaseline()		noexcept;

private:
		static bool				cppBaseline()			noexcept;
		library() 										noexcept;		// Private for now
};


}	// End of namespace "osapi"


#endif	// OSAPI_LIBRARY_HH_
