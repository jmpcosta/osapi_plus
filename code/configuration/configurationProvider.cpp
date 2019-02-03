// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide PropertiesProvider implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <mutex>

// Import OSAPI++ generic headers
#include "status/trace.hh"

// Import own module declarations
#include "configuration/configuration.hh"

// Import my declarations
#include "configuration/configurationProvider.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{

TRACE_CLASSNAME( ConfigurationProvider )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

ConfigurationProvider & ConfigurationProvider::getProvider()
{
 static	ConfigurationProvider instance;

 return instance;
}

// Instance Methods

// First, private methods

// Private Constructor
ConfigurationProvider::ConfigurationProvider()
{ TRACE_POINT }

// Private Destructor
ConfigurationProvider::~ConfigurationProvider()
{
 TRACE_ENTER

 for( const auto & i : configurationList )
 	  delete i;

 TRACE_EXIT
}



bool ConfigurationProvider::getConfiguration( const std::string & name, configuration ** p_conf )
{
 bool ret = false;

 TRACE_ENTER

 if( p_conf == nullptr ) throw_error( "Null configuration pointer" );

 TRACE( "Looking for configuration:", name, "." )

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( providerMutex );

 for( const auto & i : configurationList )
 	  if( i->equal( name ) )
		{
		  TRACE( "Found a matching configuration" )
		  TRACE( "Addresses:", p_conf, *p_conf, i )
		  *p_conf = i;
		  ret = true;
		}

 TRACE_EXIT

 return ret;
}



configuration & ConfigurationProvider::addConfiguration( const std::string & name )
{
 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( providerMutex );

 for( const auto & i : configurationList )
 	  if( i->equal( name ) )  return *i;

 configurationList.push_back( new configuration( name ) );

 TRACE_EXIT

 return *(configurationList.back());
}



bool ConfigurationProvider::deleteConfiguration( const std::string & confName )
{
 bool										ret = false;
 std::vector<configuration *>::iterator		i   = configurationList.begin();

 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( providerMutex );

 for( ; i != configurationList.end(); i++ )
    {
      if( (*i)->equal( confName ) )
    	  break;		// Container found, add to this container
    }

 // If a configuration exists, delete configuration
 if( i != configurationList.end() )
   {
	 configurationList.erase( i );
     ret = true;
   }

 TRACE_EXIT

 return ret;
}


};	// End of namespace "osapi"


