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
#include "general/general_types.hh"
#include "status/status.hh"
#include "status/trace.hh"
#include "util/util.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{

constexpr char module[] = "UTIL";

TRACE_CLASSNAME( util )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

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


// Copy a vector of strings into an array of C Strings
bool util::vecStr2array( const std::vector<std::string> vec, size_t * p_arraySize, char ** p_array[] )
{
 bool ret = false;

 if( p_arraySize != nullptr && p_array != nullptr && vec.size() > 0 )
   {
	 size_t	vecSize		= vec.size();
	 size_t allocSize	= (vecSize + 1 ) * sizeof( char * );
	 void * p_mem		= nullptr;

	 // Allocates the memory for the array of pointers first
	 if( status_failure( proc_memory_allocate( allocSize, & p_mem ) ) )
		 throw_error( "Error in memory allocation." );
	 else
	   {
		 size_t cur = 0;
		 *p_array = (char **) p_mem;

		 // For each string, copy it and add the reference to the array of pointers
		 for( auto const & i : vec )
		 	{
			  (*p_array)[ cur++ ] = (char *) i.c_str();

			  // Make sure that the there are no buffer overruns
			  if( cur >= vecSize ) break;
		 	}
		 // Make sure that the last element of the array is a NULL
		 (*p_array)[ cur ] = NULL;
	   }
   }

 return ret;
}



}; // End of namespace "osapi"
