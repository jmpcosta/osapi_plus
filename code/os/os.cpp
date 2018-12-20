// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OS module implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "os/os.h"

// Import C++ system headers
#include <string.h>
#include <iostream>
#include <string>

// Import OSAPI++ generic headers
#include "general/general_types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "os/os.hh"


namespace osapi
{

// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

constexpr char module[] = "OS";

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


info::info()
{
 TRACE_CLASSNAME( "info" )

 osInfoAvailable = false;

 throw_on_failure( os_info_get( & osInfo ) );

 osInfoAvailable = true;
}

std::string info::get_name()
{
 char *			osName = 0;

 throw_on_failure( os_name_get( & osInfo, &osName ) );

 return std::string( osName );
}

std::string info::get_version()
{
 char *				version = 0;

 throw_on_failure( os_version_get( & osInfo, &version ) );

 return std::string( version );
}

std::string info::get_release()
{
 char *			release = 0;

 throw_on_failure( os_release_get( & osInfo, &release ) );

 return std::string( release );
}

std::string info::get_node()
{
 char *				node = 0;

 throw_on_failure( os_node_get( & osInfo, &node ) );

 return std::string( node );
}

std::string info::get_machine()
{
 char *			machine = 0;

 throw_on_failure( os_machine_get( & osInfo, &machine ) );

 return std::string( machine );
}

std::string info::get_domain()
{
 char *				domain = 0;

 throw_on_failure( os_domain_get( & osInfo, &domain ) );

 return std::string( domain );
}

std::string info::get_provider()
{
 char *			providerName = 0;

 throw_on_failure( os_provider_get( & osInfo, &providerName ) );

 return std::string( providerName );
}

std::string info::get_provider_release()
{
 char *			providerRelease = 0;

 throw_on_failure( os_providerRelease_get( & osInfo, &providerRelease ) );

 return std::string( providerRelease );
}


}   // End of namespace "osapi"
