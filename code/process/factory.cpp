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

// Parent process returns a pointer to a new Runner
// Child returns a null pointer
runner * factory::build( process::plan & planned )
{
 t_status	st;

 TRACE_ENTER

 t_proc * p_proc = (t_proc *) planned.getRaw();

 st = proc_instance_create( p_proc );
 throw_on_failure( st );

 TRACE_EXIT

 if( proc_isParent( (*p_proc) ) )
 	 return new runner( (int64_t) p_proc->pid );
 else
	 return nullptr;
}

runner * factory::make( process::plan & planned )
{
 return getFactory().build( planned );
}

// Returns true is planned process is a parent process.
// Returns false otherwise
bool factory::isParent( process::plan & planned )
{
 t_proc * p_proc = (t_proc *) planned.getRaw();

 if( p_proc == nullptr )
	 throw_error( "No process plan exists !" );

 return proc_isParent( (*p_proc) );
}


// Returns true is planned process is a parent process.
// Returns false otherwise
bool factory::isChild( process::plan & planned )
{
 t_proc * p_proc = (t_proc *) planned.getRaw();

 if( p_proc == nullptr )
	 throw_error( "No process plan exists !" );

 return proc_isChild( (*p_proc) );
}


}	// End of namespace "process"

}	//End of OSAPI namespace
