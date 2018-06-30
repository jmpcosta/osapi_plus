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
#include "util/util.hh"
#include "sistema/trace.hh"
#include "sistema/module.hh"
#include "sistema/propertyContainer.hh"

// Import own module declarations
#include "sistema/propertiesProvider.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{

// Class methods

PropertiesProvider & PropertiesProvider::getProvider()
{
	static	PropertiesProvider instance;

	return instance;
}

// Instance Methods

// First, private methods

// Private Constructor
PropertiesProvider::PropertiesProvider()
{
	TRACE_CLASSNAME( "PropertiesProvider" )
	TRACE_POINT
}

// Private Destructor
PropertiesProvider::~PropertiesProvider()
{
	TRACE_ENTER

	for( const auto & i : containerList )
		 delete i;

	TRACE_EXIT
}

bool PropertiesProvider::parsePropertyName( const std::string & fullname, std::string & module, std::string & name )
{
	TRACE_ENTER

	module = getModuleName   ( fullname );
	name   = getPropertyName ( fullname );

	TRACE( "Module:",        module.c_str() )
	TRACE( "Property Name:", name.c_str()   )

	TRACE_EXIT

	return ( name.size()? true : false );
}

bool PropertiesProvider::parseLine( const std::string & line, std::string & module, std::string & name, std::string & value )
{
 std::string fullname;

 TRACE_ENTER

	util::splitString( line, property_file_separator, fullname, value );

	if( fullname.size() == 0 || value.size() == 0 ) return false;	// There is no property in this line

	TRACE( "line:",     line     )
	TRACE( "fullname:", fullname )
	TRACE( "value:",    value    )

	util::toUpperCase( fullname );

	TRACE_EXIT

	return parsePropertyName( fullname, module, name );
}


// Second, Public methods

propertyContainer * PropertiesProvider::newContainer( const std::string & containerName )
{
	TRACE_ENTER

	propertyContainer * pc = new propertyContainer( containerName );
  	containerList.push_back( pc  );

  	TRACE_EXIT

  	return pc;
}


void PropertiesProvider::importProperties( const std::string & pathname )
{
	std::string module, fullname, name, value;

	TRACE_ENTER

    TRACE( "Reading:", pathname )
	std::ifstream propFile( pathname );

	// Process system property file
	for( std::string line; std::getline( propFile, line ); )
	   {
	     if( line.length() )
	       {
	    	 if( parseLine( line, module, name, value ) )		// Add a new property to the list of system properties
	    	   {
		    	 TRACE( "New property:", module, "$", name, "=", value )
	    		 addProperty( module, name, value );
	    	   }
	       }
	   }

	TRACE_EXIT
}

// Central Point of property management - The following two methods

void PropertiesProvider::addProperty( const std::string & module, const std::string & propName, const std::string & propValue )
{
  TRACE_ENTER

  std::string mod  = module;
  std::string name = propName;

  util::toUpperCase( mod  );
  util::toUpperCase( name );

  TRACE( "Module:",        mod.c_str()  )
  TRACE( "Property Name:", name.c_str() )


  provMutex.lock();

  for( auto & i : containerList )
     {
	   if( i->equal( mod ) )			// Is the current container name the same as "module" name
	     {
		   i->addProperty( name, propValue );
		   provMutex.unlock();
		   TRACE_EXIT
		   return;
	     }
     }

  // If there is no existent container already, create one
  newContainer( mod )->addProperty( name, propValue );

  provMutex.unlock();

  TRACE_EXIT
}

// Output is vector of string references
bool PropertiesProvider::getPropertyValues( const std::string & module, const std::string & name, std::vector<std::string> & values )
{
  bool result = false;

  TRACE_ENTER

  std::string mod  = module;
  std::string prop = name;

  util::toUpperCase( mod  );
  util::toUpperCase( prop );

  TRACE( "Module:",        mod.c_str()  )
  TRACE( "Property Name:", prop.c_str() )


  provMutex.lock();

  for( const auto & i : containerList )
     {
	   // Is the current container name the same as "module" name
	   if( i->equal( mod ) )
	     {
		   TRACE( "Module found" )
		   result = i->getProperty( prop, values );
		   break;
	     }
	 }

  provMutex.unlock();

  TRACE( "Last result:|", util::bool2string( result ) , "|" )

  TRACE_EXIT

  return result;
}

// The following methods are wrappers to one of the two above

void PropertiesProvider::addProperty( const std::string & propertyName, const std::string & propertyValue )
{
  std::string	module, propName;

  TRACE_ENTER

  module   = getModuleName   ( propertyName );
  propName = getPropertyName ( propertyName );

  // Invoke own more specific addProperty method
  addProperty( module, propName, propertyValue );

  TRACE_EXIT
}


bool PropertiesProvider::getPropertyValues( const std::string & propertyName, std::vector<std::string> & values )
{
 std::string	module, propName;

 TRACE_ENTER

 module   = getModuleName   ( propertyName );
 propName = getPropertyName ( propertyName );

 // Invoke own more specific getPropertyValue method
 return getPropertyValues( module, propName, values );
}



};	// End of namespace "osapi"


