// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Defines the Interface for parsing configuration items
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATIONPARSER_HH_
#define OSAPI_CONFIGURATIONPARSER_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

// Import module headers
#include "configuration/item.hh"
#include "configuration/container.hh"
#include "configuration/configuration.hh"


// *****************************************************************************************
//
// Section: Parser interface declaration
//
// *****************************************************************************************

namespace osapi
{

namespace configuration
{

/// @brief The Configuration parser interface
class parser
{
public:
		/// @brief The virtual Class destructor
		virtual		 	~parser();

		/// @brief Parse and import a configuration from source into a destination
		/// @param [in] from - Source configuration
		/// @param [in] into - Configuration destination
		virtual void	import				( const std::string & from, std::string & into )	= 0;

		/// @brief Helper methods to insert List of CIs into a a specific configuration and container,
		/// if needed configuration and/or container are created
		/// @param [in] configurationName - Name of configuration to add to
		/// @param [in] containerName - Name of container inside the configuration to add CI
		/// @param [in] list - List of CIs to add to container and configuration
		void			addConfiguration	(
											  const std::string & configurationName,
											  const std::string & containerName,
											  const std::vector<item *> & list
											);

		/// @brief Helper methods to insert List of CIs into a a specific configuration and container
		/// @param [in] config - Configuration reference where to add the CI
		/// @param [in] containerName - Name of container inside the configuration to add CI
		/// @param [in] list - List of CIs to add to container and configuration
		void			addConfiguration	(
											  configuration & config,
											  const std::string & containerName,
											  const std::vector<item *> & list
											);

		/// @brief Helper methods to insert List of CIs into a a specific container
		/// @param [in] containerName - Name of container inside the configuration to add CI
		/// @param [in] list - List of CIs to add to container and configuration
		void			addConfiguration	(
											  container & containerName,
											  const std::vector<item *> & list
											);

		/// @brief Helper methods to insert a single CI into a a specific configuration and container,
		/// if needed configuration and/or container are created
		/// @param [in] configurationName - Name of configuration to add to
		/// @param [in] containerName - Name of container inside the configuration to add CI
		/// @param [in] ci - List of CIs to add to container and configuration
		void			addConfiguration	(
											  const std::string & configurationName,
											  const std::string & containerName,
											  item * ci
											);

		/// @brief Helper methods to insert List of CIs into a a specific configuration and container, if needed container is created
		/// @param [in] config - Configuration reference where to add the CI
		/// @param [in] containerName - Name of container inside the configuration to add CI
		/// @param [in] ci - List of CIs to add to container and configuration
		void			addConfiguration	(
											  configuration & config,
											  const std::string & containerName,
											  item * ci
											);
		/// @brief Helper methods to insert List of CIs into a a specific container, if needed container is created
		/// @param [in] containerName - Name of container inside the configuration to add CI
		/// @param [in] ci - List of CIs to add to container and configuration
		void			addConfiguration	(
											  container & containerName,
											  item * ci
											);

};


}	// End of namespace "configuration"
}	// osapi namespace

#endif /* OSAPI_CONFIGURATIONPARSER_HH_ */
