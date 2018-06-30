// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS module implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>

// Import OSAPI++ generic headers
#include "util/util.hh"
#include "general/general_types.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{

// Create a two strings output (name & value) based on an initial input string (line) and string separator (sep)

void util::splitString( const std::string & line, const char sep, std::string & name, std::string & value )
{
 size_t pos = line.find( sep );

 if( pos != std::string::npos )
   {
	 name  = line.substr( 0, pos  );
	 value = line.substr( pos + 1 );
   }
}


void util::stringEraser( const std::string & what, size_t location, std::string & where )
{
 size_t pos = where.find( what, location );
 size_t len = what.length();

 if( pos != std::string::npos )
	 where.erase( pos, len );
}

// Convert a string to Upper case
void util::toUpperCase( std::string & str )
{
	for( auto & c : str )
		 c = char( toupper(c) );
}

// Convert a string to Lower case
void util::toLowerCase( std::string & str )
{
	for( auto & c : str )
		 c = char( tolower(c) );
}


const char * util::bool2string ( bool value )
{
	return ( value ? trueString : falseString );
}

}; // End of namespace "osapi"
