/*
 * os.cpp
 *
 *  Created on: 02/02/2018
 *      Author: joao
 */

#include <string.h>
#include <iostream>
#include <string>

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "os/os.h"

#include <status/status.hh>
#include <general/general_types.hh>
#include <os/os.hh>

namespace osapi
{

info::info()
{
 t_status		st;

 osInfoAvailable = false;

	st = os_info_get( & osInfo );

	if( status_success( st ) )
		osInfoAvailable = true;
	else
        throw status( STATUS( st ) );
}

std::string info::get_name()
{
 t_status		st;
 char *			osName = 0;

	st = os_name_get( & osInfo, &osName );
	if( status_failure( st ) )
		throw status( STATUS( st ) );

	return std::string( osName );
}

std::string info::get_version()
{
 t_status		st;
 char *				version = 0;

	st = os_version_get( & osInfo, &version );
	if( status_failure( st ) )
		throw status( STATUS( st ) );

	return std::string( version );
}

std::string info::get_release()
{
 char *			release = 0;

 t_status st = os_release_get( & osInfo, &release );
 if( status_failure( st ) )
	 throw status( STATUS( st ) );

	return std::string( release );
}

std::string info::get_node()
{
 t_status		st;
 char *				node = 0;

	st = os_node_get( & osInfo, &node );
	if( status_failure( st ) )
		throw status( STATUS( st ) );

	return std::string( node );
}

std::string info::get_machine()
{
 t_status		st;
 char *			machine = 0;

	st = os_machine_get( & osInfo, &machine );
	if( status_failure( st ) )
		throw status( STATUS( st ) );

	return std::string( machine );
}

std::string info::get_domain()
{
 t_status		st;
 char *				domain = 0;

	st = os_domain_get( & osInfo, &domain );
	if( status_failure( st ) )
		throw status( STATUS( st ) );

	return std::string( domain );
}

std::string info::get_provider()
{
 t_status		st;
 char *			providerName = 0;

	st = os_provider_get( & osInfo, &providerName );
	if( status_failure( st ) )
		throw status( STATUS( st ) );

	return std::string( providerName );
}

std::string info::get_provider_release()
{
 t_status		st;
 char *			providerRelease = 0;

	st = os_providerRelease_get( & osInfo, &providerRelease );
	if( status_failure( st ) )
		throw status( STATUS( st ) );

	return std::string( providerRelease );
}


}   // End of namespace "osapi"
