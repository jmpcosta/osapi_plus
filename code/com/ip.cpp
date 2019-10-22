// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Communication module implementation for IPs
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"

// Import C++ system headers
#include <string>

// Import OSAPI++ generic headers
#include "general/types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "com/ip.hh"


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

namespace osapi
{
namespace com
{

TRACE_CLASSNAME( ip )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// ProcessData Instance methods

ip::ip( std::string & address )
{
 TRACE_POINT
}


ip::~ip()
{
 TRACE_POINT
}



}   // End of namespace "com"
}   // End of namespace "osapi"
