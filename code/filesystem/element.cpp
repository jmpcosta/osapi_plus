// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module implementation for a FS element
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "fs/fs.h"

// Import C++ system headers

// Import OSAPI++ generic headers
#include "general/types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "filesystem/element.hh"


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

namespace osapi
{
namespace filesystem
{

TRACE_CLASSNAME( element )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// ProcessData Instance methods

element::element()
{
 TRACE_POINT
}


element::~element()
{
 TRACE_POINT
}


bool element::exists( const char * path )
{
 bool ret = false;
 TRACE_ENTER

 t_status st = fs_element_exists( (t_char *) path );

 if( status_success( st ) )
	 ret = true;

 TRACE( "Exiting with:", ret )

 return ret;
}


bool element::exists( const std::string & path )
{
 return exists( path.c_str() );
}


}   // End of namespace "filesystem"
}   // End of namespace "osapi"
