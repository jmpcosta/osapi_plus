/*
 * propertyContainer.cpp
 *
 *  Created on: 13/05/2018
 *      Author: joao
 */

#include <vector>

#include "status/status.hh"
#include "util/util.hh"
#include "sistema/trace.hh"
#include "sistema/property.hh"
#include "sistema/module.hh"
#include "sistema/propertyContainer.hh"


namespace osapi
{

// Definition of Constructor & Destructor

propertyContainer::propertyContainer( const std::string & containerName )
{
	TRACE_CLASSNAME( "propertyContainer" )

	name = containerName;
	TRACE( "Creating Container name:|", name, "|" )
}

propertyContainer::~propertyContainer()
{
	TRACE( "Destroying container:|", name, "|" )

	for( const auto & i : propertyList )  delete i;
}

void propertyContainer::addProperty( const std::string & propertyName, const std::string & propertyValue )
{
 std::string errorMsg("");

 TRACE_ENTER

 if( propertyName.size()  == 0 ) errorMsg = "Invalid Property Name";

 if( propertyValue.size() == 0 ) errorMsg = "Invalid Property Value";

 if( errorMsg.size() != 0 )
	 throw new status( errorMsg );

 // If all pre-requisites are valid, add the property to this container
 propertyList.push_back( new property( propertyName, propertyValue ) );

 TRACE_EXIT
}



bool propertyContainer::equal( const std::string & container )
{
  return ( name == container );
}


bool propertyContainer::getProperty( const std::string & name, std::vector<std::string> & values )
{
 TRACE_ENTER

   for( const auto & i : propertyList )
      {
	    // Property name matches, add to result vector
    	if( i->equal( name ) )
    	  {
    		TRACE( "Found matching property:|", name, "|" )

    	    values.push_back( i->getValue() );

    		TRACE( "Containing returning property Value:|", i->getValue() , "|" )
    	  }
      }

 TRACE_EXIT

 return ( (values.size() == 0 ) ? false: true );
}


};	// End of namespace "osapi"


