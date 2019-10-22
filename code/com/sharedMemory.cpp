// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Communication module implementation for Shared Memory
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
#include "com/sharedMemory.hh"


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

namespace osapi
{
namespace com
{

TRACE_CLASSNAME( sharedMemory )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// ProcessData Instance methods

sharedMemory::sharedMemory( std::string & inkey )
{
 key = inkey;
 TRACE_POINT
}


sharedMemory::~sharedMemory()
{
 TRACE_POINT
}



}   // End of namespace "com"
}   // End of namespace "osapi"
