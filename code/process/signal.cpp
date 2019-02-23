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
#include "general/general.hh"
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

namespace process
{

TRACE_CLASSNAME(signal)

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
 sigNumber    = number;
 sigHandler   = nullptr;

 TRACE( "signo:", sigNumber )
}


signal::~signal()
{
 TRACE_POINT
}

bool signal::equal( int number )
{
 TRACE( "Testing equal for signal:", sigNumber )
 return ( sigNumber == number );
}

void signal::setHandler( sighandler_t handlerFunction )
{
 TRACE( "signal:", sigNumber )
 sigHandler = handlerFunction;
}

bool signal::hasValidHandler( void )
{
 return ( ! (sigHandler == nullptr) );
}

void signal::clearHandler( void )
{
 TRACE( "signal:", sigNumber )
 sigHandler = nullptr;
}


sighandler_t signal::getHandler( void )
{
 TRACE( "signal number:",  sigNumber  )
 TRACE( "signal handler:", sigHandler )
 return sigHandler;
}

int signal::getNumber( void	)
{
 TRACE( "signal:", sigNumber )
 return sigNumber;
}


}	// End of namespace "process"

}	// End of OSAPI namespace
