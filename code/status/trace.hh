// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide tracing declarations/definitions
//
// *****************************************************************************************

#ifndef OSAPI_TRACE_HH_
#define OSAPI_TRACE_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <iostream>

// Import OSAPI++ declarations
#include "status/status.hh"

// Include own private headers
#include "status/trace_internal.hh"

// *****************************************************************************************
//
// Section: Trace API declaration/definition
//
// *****************************************************************************************

namespace osapi
{

#ifdef OSAPI_TRACING

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


#endif	// OSAPI_TRACING


template <typename P>
void throw_error( const P p_c)
{
 if( p_c != nullptr ) throw status( p_c );

 throw status( "Null pointer error !" );
}


}	// End of namespace "osapi"




#endif /* OSAPI_TRACE_HH_ */
