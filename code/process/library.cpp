// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	API implementation for managing shared libraries
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
#include <string>
#include <vector>

// Import OSAPI++ generic headers
#include "general/general.hh"
#include "status/status.hh"
#include "status/trace.hh"
#include "common/common.hh"

// Import own module declarations
#include "process/library.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{
namespace process
{

TRACE_CLASSNAME( library )


// *****************************************************************************************
//
// Section: CurrentProcess Function definition
//
// *****************************************************************************************

library::library( std::string & name )
{
 t_status	st;

 TRACE_POINT

 st = proc_library_supported();
 throw_on_failure( st );

 libInfo = (void *) new t_memory;

 st = proc_memory_allocate( sizeof( t_library ), (t_memory *) &libInfo );
 throw_on_failure( st );

 libName	= name;
 isLoaded	= false;
 lastError	= empty_string;
}


library::~library( void )
{
 TRACE_ENTER

 t_memory * p_memory = (t_memory *) libInfo;

 proc_memory_deallocate( p_memory );

 delete p_memory;

 TRACE_EXIT
}


bool library::load( const std::vector<std::string> & options )
{
 t_status						st;
 std::vector<const char *>		cOptions;

 TRACE_ENTER

 isLoaded = false;

 for(size_t i=0; i<options.size(); i++)
	  TRACE( i, ": loading option:", options[i] )

 common::vecStrings( options, cOptions );

 TRACE( "Loading library:", libName )

 st = proc_library_load( (char *) libName.c_str(), (char **) cOptions.data(), (t_library *) &libInfo );

 if( status_failure( st ) )
   {
	 lastError = status_message_get( st );
	 TRACE( "Error loading library:", lastError )
   }
 else
   {
	 TRACE( "Successfully loaded library into the current process:", libName )
	 isLoaded 	= true;
   }

 TRACE_EXIT

 return isLoaded;
}



bool library::unload( void )
{
 t_status	st;
 bool 		ret = false;

 TRACE_ENTER

 if( isLoaded )
   {
	 st = proc_library_unload( (t_library) libInfo );
	 if( status_failure( st ) )
		 lastError = status_message_get( st );
	 else
	   {
		 TRACE( "Successfully unloaded library from the current process:", libName )
		 isLoaded	= false;
		 ret		= true;
	   }
   }

 TRACE_EXIT

 return ret;
}


std::string library::getRelease( void )
{
 t_status		st;
 std::string	ret = empty_string;

 TRACE_ENTER

 if( isLoaded )		// Attempt to retrieve my library
   {
	 char release[ 21 ];	// Should be more than enough
	 st = proc_library_getRelease( libName.c_str(), 20, release );

     if( status_success( st ) )
       {
    	 ret = release;
    	 TRACE( "Successfully retrieved library Release:", ret )
       }
   }

 TRACE_EXIT

 return ret;
}



std::string	& library::getLastError( void )
{
 return lastError;
}

}	// End of namespace "process"

}   // End of namespace "osapi"
