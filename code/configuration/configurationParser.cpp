// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Defines the default methods for the configuration parser
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>

// Import module headers
#include "configuration/configurationItem.hh"
#include "configuration/ciContainer.hh"
#include "configuration/configuration.hh"
#include "configuration/configurationProvider.hh"

// Import own header
#include "configuration/configurationParser.hh"



// *****************************************************************************************
//
// Section: Parser interface default definitions
//
// *****************************************************************************************

namespace osapi
{

configurationParser::~configurationParser() {};

// Default instance methods for this interface, for List of items

void configurationParser::addConfiguration( ciContainer & container, const std::vector<configurationItem *> & list	)
{
  container.addList( list );
}


void configurationParser::addConfiguration( const std::string & config, const std::string & container, const std::vector<configurationItem *> & list )
{
	ConfigurationProvider::getProvider().addConfiguration( config ).addContainer( container ).addList( list );
}

void configurationParser::addConfiguration( configuration & config, const std::string & container, const std::vector<configurationItem *> & list )
{
    config.addContainer( container ).addList( list );
}


// Default instance methods for this interface, for single items

void configurationParser::addConfiguration( ciContainer & container, configurationItem * p_item	)
{
  container.addItem( p_item );
}


void configurationParser::addConfiguration( const std::string & config, const std::string & container, configurationItem * p_item )
{
	ConfigurationProvider::getProvider().addConfiguration( config ).addContainer( container ).addItem( p_item );
}

void configurationParser::addConfiguration( configuration & config, const std::string & container, configurationItem * p_item )
{
    config.addContainer( container ).addItem( p_item );
}


};
