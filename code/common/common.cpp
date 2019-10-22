// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide a Common implementation to support functional modules
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <vector>

// Import OSAPI C headers
#include "proc/proc.h"

// Import OSAPI++ generic headers
#include "general/types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "common/common.hh"


namespace osapi
{


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

TRACE_CLASSNAME( common )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


void common::splitString( const std::string & line, const char sep, std::string & name, std::string & value )
{
 size_t pos = line.find( sep );

 if( pos != std::string::npos )
   {
	 name  = line.substr( 0, pos  );
	 value = line.substr( pos + 1 );
   }
}


void common::stringEraser( const std::string & what, size_t location, std::string & where )
{
 size_t pos = where.find( what, location );
 size_t len = what.length();

 if( pos != std::string::npos )
	 where.erase( pos, len );
}

// Convert a string to Upper case
void common::toUpperCase( std::string & str )
{
 for( auto & c : str )
	 c = char( toupper(c) );
}

// Convert a string to Lower case
void common::toLowerCase( std::string & str )
{
 for( auto & c : str )
	  c = char( tolower(c) );
}


const char * common::bool2string ( bool value )
{
 return ( value ? trueString : falseString );
}

// Using void pointer to avoid propagating a t_list OSAPI-C to the OSAPI+ clients
void common::vecStrings( const std::vector<std::string> & source, std::vector<const char *> & target )
{
 TRACE_ENTER

 if( source.size() == 0 ) return;

 target.reserve( source.size() + 1 );

 for( auto const & i : source )
	  target.push_back( i.c_str() );

 target.push_back( nullptr );

}




};	// End of namespace "osapi"

