// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Process module implementation
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

// #import <string.h>

// Import C++ system headers
#include <iostream>
#include <string>
#include <mutex>

// Import OSAPI++ generic headers
#include "general/general.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "process/signal.hh"
#include "process/current.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{
namespace process
{

TRACE_CLASSNAME( Current )


// *****************************************************************************************
//
// Section: CurrentProcess Function definition
//
// *****************************************************************************************


// Implementation for CurrentProcess
Current & Current::get()
{
 static Current instance;

 return instance;
}

Current::Current()
{
 TRACE_POINT
}

Current::~Current()
{
 TRACE_POINT
}


bool Current::clone( bool & isClone )
{
 bool		ret		= false;
 int		isChild	= false;

 TRACE_ENTER

 isClone = false;
 t_status st = proc_instance_clone( &isChild );
 if( status_success( st ) )
   {
	 ret = true;
	 if( isChild ) isClone = true;
   }

 return ret;
}


void Current::terminate( bool normal )
{
 int code = 0;

 if( ! normal )	 code = 1;

 // The next call will always succeed
 proc_instance_terminate( code );
}


int64_t Current::getPID()
{
 TRACE_POINT

 return id.get();
}

int64_t Current::getParentPID()
{
 t_pid pid = 0;

 TRACE_ENTER

 t_status st = proc_id_getParent( (t_pid) id.get(), & pid );
 throw_on_failure( st );

 TRACE_EXIT

 return (int64_t) pid;
}

bool Current::setSession()
{
 bool 		ret = false;
 t_status	st;

 TRACE_ENTER

 st = proc_id_setSession();
 if( status_success( st ) )
   {
	 TRACE( "Success in creating own session process" )
	 ret = true;
   }

 TRACE( " Exiting with ", ret )

 return ret;
}


bool Current::suspend()
{
 bool 		ret = false;
 t_status	st;

 TRACE_ENTER

 st = proc_instance_suspendExecution();
 if( status_success( st ) )
   {
	 TRACE( "Success in suspending process" )
	 ret = true;	// If it succeeds it will only return when the thread is interrupted
   }

 TRACE( " Exiting with ", ret )

 return ret;
}


// Activate any configured setting
void Current::activateAllSignals()
{
 t_status st;

 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> 			guard( procMutex );
 signal_list::iterator				i =	sigList.begin();

 TRACE_IF( t_size sz = sigList.size(); )
 TRACE( "Size of list of signals:", sz )

 for( ; i != sigList.end(); i++ )
    {
	  TRACE( "Activating signal number:", i->getNumber() )
	  if( i->hasValidHandler() )
	    {
		  st = proc_signal_setHandler( i->getNumber(), i->getHandler() );
		  throw_on_failure( st );
	    }
    }

 TRACE_EXIT
}


void Current::clearAllSignals()
{
 t_status st;

 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( procMutex );

 // Clear process signal mask
 st = proc_signal_clearAll();
 throw_on_failure( st );

 TRACE_EXIT
}


}	// End of namespace "process"

}   // End of namespace "osapi"
