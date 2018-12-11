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
#include "general/general_types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own declarations
#include "configuration/configurationItem.hh"
#include "configuration/ciContainer.hh"
#include "configuration/configuration.hh"




namespace osapi
{

// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

constexpr char module[] 					=	"CONFIGURATION";


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


// Constructor
configuration::configuration( const std::string & name )
{
 TRACE_CLASSNAME( "configuration" )
 TRACE( "New configuration (", name, ")" )

 configurationName = name;

 // Create default container for this configuration
 std::string defaultContainerName = ciContainer::getDefaultName();
 ciContainers.push_back( new ciContainer( defaultContainerName ) );

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

ciContainer & configuration::addContainer( void )
{
 TRACE_POINT

  return *(ciContainers[0]);
}

ciContainer & configuration::addContainer( const std::string & container )
{
 TRACE_ENTER

 std::vector<ciContainer *>::iterator i = ciContainers.begin();

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( confMutex );

 for( ; i != ciContainers.end(); i++ )
    {
      if( (*i)->equal( container ) )
    	  break;		// Container found, add to this container
    }

 // No container exists yet, create container for this configuration list
 if( i == ciContainers.end() )
   {
     ciContainers.push_back( new ciContainer( container ) );
     *i = ciContainers.back();
   }

 TRACE_EXIT

 return **i;
}


bool configuration::deleteContainer( const std::string & container )
{
 bool									ret = false;

 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( confMutex );
 std::vector<ciContainer *>::iterator	i   = ciContainers.begin();

 for( ; i != ciContainers.end(); i++ )
    {
      if( (*i)->equal( container ) )
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


ciContainer & configuration::getContainer( const std::string & name	)
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



ciContainer & configuration::getContainer()
{
  TRACE_POINT

  std::string defaultName = ciContainer::getDefaultName();
  return getContainer( defaultName );
}



}	// End of namespace "osapi"

