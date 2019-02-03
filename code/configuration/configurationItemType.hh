// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Declaration for Configuration Item types
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATIONITEMTYPE_HH_
#define OSAPI_CONFIGURATIONITEMTYPE_HH_

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

// Possible CI types
enum class ciType { UNKNOWN = 0, ARGUMENT = 1, ENVIRONMENT = 2, PROPERTY = 3 };



#endif /* OSAPI_CONFIGURATIONITEMTYPE_HH_ */
