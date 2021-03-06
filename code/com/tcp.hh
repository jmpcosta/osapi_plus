// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Communication module API for TCP endpoints
//
// *****************************************************************************************

#ifndef OSAPI_COM_TCP_HH_
#define OSAPI_COM_TCP_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>

// Import OSAPI++ declarations
#include "general/types.hh"
#include "status/trace_macros.hh"

// Import own Module declarations
#include "com/endpoint.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace com
{

class tcp : public endpoint
{
public:
						// Constructor & Destructor
						tcp( std::string & ips, int port );
						~tcp();

protected:

private:

		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "com"
}	// End of namespace "osapi"

#endif /* OSAPI_COM_TCP_HH_ */
