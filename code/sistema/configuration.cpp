/*
 * system.cpp
 *
 *  Created on: 16/02/2018
 *      Author: joao
 */

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

#include "status/status.hh"
#include "util/util.hh"

#include "sistema/trace.hh"
#include "sistema/system.hh"				// Include my own interface
#include "sistema/propertiesProvider.hh"

namespace osapi
{

constexpr char module[] = "SYSTEM";

// Class methods

Configuration & Configuration::getConfiguration()
{
	static	Configuration instance;

	return instance;
}


// Private Constructor
Configuration::Configuration()
{
  argumentCount 	= 0;
  arguments 		= nullptr;
  environment 		= nullptr;
  TRACE_CLASSNAME( "Configuration" )
}

// Private Destructor
Configuration::~Configuration() {}

// Instance methods

void Configuration::init( int argc, char * argv[], char * env[] )
{
  argumentCount = (size_t) argc;
  arguments		= argv;
  environment	= env;
}

void Configuration::addProperty( const std::string module, const std::string propName, const std::string propValue )
{
	PropertiesProvider::getProvider().addProperty( propName, propValue);
}


// Getting property values with module already provided
bool Configuration::getPropertyValues( const std::string & module, const std::string & name, std::vector<std::string> & values )
{
  bool result = false;

  TRACE_ENTER

  result = PropertiesProvider::getProvider().getPropertyValues( module, name, values );

  TRACE_EXIT

  return result;
}

// Getting property values without module already provided
bool Configuration::getPropertyValues( const std::string & name, std::vector<std::string> & values )
{
  bool result = false;

  TRACE_ENTER

  result = PropertiesProvider::getProvider().getPropertyValues( name, values );

  TRACE_EXIT

  return result;
}


void Configuration::import( const std::string & pathname )
{
  PropertiesProvider::getProvider().importProperties( pathname );
}





}	// End of namespace "osapi"

