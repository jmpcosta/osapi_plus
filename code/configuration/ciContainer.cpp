// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide a Configuration Container implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <configuration/defs.hh>
#include <vector>
#include <algorithm>
#include <mutex>

// Import OSAPI++ generic headers
#include "status/status.hh"
#include "util/util.hh"
#include "status/trace.hh"

// Import own module declarations
#include "configuration/ciContainer.hh"


namespace osapi
{


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

constexpr char container_default_name[]	=	"-Default-";

TRACE_CLASSNAME( ciContainer )

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// Class methods
const char * ciContainer::getDefaultName()
{
 return container_default_name;
}


// Definition of Constructor & Destructor

ciContainer::ciContainer( const std::string & containerName )
{
 name = containerName;
 TRACE( "Creating Container name:|", name, "|" )
}

ciContainer::~ciContainer()
{
 TRACE( "Destroying container (", name, ")" )

 for( const auto & i : ciList )	 delete i;
}

size_t ciContainer::getNumber()
{
 return ciList.size();
}

std::vector<refConstStr> ciContainer::getStringList()
{
 std::vector<std::reference_wrapper<const std::string>> stringList;

 for( const auto & i : ciList )
	  stringList.push_back( std::ref( i->getString() ) );

 return stringList;
}


void ciContainer::addList( const std::vector<configurationItem *> & list )
{
 std::string errorMsg("");

 TRACE_ENTER

 if( list.size() == 0 )
   {
	 errorMsg = "Invalid List Size";
	 throw new status( errorMsg );
   }

 // If all pre-requisites are valid, add the list to this container
 ciList.insert( std::end( ciList ), std::begin( list ), std::end( list) );

 TRACE_EXIT
}


bool ciContainer::equal( const std::string & containerName )
{
 bool ret = false;

 TRACE_POINT

 if( name == containerName )
   {
	 TRACE( "Found matching container (", name, ")" )
	 ret = true;
   }

 TRACE_EXIT

 return ret;
}



bool ciContainer::deleteItem( const std::string & itemName )
{
 bool											ret = false;
 std::vector<configurationItem *>::iterator		i   = ciList.begin();

 TRACE_ENTER

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( containerMutex );

 for( ; i != ciList.end(); i++ )
    {
      if( (*i)->equal( itemName ) )
    	  break;		// Container found, add to this container
    }

 // If a CI exists, delete CI
 if( i != ciList.end() )
   {
	 ciList.erase( i );
     ret = true;
   }

 TRACE_EXIT

 return ret;
}


void ciContainer::addItem( configurationItem * p_item )
{
 TRACE_ENTER

 if( p_item == nullptr ) throw_error( "Null pointer to item" );

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( containerMutex );

 // If all pre-requisites are valid, add the item to this container
 ciList.push_back( p_item );

 TRACE_EXIT
}

bool ciContainer::getItem( const std::string & name, configurationItem ** p_item )
{
 bool ret = false;
 TRACE_ENTER

 if( p_item == nullptr ) throw_error( "Null configurationItem pointer" );

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( containerMutex );

 for( const auto & i : ciList )
	  if( i->equal( name ) )
	    {
		  // Return address of configurationItem and not the address in the item in the vector (item is pointer to object and not the object itself)
		  *p_item = i;
		  ret = true;
		  break;
	    }

 TRACE_EXIT

 return ret;
}


std::string & ciContainer::getName()
{
	return name;
}

};	// End of namespace "osapi"


