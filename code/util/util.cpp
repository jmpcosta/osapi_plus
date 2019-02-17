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

// Import OSAPI
#include "osapi.h"

// Import C++ system headers
#include <string>

// Import OSAPI++ generic headers
#include "general/general.hh"
#include "status/status.hh"
#include "status/trace.hh"
#include "common/common.hh"

// Import own module
#include "util/util.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{

TRACE_CLASSNAME( util )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// Create a two strings output (name & value) based on an initial input string (line) and string separator (sep)
void util::splitString( const std::string & line, const char sep, std::string & name, std::string & value )
{
 common::splitString( line, sep, name, value );
}


void util::stringEraser( const std::string & what, size_t location, std::string & where )
{
 common::stringEraser( what, location, where );
}

// Convert a string to Upper case
void util::toUpperCase( std::string & str )
{
 common::toUpperCase( str );
}

// Convert a string to Lower case
void util::toLowerCase( std::string & str )
{
 common::toLowerCase( str );
}


const char * util::bool2string ( bool value )
{
	return common::bool2string( value );
}

// Copy a vector of strings into an array of C Strings
bool util::vecStr2array( const std::vector<std::string> & vec, size_t * p_arraySize, char *** p_array )
{
 return common::vecStr2array( vec, p_arraySize, p_array );
}




}; // End of namespace "osapi"
