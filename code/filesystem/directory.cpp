// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module implementation for a Directory element
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "fs/fs_dir.h"

// Import C++ system headers

// Import OSAPI++ generic headers
#include "general/types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "filesystem/directory.hh"

// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

namespace osapi
{
namespace filesystem
{

TRACE_CLASSNAME( directory )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

directory::directory( const std::string & dirname )
{
 TRACE_POINT

 name 			= dirname;
 p_directory	= (void *) new t_dir;
 type			= elementType::unknown;
 size			= (uint64_t) 0;
}

directory::~directory()
{
 TRACE_POINT

 t_dir * p_dir = (t_dir *) p_directory;

 // Attempt to close directory descriptor
 fs_directory_close( p_dir );

 delete (t_dir *) p_directory;
}


void directory::open( void )
{
 TRACE_POINT

 t_dir * p_dir = (t_dir *) p_directory;

 t_status st = fs_directory_open( name.c_str(), p_dir );

 throw_on_failure( st );
}


void directory::refresh( void )
{
 TRACE_POINT

 t_dir * p_dir = (t_dir *) p_directory;

 t_status st = fs_directory_updateInfo( p_dir );

 throw_on_failure( st );
}



void directory::close( void )
{
 TRACE_POINT

 t_dir * p_dir = (t_dir *) p_directory;

 fs_directory_close( p_dir );
}





}   // End of namespace "filesystem"
}   // End of namespace "osapi"
