/*
 * trace.hh
 *
 *  Created on: 27/05/2018
 *      Author: joao
 */

#ifndef CODE_SISTEMA_TRACE_HH_
#define CODE_SISTEMA_TRACE_HH_

#include <iostream>

namespace osapi
{

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

}	// End of namespace "osapi"

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






#endif /* CODE_SISTEMA_TRACE_HH_ */
