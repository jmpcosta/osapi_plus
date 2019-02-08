// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Implementation of a process factory
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "proc/proc_instance.h"

// Import C++ system headers

// Import OSAPI++ generic headers
#include "general/general.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "process/factory.hh"

// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{
namespace process
{

TRACE_CLASSNAME( factory )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


factory & factory::getFactory( void )
{
 static factory instance;

 return instance;
}

factory::factory()
{ TRACE_POINT }

factory::~factory()
{ TRACE_POINT }


runner * factory::build( process::plan & planned )
{
 t_status	st;

 TRACE_ENTER

 t_proc *	p_proc = (t_proc *) planned.getRaw();

 st = proc_instance_create( p_proc );
 throw_on_failure( st );

 TRACE_EXIT

 return new runner( (int64_t) p_proc->pid );
}

runner * factory::make( process::plan & planned )
{
 return getFactory().build( planned );
}

}	// End of namespace "process"

}	//End of OSAPI namespace
