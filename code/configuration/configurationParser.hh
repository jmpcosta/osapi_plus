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
#include "configuration/configurationItem.hh"
#include "configuration/ciContainer.hh"
#include "configuration/configuration.hh"


// *****************************************************************************************
//
// Section: Parser interface declaration
//
// *****************************************************************************************

namespace osapi
{

class configurationParser
{
public:
		virtual		 	~configurationParser();
		virtual void	import				( const std::string & from, std::string & into )	= 0;

		// Helper methods to insert List of CIs into a a specific configuration and container
		void			addConfiguration	(
											  const std::string & configurationName,
											  const std::string & containerName,
											  const std::vector<configurationItem *> & list
											);
		void			addConfiguration	(
											  configuration & config,
											  const std::string & containerName,
											  const std::vector<configurationItem *> & list
											);
		void			addConfiguration	(
											  ciContainer & containerName,
											  const std::vector<configurationItem *> & list
											);

		// Helper methods to insert a single CI into a a specific configuration and container
		void			addConfiguration	(
											  const std::string & configurationName,
											  const std::string & containerName,
											  configurationItem * p_item
											);
		void			addConfiguration	(
											  configuration & config,
											  const std::string & containerName,
											  configurationItem * p_item
											);
		void			addConfiguration	(
											  ciContainer & containerName,
											  configurationItem * p_item
											);

};

};	// osapi namespace

#endif /* OSAPI_CONFIGURATIONPARSER_HH_ */
