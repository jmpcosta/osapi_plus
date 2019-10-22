// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Filesystem module implementation for a File element
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "fs/fs_file.h"

// Import C++ system headers

// Import OSAPI++ generic headers
#include "general/types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "filesystem/file.hh"

// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

namespace osapi
{
namespace filesystem
{

TRACE_CLASSNAME( file )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// What does the constructor do: Create/open a file in the filesystem or just create an instance of the type?

file::file( const std::string & filename )
{
 TRACE_POINT

 name		= filename;
 p_iFile	= (void *) new t_file;
}


file::~file()
{
 delete (t_file *) p_iFile;

 TRACE_POINT
}


void file::setOpenMode( const std::string & mode )
{
 iOpenMode.push_back( mode );
}

void file::open( void )
{
 t_status st;

 // TODO
 // Convert array of strings into a C-String array
 st = fs_file_open( name.c_str(), {nullptr}, (t_file *) p_iFile );

 throw_on_failure( st );
}

void file::refresh( void )
{
 t_status st;

 st = fs_file_updateInfo( (t_file *) p_iFile );

 throw_on_failure( st );
}

void file::write( const osapi::buffer & buf )
{
 t_status st;

 st = fs_file_write( (t_file *) p_iFile, (t_buffer *) buf.getAddress() );

 throw_on_failure( st );
}

// Returns false when there is no more items to read to implement the following pattern
// while( read( buffer) ) write( buffer );

bool file::read( osapi::buffer & buf )
{
 t_status st;
 bool  	eof;

 st = fs_file_read( (t_file *) p_iFile, (t_buffer *) buf.getAddress(), &eof );

 throw_on_failure( st );

 return ( ! eof );
}

void file::close( void )
{
 t_status st;

 st = fs_file_close( (t_file *) p_iFile );

 throw_on_failure( st );
}



}   // End of namespace "filesystem"
}   // End of namespace "osapi"
