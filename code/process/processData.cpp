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
#include "process/processData.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{

// ProcessData Instance methods

processData::processData()
{
 TRACE_CLASSNAME( "processData" )
 TRACE_POINT

 // Initialize data
 environment	= nullptr;
 cmdLine		= nullptr;

 throw_on_failure( proc_memory_allocate( sizeof(t_proc), &data ) );
}


processData::~processData()
{
 TRACE_POINT

 // Deallocate memory from Heap
 proc_memory_deallocate( cmdLine 		);
 proc_memory_deallocate( environment	);
 proc_memory_deallocate( data			);
}


void * processData::getRaw( void )
{
 TRACE_POINT
 return data;
}

bool processData::setCmdLine( std::vector<std::string> & line )
{
 bool		ret			= false;
 char	**	p_array;
 t_proc	*	p_proc		= (t_proc *) data;
 size_t		size;

 TRACE_ENTER

 std::lock_guard<std::mutex> guard( dataMutex );

 if( cmdLine != nullptr )
	 proc_memory_deallocate( cmdLine );

 ret = util::vecStr2array( line, &size, &p_array );

 if( ret )
   {
	 cmdLine = (void *) p_array;
	 throw_on_failure( proc_data_setCmdLine( size, p_array, p_proc ) );
   }

 TRACE_EXIT

 return ret;
}

bool processData::setEnvironment( std::vector<std::string> & env )
{
 bool		ret			= false;
 char	**	p_array;
 t_proc	*	p_proc		= (t_proc *) data;
 size_t		size		= env.size();

 TRACE_ENTER

 std::lock_guard<std::mutex> guard( dataMutex );

 if( environment != nullptr )
	 proc_memory_deallocate( environment );

 ret = util::vecStr2array( env, &size, &p_array );

 if( ret )
   {
	 environment = (void *) p_array;
	 throw_on_failure( proc_data_setEnvironment( size, p_array, p_proc ) );
   }

 TRACE_EXIT

 return ret;
}



};	//End of OSAPI namespace
