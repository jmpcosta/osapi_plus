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

// Import C++ system headers
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

// Import OSAPI++ generic headers
#include "general/general_types.hh"
#include "status/status.hh"
#include "util/util.hh"
#include "sistema/trace.hh"

// Import own declarations
#include "sistema/configuration.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

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

