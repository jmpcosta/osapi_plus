// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide system tracing declarations/definitions
//
// *****************************************************************************************

#ifndef SISTEMA_TRACE_HH_
#define SISTEMA_TRACE_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <iostream>

// Import OSAPI C declarations
#include "status/status.h"

// Import OSAPI++ declarations
#include "status/status.hh"


// *****************************************************************************************
//
// Section: Trace API declaration/definition
//
// *****************************************************************************************

namespace osapi
{

// Trace template composed of the next two entries
template <typename V>
void trace( const V & value  )
{
	std::cerr << value;
	std::cerr << std::endl;
}

template <typename V, typename... R>
void trace( const V & value, const R & ... rest  )
{
	std::cerr << value;

	trace( rest... );

}

// Wrap the C status return "object" and throw exception if a failure is returned
template <typename S>
void throw_on_failure( const S & st  )
{
	if( status_failure( st ) )
		OSAPI_STATUS( st );

}


}	// End of namespace "osapi"


// *****************************************************************************************
//
// Section: Supporting macros
//
// *****************************************************************************************


#ifdef OSAPI_TRACING
 #define TRACE_CLASSNAME_DECLARATION	std::string	classname;
 #define TRACE_CLASSNAME(x)				classname=x;
 #define TRACE_ENTER					trace ( classname, "::", __FUNCTION__, " - Entering" );
 #define TRACE_EXIT						trace ( classname, "::", __FUNCTION__, " - Leaving" );
 #define TRACE_POINT					trace ( classname, "::", __FUNCTION__, " - Passing through" );
 #define TRACE(...)						trace ( classname, "::", __FUNCTION__, " - ", __VA_ARGS__ );		// For instance methods
 #define STRACE(...)					trace ( __FUNCTION__, " - ", __VA_ARGS__ );							// For class methods
#else
 #define TRACE_CLASSNAME_DECLARATION
 #define TRACE_CLASSNAME(x)
 #define TRACE_ENTER
 #define TRACE_EXIT
 #define TRACE_POINT
 #define TRACE(...)
 #define STRACE(...)
#endif



#endif /* SISTEMA_TRACE_HH_ */
