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
#include "fs/fs_element.h"

// Import C++ system headers
#include <string>
#include <vector>

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

element::element( void )
{
 TRACE_POINT

 size	= 0;
 type	= elementType::unknown;
}

element::~element( void )
{ TRACE_POINT }



bool element::operator==(element const & elem )
{
 bool result = false;

 t_status st = fs_element_same( name.c_str(), elem.name.c_str(), &result );

 if( status_failure( st ) )	 return false;

 return result;
}



elementType	element::getType( const std::string & name )
{
 t_status 	st;
 t_fs_eType	type;

 st = fs_element_getType( name.c_str(), &type );

 throw_on_failure( st );

 return static_cast<elementType>(type);
}

bool element::exists( const std::string & path )
{
 bool ret = false;
 TRACE_ENTER

 t_status st = fs_element_exists( (t_char *) path.c_str(), &ret );

 if( status_success( st ) )	 ret = true;

 TRACE( "Exiting with:", ret )

 return ret;
}


bool element::remove( const std::string & path 	)
{
 bool ret = false;
 TRACE_ENTER

 t_status st = fs_element_remove( (t_char *) path.c_str() );

 if( status_success( st ) )	 ret = true;

 TRACE( "Exiting with:", ret )

 return ret;
}

/*
bool element::copy( const std::string & source, const std::string & target, const std::vector<std::string> & options )
{
 bool ret = false;
 TRACE_ENTER

 t_status st = fs_element_scopy( (t_char *) source.c_str(), (t_char *) target.c_str() );

 if( status_success( st ) )	 ret = true;

 TRACE( "Exiting with:", ret )

 return ret;
}
*/

bool element::copy( const std::string & source, const std::string & target, bool overwrite )
{
 bool ret = false;
 TRACE_ENTER

 t_status st = fs_element_copy( (t_char *) source.c_str(), (t_char *) target.c_str(), overwrite );

 if( status_success( st ) )	 ret = true;

 TRACE( "Exiting with:", ret )

 return ret;
}


bool element::copy( const std::string & source, const std::string & target )
{
 return element::copy( source, target, true);
}


bool element::move( const std::string & source, const std::string & target )
{
 bool ret = false;
 TRACE_ENTER

 t_status st = fs_element_move( (t_char *) source.c_str(), (t_char *) target.c_str() );

 if( status_success( st ) )	 ret = true;

 TRACE( "Exiting with:", ret )

 return ret;
}

/*
bool element::isFile( const std::string & name )
{

}

bool element::isDirectory( const std::string & name )
{

}



void element::getUID( void )
{

}

void element::getGID( void )
{

}


std::time_t	element::getCreationTime( void )
{

}

std::time_t	element::getModificationTime( void )
{

}

std::time_t	element::getAccessTime( void )
{

}


*/

}   // End of namespace "filesystem"
}   // End of namespace "osapi"
