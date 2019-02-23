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
#include "configuration/item.hh"
#include "configuration/container.hh"
#include "configuration/configuration.hh"
#include "configuration/Provider.hh"

// Import own header
#include "configuration/parser.hh"



// *****************************************************************************************
//
// Section: Parser interface default definitions
//
// *****************************************************************************************

namespace osapi
{

namespace configuration
{


parser::~parser() {};

// Default instance methods for this interface, for List of items

void parser::addConfiguration( container & ciContainer, const std::vector<item *> & list	)
{
  ciContainer.addList( list );
}


void parser::addConfiguration( const std::string & config, const std::string & container, const std::vector<item *> & list )
{
	Provider::getProvider().addConfiguration( config ).addContainer( container ).addList( list );
}

void parser::addConfiguration( configuration & config, const std::string & container, const std::vector<item *> & list )
{
    config.addContainer( container ).addList( list );
}


// Default instance methods for this interface, for single items

void parser::addConfiguration( container & ciContainer, item * p_item	)
{
  ciContainer.addItem( p_item );
}


void parser::addConfiguration( const std::string & config, const std::string & container, item * p_item )
{
	Provider::getProvider().addConfiguration( config ).addContainer( container ).addItem( p_item );
}

void parser::addConfiguration( configuration & config, const std::string & container, item * p_item )
{
    config.addContainer( container ).addItem( p_item );
}


}	// End of namespace "configuration"

}	// End of namespace "osapi"
