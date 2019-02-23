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


bool common::vecStr2array( const std::vector<std::string> & vec, size_t * p_arraySize, char *** p_array )
{
 t_status 	st;
 bool		ret 		= false;
 size_t		vecSize		= vec.size();

 TRACE_ENTER

 if( p_arraySize != nullptr && p_array != nullptr && vecSize > 0 )
   {
	 t_size allocSize	= (vecSize + 1 ) * sizeof( char * );
	 void * p_mem		= nullptr;

	 // Allocates the memory for the array of pointers first
	 st = proc_memory_allocate( allocSize, & p_mem );
	 if( status_failure( st ) )
		 throw_error( "Error in memory allocation." );
	 else
	   {
		 size_t cur		= 0;
		 *p_arraySize	= 0;
		 *p_array		= (char **) p_mem;
		 TRACE( "Successfully allocated ", allocSize, " bytes at location:", p_mem )
		 TRACE( "Converting vector with size ", vecSize, " to a C-String array" )

		 // For each string, copy it and add the reference to the array of pointers
		 for( auto const & i : vec )
		 	{
			  (*p_array)[ cur++ ] = (char *) i.c_str();

			  // Make sure that the there are no buffer overruns
			  if( cur <= vecSize )
				  (*p_arraySize)++;
			  else
			  	{
				  TRACE( "Error: Current vector bigger than array size: ", cur )
				  break;
			  	}
		 	}
		 // Make sure that the last element of the array is a NULL
		 (*p_array)[ vecSize ] = NULL;
		 ret = true;
	   }
   }

 TRACE( "Exiting with return=", common::bool2string( ret ), " and array size:", (*p_arraySize) )

 return ret;
}


const char * getVecRefString( const std::vector<refConstStr> & vec, size_t index )
{
 return vec[ index ].get().c_str();
}


// Copy a vector of string into an array of C Strings. The vector is a reference object for const strings
bool common::vecRefStr2array( const std::vector<refConstStr> & vec, size_t * p_arraySize, char *** p_array )
{
 t_status 	st;
 bool		ret 		= false;
 size_t		vecSize		= vec.size();

 TRACE_ENTER

 if( p_arraySize != nullptr && p_array != nullptr && vecSize > 0 )
   {
	 t_size allocSize	= (vecSize + 1 ) * sizeof( char * );
	 void * p_mem		= nullptr;

	 // Allocates the memory for the array of pointers first
	 st = proc_memory_allocate( allocSize, & p_mem );
	 if( status_failure( st ) )
		 throw_error( "Error in memory allocation." );
	 else
	   {
		 size_t cur		= 0;
		 *p_array		= (char **) p_mem;
		 TRACE( "Successfully allocated ", allocSize, " bytes at location:", p_mem )
		 TRACE( "Converting vector with size ", vecSize, " to a C-String array" )

		 // For each string, copy it and add the reference to the array of pointers
		 for( auto const & i : vec )
		 	{
			  (*p_array)[ cur++ ] = (char *) i.get().c_str();

			  // Make sure that the there are no buffer overruns
			  if( cur <= vecSize )
				  (*p_arraySize)++;
			  else
			  	{
				  TRACE( "Error: Current vector bigger than array size: ", cur )
				  break;
			  	}
		 	}
		 // Make sure that the last element of the array is a NULL
		 (*p_array)[ vecSize ] = NULL;
		 ret = true;
	   }
   }

 TRACE( "Exiting with return=", common::bool2string( ret ), " and array size:", (*p_arraySize) )

 return ret;
}




};	// End of namespace "osapi"

