// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS module API
//
// *****************************************************************************************

#ifndef OSAPI_OS_HH_
#define OSAPI_OS_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>

// Import OSAPI++ declarations
#include "general/general.hh"
#include "status/trace_macros.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

class info
 {
 public:
	 	 	 	 	 	info();
	 std::string		get_name();
	 std::string 		get_version();
	 std::string		get_release();
	 std::string		get_node();
	 std::string		get_machine();
	 std::string		get_domain();
	 std::string		get_provider();
	 std::string		get_provider_release();
 private:
	 bool				osInfoAvailable;
	 t_osInfo			osInfo;
	 TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "osapi"

#endif /* OSAPI_OS_HH_ */
