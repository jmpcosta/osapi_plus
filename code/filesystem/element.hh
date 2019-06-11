// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide File system module API
//
// *****************************************************************************************

#ifndef OSAPI_FS_ELEMENT_HH_
#define OSAPI_FS_ELEMENT_HH_

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
#include "filesystem/elementType.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace filesystem
{

class element
{
public:
						// Constructor & Destructor
						element();
						~element();
		static bool		exists( const std::string & name );
		static bool		exists( const char *		name );

protected:

private:

		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "filesystem"
}	// End of namespace "osapi"

#endif /* OSAPI_FS_ELEMENT_HH_ */
