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
#include <string.h>
#include <iostream>
#include <string>

// Import OSAPI++ generic headers
#include "general/general_types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "process/process.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{

process::process()
{
 TRACE_CLASSNAME( "info" )

}

process::~process()
{
 TRACE_POINT

}


intmax_t process::getPID()
{
 t_pid pid = 0;

 throw_on_failure( proc_id_get( & pid ) );

 return (intmax_t) pid;
}


intmax_t process::getParentPID()
{
 t_pid pid = 0;

 throw_on_failure( proc_parentID_get( & pid ) );

 return (intmax_t) pid;
}


bool process::suspend()
{
 if( status_success( proc_thread_suspend() ) )
	 return true;
 else
	 return false;
}


}   // End of namespace "osapi"
