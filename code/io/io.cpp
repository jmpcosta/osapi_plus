// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide IO module implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "io/io.h"

// Import C++ system headers


// Import OSAPI++ generic headers
#include "general/general_types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "io/io.hh"


namespace osapi
{


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

constexpr char module[] = "IO";


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// ProcessData Instance methods

directory::directory()
{
 TRACE_CLASSNAME( "directory" )
 TRACE_POINT
}


directory::~directory()
{
 TRACE_POINT
}


bool directory::change( const std::string & dirname )
{
 bool ret = false;
 TRACE_ENTER

 t_status st = io_directory_change( (t_char *) dirname.c_str() );

 if( status_success( st ) )
	 ret = true;

 TRACE( "Exiting with:", ret )

 return ret;
}



}   // End of namespace "osapi"
