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
#include "proc/proc_signal_types.h"
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
// Section: Constant declarations/definitions
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{

// Class methods
bool signal::isSupported( signalSupportLevel & supportLevel )
{
 bool ret	= false; 	// Assume no support
 int  level	= 0;		// No support level

 if( status_success( proc_signal_supported( &level ) ) )
   {
	 ret = true;

	 // Map OSAPI C to OSAPI++ to avoid propagation of OSAPI C to OSAPI++ client applications
	 supportLevel = signalSupportLevel::unsupported;

	 switch( level )
	       {
	 	 	 case e_siglevel_none:		supportLevel = signalSupportLevel::unsupported;	break;
	 	 	 case e_siglevel_c:			supportLevel = signalSupportLevel::ansi; 		break;
	 	 	 case e_siglevel_posix:		supportLevel = signalSupportLevel::posix; 		break;
	 	 	 case e_siglevel_realtime:	supportLevel = signalSupportLevel::realTime; 	break;
	       }

   }

 return ret;
}


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

void signal::setHandler( sighandler_t func )
{
 TRACE( "signal:", signumber )
 handler = func;
}

void signal::clearHandler( void )
{
 TRACE( "signal:", signumber )
 handler = nullptr;
}


sighandler_t signal::getHandler( void )
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
