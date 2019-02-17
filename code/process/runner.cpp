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
#include <chrono>
#include <thread>

// Import OSAPI++ generic headers
#include "general/general.hh"
#include "status/status.hh"
#include "status/trace.hh"
#include "common/id.hh"
#include "util/util.hh"

// Import own module declarations
#include "process/runner.hh"


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

namespace osapi
{
namespace process
{

TRACE_CLASSNAME( runner )

// *****************************************************************************************
//
// Section: Process Function definition
//
// *****************************************************************************************


// Instance methods
runner::runner( int64_t pid ) : id( pid )
{
 TRACE_POINT

 if( ! exists( pid ) )
	 throw osapi::status( "The Process is not running" );
}


runner::runner() : id( 0 )
{
 t_pid pid;

 t_status st = proc_id_get( &pid );
 throw_on_failure( st );

 id.set( (int64_t) pid );
}

runner::~runner()
{ TRACE_POINT }


int64_t runner::getPID( void )
{
 TRACE_POINT

 return id.get();
}

int64_t runner::getParentPID( void )
{
 t_status st;
 t_pid pid = 0;

 st = proc_id_getParent( (t_pid) id.get(), &pid );
 throw_on_failure( st );

 return (int64_t) pid;
}


bool runner::exists( int64_t pid )
{
 t_status st;

 TRACE_ENTER

 // Test the existence of the Process
 st = proc_instance_isRunning( (t_pid) pid );
 if( status_failure( st ) )
   {
	 TRACE( "The failed PID that was tested was:", pid )
	 TRACE_EXIT
 	 return false;
   }

 TRACE_EXIT

 return true;
}


state runner::getState( void )
{
 t_status	st;
 int		iState;

 st = proc_instance_getState( (t_pid) getPID(), & iState );
 throw_on_failure( st );

 return (state) iState;
}


status runner::getStatus( void )
{
 t_status		st;
 t_proc_status	iStatus;

 st = proc_instance_getStatus( (t_pid) getPID(), & iStatus );
 throw_on_failure( st );

 status	retStatus(
		 	 	 	 proc_getStatusInfo(   iStatus	),
					 proc_getStatusSignal( iStatus  ),
					 proc_getStatusCode(   iStatus  )
 	 	 	 	 );

 return retStatus;
}

bool runner::terminate( size_t graceTime )
{
 t_status		st;

 st = proc_instance_destroy( (t_pid) id.get(), false );
 if( status_failure( st ) )
	 return false;			// No need to wait since the forced kill bellow will also fail

 std::this_thread::sleep_for( std::chrono::milliseconds( graceTime ) );

 st = proc_instance_destroy( (t_pid) id.get(), true );

 return status_result( st );
}

}	// End of namespace "process"

}   // End of namespace "osapi"
