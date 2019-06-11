// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide tracing declarations/definitions
//
// *****************************************************************************************

#ifndef OSAPI_TRACE_INTERNAL_HH_
#define OSAPI_TRACE_INTERNAL_HH_

#ifndef OSAPI_TRACE_CLIENT

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



}	// End of namespace "osapi"


#endif	// ! OSAPI_TRACE_CLIENT

#endif /* OSAPI_TRACE_INTERNAL_HH_ */
