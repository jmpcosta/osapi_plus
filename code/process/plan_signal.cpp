// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide common functionality for the process module.
//			Derived classes for implementation sharing.
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "sec/sec.h"
#include "proc/proc.h"

// Import C++ system headers
#include <iostream>
#include <string>
#include <memory>

// Import OSAPI++ generic headers
#include "general/general.hh"
#include "general/templates.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "process/plan_signal.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{
namespace process
{

TRACE_CLASSNAME( planSignal )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// ProcessData Instance methods
planSignal::planSignal( void )
{
 TRACE_POINT
}


planSignal::~planSignal()
{
TRACE_POINT
}




void planSignal::addSignal( process::signal & sig )
{
 TRACE_ENTER

 sigList.push_back( sig );

 TRACE_EXIT
}


void planSignal::eraseSignal( int signo )
{
 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> 			guard( signalMutex );
 signal_list::iterator	i 			=	sigList.begin();

 for( ; i != sigList.end(); i++ )
    {
	 if( i->equal( signo ) )
	 	 sigList.erase( i );
    }

 TRACE_EXIT
}

// Activate any configured setting
void planSignal::eraseAllSignals()
{
 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> 			guard( signalMutex );
 sigList.clear();

 TRACE_EXIT
}



}	// End of namespace "process"

}	//End of OSAPI namespace
