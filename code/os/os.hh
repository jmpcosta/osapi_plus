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

/// @brief Class responsible for OS information
class info
 {
 public:
	  /// @brief Class constructor
	 	 	 	 	 	info();

	 /// @brief Get OS name
	 /// @return String with OS name
	 std::string		get_name();

	 /// @brief Get OS name
	 /// @return String with OS name
	 std::string 		get_version();

	 /// @brief Get OS Release
	 /// @return String with Release information
	 std::string		get_release();

	 /// @brief Get OS node name
	 /// @return String with OS node name
	 std::string		get_node();

	 /// @brief Get machine name
	 /// @return String with machine name
	 std::string		get_machine();

	 /// @brief Get OS domain name
	 /// @return String with machine domain name
	 std::string		get_domain();

	 /// @brief Get OS provider
	 /// @return String with OS provider information
	 std::string		get_provider();

	 /// @brief Get OS provider Release
	 /// @return String with OS provider release number
	 std::string		get_provider_release();

 private:
	 bool				osInfoAvailable;
	 t_osInfo			osInfo;
	 TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "osapi"

#endif /* OSAPI_OS_HH_ */
