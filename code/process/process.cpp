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

// Import C++ system headers
#include <iostream>
#include <string.h>
#include <string>
#include <mutex>

// Import OSAPI++ generic headers
#include "general/general_types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "process/signal.hh"
#include "process/process.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{

CurrentProcess & process::getCurrent()
{
  return CurrentProcess::getInstance();
}

process::process()
{
 TRACE_CLASSNAME( "process" )

}

process::~process()
{
 TRACE_POINT

}


void process::addSignal( signal & sig )
{
 // Move the signal content (rvalue) to the vector
 sigList.push_back( std::move( sig ) );
}


void process::eraseSignal( int signo )
{
 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> 			guard( signalMutex );
 std::vector<osapi::signal>::iterator	i =	sigList.begin();

 for( ; i != sigList.end(); i++ )
    {
	  if( i->getID() == signo )
	    {
		  throw_on_failure( proc_signal_resetHandler( signo ) );
		  sigList.erase( i );
	    }
    }

 TRACE_EXIT
}

// Activate any configured setting
void process::eraseAllSignals()
{
 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> 			guard( signalMutex );
 std::vector<osapi::signal>::iterator	i =	sigList.begin();

 for( ; i != sigList.end(); i++ )
    {
	  TRACE( "Reset handler for signal number:", i->getID() )
	  throw_on_failure( proc_signal_resetHandler( i->getID() ) );
    }

 TRACE_EXIT
}


// Implementation for CurrentProcess
CurrentProcess & CurrentProcess::getInstance()
{
 static CurrentProcess instance;

 return instance;
}

CurrentProcess::CurrentProcess()
{ TRACE_CLASSNAME( "CurrentProcess" ) }

CurrentProcess::~CurrentProcess()
{  TRACE_POINT  }


unsigned long CurrentProcess::getPID()
{
 t_pid		pid = 0;

 TRACE_ENTER

 t_status st = proc_id_get( &pid );
 throw_on_failure( st );

 TRACE_EXIT

 return (unsigned long) pid;
}

unsigned long CurrentProcess::getParentPID()
{
 t_pid pid = 0;

 TRACE_ENTER

 t_status st = proc_id_getParent( & pid );
 throw_on_failure( st );

 TRACE_EXIT

 return (unsigned long) pid;
}

bool CurrentProcess::suspend()
{
 bool 		ret = false;
 t_status	st;

 TRACE_ENTER

 st = proc_execution_suspend();
 if( status_success( st ) )
   {
	 TRACE( "Success in suspending process" )
	 ret = true;	// If it succeeds it will only return when the thread is interrupted
   }

 TRACE( " Exiting with ", ret )

 return ret;
}


// Activate any configured setting
void CurrentProcess::activateSignals()
{
 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> 			guard( signalMutex );
 std::vector<osapi::signal>::iterator	i =	sigList.begin();

 for( ; i != sigList.end(); i++ )
    {
	  TRACE( "Activating signal number:", i->getID() )
	  throw_on_failure( proc_signal_setHandler( i->getID(), i->getHandler() ) );
    }

 TRACE_EXIT
}


void CurrentProcess::clearSignals()
{
 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( signalMutex );

 // Clear process signal mask
 throw_on_failure( proc_signal_clearAll() );

 TRACE_EXIT
}


// Activate any configured setting
void CurrentProcess::activateAll()
{
 TRACE_ENTER

 // Activate signals
 activateSignals();

 TRACE_EXIT
}




}   // End of namespace "osapi"
