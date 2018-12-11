// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide signal class implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "proc/proc.h"

// Import C++ system headers
#include <string.h>
#include <iostream>
#include <string>

// Import OSAPI++ generic headers
#include "general/general_types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "process/signal.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{

// Constructor & Destructor
signal::signal( int number )
{
 TRACE_CLASSNAME( "signal" )

 TRACE( "signal:", number )
 signumber = number;
 handler   = nullptr;
}

signal::~signal()
{
 TRACE( "signal:", signumber )
}

bool signal::equal( int number )
{
 TRACE( "Testing equal for signal:", number )
 return ( signumber == number );
}

void signal::setHandler( signal_function func )
{
 TRACE( "signal:", signumber )
 handler = func;
}

void signal::clearHandler( void )
{
 TRACE( "signal:", signumber )
 handler = nullptr;
}


signal_function signal::getHandler( void )
{
 TRACE( "signal:", signumber )
 return handler;
}

int signal::getID( void	)
{
 TRACE( "signal:", signumber )
 return signumber;
}

}; // End of OSAPI namespace
