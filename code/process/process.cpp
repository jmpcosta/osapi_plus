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
#include "util/util.hh"

// Import own module declarations
#include "process/signal.hh"
#include "process/process.hh"


namespace osapi
{

// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

constexpr char module[] = "Process";


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Process Class methods
CurrentProcess & process::getCurrent()
{
  return CurrentProcess::getInstance();
}

bool process::create( process & proc )
{
 bool 		ret = false;
 t_proc	*	p_proc;

 // Convert the generic pointer to the concrete OSAPI t_proc pointer
 p_proc = (t_proc *) proc.getData().getRaw();

 // The return will only occur for the father of the process.
 // The child is created with the arguments on the t_proc type and executes the given binary
 if( status_success( proc_instance_create( p_proc ) ) )
 	 ret = true;

 return ret;
}

// Instance methods

process::process()
{
 TRACE_CLASSNAME( "process" )
}

process::~process()
{ TRACE_POINT }


processData & process::getData()
{
 return data;
}

bool process::addCommandLine( std::vector<std::string> & args )
{
 if( args.size() <= 0 )
	 throw_error( "No command line provided !" );

 return getData().setCmdLine( args );
}


bool process::addEnvironment( std::vector<std::string> & env )
{
 if( env.size() <= 0 )
	 throw_error( "No environment provided !" );

 return getData().setEnvironment( env );
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


bool CurrentProcess::clone( bool & isClone )
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


void CurrentProcess::terminate( bool normal )
{
 int code = 0;

 if( normal )
	 code = 1;

 // The next call will always succeed
 proc_instance_terminate( code );
}


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

bool CurrentProcess::setSession()
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


bool CurrentProcess::suspend()
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
