// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	API for Provider of Configurations
//
// *****************************************************************************************

#ifndef CONFIGURATIONPROVIDER_HH_
#define CONFIGURATIONPROVIDER_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

// Import OSAPI++ declarations
#include "status/trace_macros.hh"
#include "configuration/configuration.hh"

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{


class ConfigurationProvider
{
public:
		static ConfigurationProvider & 	getProvider();	// Class instance creator method

		bool			 				getConfiguration	( const std::string & name, configuration ** p_conf	);
		configuration & 				addConfiguration	( const std::string & name							);
		bool			 				deleteConfiguration	( const std::string & configuration					);

		// delete copy and move constructors and assign operators
		ConfigurationProvider(ConfigurationProvider const&) 				= delete;		// Copy construct
		ConfigurationProvider(ConfigurationProvider &&     )				= delete;		// Move construct

		ConfigurationProvider& operator=(ConfigurationProvider const&)		= delete; 		// Copy assign
		ConfigurationProvider& operator=(ConfigurationProvider &&    )		= delete;		// Move assign


private:
		// Constructor & Destructor
		ConfigurationProvider();
		~ConfigurationProvider();

		// Class instance variables
		std::mutex						providerMutex;
		std::vector<configuration *>	configurationList;

	TRACE_CLASSNAME_DECLARATION
};



};	// End of namespace "osapi"


#endif /* CONFIGURATIONPROVIDER_HH_ */
