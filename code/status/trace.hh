// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide tracing declarations/definitions
//
// *****************************************************************************************

#ifndef STATUS_TRACE_HH_
#define STATUS_TRACE_HH_

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
		throw status(
						status_module_get	( st ),
						status_function_get	( st ),
						status_error_get	( st )
			  	  	);

}


template <typename P>
void throw_error( const P p_c)
{
	if( p_c != nullptr ) throw status( p_c );

	throw status( "Null pointer error !" );
}


}	// End of namespace "osapi"


#endif /* STATUS_TRACE_HH_ */
