// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	API for Provider of Configurations
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATIONPROVIDER_HH_
#define OSAPI_CONFIGURATIONPROVIDER_HH_

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

namespace configuration
{

/// @brief The class that manages the set of configurations
///
/// A configuration is composed of a set of CIs.
/// These CIs can be organized in containers.
///
/// The set of of configurations can be managed through a configuration Provider interface which is provided by this class.
class Provider
{
public:
		/// @brief The method to retrieve the singleton class instance
		/// @return The reference to the singleton
		static Provider				 & 	getProvider();	// Class instance creator method

		/// @brief Get the reference to a given configuration
		/// @param [in] name - The configuration name to retrieve
		/// @param [out] conf - A reference to a configuration
		/// @return Operation status: Success (true) or failure (false) to find the configuration
		bool			 				getConfiguration	( const std::string & name, configuration ** conf	);

		/// @brief Add one configuration to the set of configurations
		/// @param [in] name - The configuration name to add
		/// @return A reference to the newly added configuration
		configuration & 				addConfiguration	( const std::string & name							);

		/// @brief Delete one configuration from the set of configurations
		/// @param [in] name - The configuration name to delete
		/// @return Operation status: Success (true) or failure (false)
		bool			 				deleteConfiguration	( const std::string & name							);

		// delete copy and move constructors and assign operators
		Provider(Provider const&) 				= delete;		// Copy construct
		Provider(Provider &&     )				= delete;		// Move construct

		Provider& operator=(Provider const&)	= delete; 		// Copy assign
		Provider& operator=(Provider &&    )	= delete;		// Move assign


private:
		/// @brief Constructor
		Provider();

		/// @brief destructor
		~Provider();

		/// @brief The mutex to prevent concurrent access to the configuration set
		std::mutex						providerMutex;
		/// @brief Class holding the set of configurations
		std::vector<configuration *>	configurationList;

	TRACE_CLASSNAME_DECLARATION
};



}	// End of namespace "configuration"
}	// End of namespace "osapi"


#endif /* OSAPI_CONFIGURATIONPROVIDER_HH_ */
