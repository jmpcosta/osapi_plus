// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose: Defines the Interface for a Configuration
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATION_HH_
#define OSAPI_CONFIGURATION_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>
#include <mutex>

// Import OSAPI++ declarations
#include "status/trace_macros.hh"
#include "configuration/item.hh"
#include "configuration/container.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************


namespace osapi
{

namespace configuration
{

/// @brief The class that represents a configuration, i.e. a set of Configuration Items
/// A configuration is a kind of a named baseline for the set of items that belong to a configuration
class configuration
{
public:

#pragma GCC visibility push(default)		// Start of public interface

		/// @brief Class constructor
		/// @param [in] name - The new configuration name

		explicit 					configuration	( const std::string & name );

		/// @brief Class destructor
				 	 	 	 		~configuration	();

		/// @brief Test if this is the correct container / name match
		/// @param [in] name - Name of the container to match
		/// @return Match success (true) or failure (false)
		bool						equal			( const std::string & name );

		/// @brief Add a new CI to the default container
		/// @return A reference to the default container
		container &					addContainer	();

		/// @brief Add a new CI to the default container
		/// @param [in] name - Add a new CI to a container, if the container doesn't exist, create it first
		/// @return A reference to the named container
		container & 				addContainer	( const std::string & name );

		/// @brief Delete a container
		/// @param [in] name - Name of the container to delete
		/// @return The success of failure of the delete operation
		bool		 				deleteContainer	( const std::string & name );

		/// @brief Get a reference to the default container
		/// @return The reference to the default container
		container &					getContainer	();

		/// @brief Get a reference to the named container
		/// @param [in] name - Name of the container to find
		/// @return The reference to the named container
		container &					getContainer	( const std::string & name );		// Get a container matching "name"

		/// @brief Get the number of containers in the configuration
		/// @return Number of configuration containers
		size_t						getNumber		();

		/// @brief Get the configuration name
		/// @return Configuration name
		const std::string &			getName			() const;




#pragma GCC visibility pop					// End of public interface


private:
		// Instance variables
		std::string						configurationName;
		std::mutex						confMutex;
		std::vector<container *>		ciContainers;


		TRACE_CLASSNAME_DECLARATION
};




}	// End of namespace "configuration"
}	// End of namespace


#endif /* OSAPI_CONFIGURATION_HH_ */
