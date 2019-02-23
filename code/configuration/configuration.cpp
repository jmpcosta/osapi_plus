// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide configuration class implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <vector>
#include <mutex>

// Import OSAPI++ generic headers
#include "general/general.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own declarations
#include "configuration/item.hh"
#include "configuration/container.hh"
#include "configuration/configuration.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{

namespace configuration
{

TRACE_CLASSNAME( configuration )

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Constructor
configuration::configuration( const std::string & name )
{
 TRACE( "New configuration (", name, ")" )

 configurationName = name;

 // Create default container for this configuration
 std::string defaultContainerName = container::getDefaultName();
 ciContainers.push_back( new container( defaultContainerName ) );

 TRACE( "Default Container name", defaultContainerName )
 TRACE_EXIT
}

// Destructor
configuration::~configuration()
{
 TRACE_ENTER

 TRACE( "Destroying configuration (", configurationName, ")" )

 for( const auto & i : ciContainers )
      delete i;

 TRACE_EXIT
}



// Instance methods

size_t configuration::getNumber()
{
 TRACE_POINT

 return ciContainers.size();
}

const std::string & configuration::getName() const
{
 TRACE( "Returning (", configurationName, ")" )
 return configurationName;
}


bool configuration::equal( const std::string & name )
{
 TRACE_POINT

 return ( configurationName == name );
}

container & configuration::addContainer( void )
{
 TRACE_POINT

  return *(ciContainers[0]);
}

container & configuration::addContainer( const std::string & newContainer )
{
 TRACE_ENTER

 std::vector<container *>::iterator i = ciContainers.begin();

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( confMutex );

 for( ; i != ciContainers.end(); i++ )
    {
      if( (*i)->equal( newContainer ) )
    	  break;		// Container found, add to this container
    }

 // No container exists yet, create container for this configuration list
 if( i == ciContainers.end() )
   {
     ciContainers.push_back( new container( newContainer ) );
     *i = ciContainers.back();
   }

 TRACE_EXIT

 return **i;
}


bool configuration::deleteContainer( const std::string & ciContainer )
{
 bool									ret = false;

 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> 		guard( confMutex );
 std::vector<container *>::iterator	i   = ciContainers.begin();

 for( ; i != ciContainers.end(); i++ )
    {
      if( (*i)->equal( ciContainer ) )
    	  break;		// Container found, add to this container
    }

 // If a container exists, delete container
 if( i != ciContainers.end() )
   {
     ciContainers.erase( i );
     ret = true;
   }

 TRACE_EXIT

 return ret;
}


container & configuration::getContainer( const std::string & name )
{
 TRACE_ENTER

 for( const auto & i : ciContainers )
	{
	  if( i->equal( name ) )
	    {
		  TRACE_EXIT
	 	  return *i;
	    }
	}

 std::string errorMsg( "No Container found" );
 status		 st( errorMsg );
 throw st;
}



container & configuration::getContainer()
{
  TRACE_POINT

  std::string defaultName = container::getDefaultName();
  return getContainer( defaultName );
}




}	// End of namespace "configuration"
}	// End of namespace "osapi"

