// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <stdexcept>

// Import OSAPI C respective module declarations
#include "status/status.h"

// Import own module declarations
#include "status/trace.hh"
#include "status/status.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{

TRACE_CLASSNAME( status )

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


status::status( const char * mod, const char * function, const char * errMsg )
{
 TRACE_ENTER

 if( function != nullptr )
   {
	reason = "Exception in function ";
	reason += function;
   }
 if( mod != nullptr )
   {
	reason += " of module ";
	reason += mod;
   }
 if( errMsg != nullptr )
   {
    reason += " with message: ";
    reason += errMsg;
   }

 TRACE_EXIT
}


status::status( const std::string & message )
{
 TRACE_ENTER

 reason = message;

 TRACE_EXIT
}


status::~status() noexcept { TRACE_POINT }

const char * status::what() const throw ()
{
	return reason.c_str();
}


} // End of namespace osapi
