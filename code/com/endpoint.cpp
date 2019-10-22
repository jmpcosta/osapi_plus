// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Communication module implementation for endpoints
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "fs/fs.h"

// Import C++ system headers

// Import OSAPI++ generic headers
#include "general/types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "com/endpoint.hh"


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

namespace osapi
{
namespace com
{

TRACE_CLASSNAME( endpoint )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// ProcessData Instance methods


endpoint::~endpoint()
{
 TRACE_POINT
}



}   // End of namespace "com"
}   // End of namespace "osapi"
