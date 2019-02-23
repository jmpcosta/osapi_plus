// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Declaration for Configuration Item types
//
// *****************************************************************************************

#ifndef OSAPI_CITYPE_HH_
#define OSAPI_CITYPE_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <cstdint>



// *****************************************************************************************
//
// Section: Declarations/definitions
//
// *****************************************************************************************

namespace osapi
{

namespace configuration
{


/// @brief Possible Configuration Item types
enum class ciType { UNKNOWN = 0,		//!< Type not known
					ARGUMENT = 1,		//!< Argument CI
					ENVIRONMENT = 2,	//!< A pair of name/value for environment variables
					PROPERTY = 3		//!< A pair of name/value for properties
				  };



}	// End of namespace "configuration"
}	// End of namespace


#endif /* OSAPI_CITYPE_HH_ */
