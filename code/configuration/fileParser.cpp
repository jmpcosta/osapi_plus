// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose: Module definitions for parsing items through a configuration file
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>

// Import OSAPI+ headers
#include "status/trace_macros.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import configuration headers
#include "configuration/item.hh"
#include "configuration/argItem.hh"
#include "configuration/propertyItem.hh"
#include "configuration/container.hh"
#include "configuration/configuration.hh"
#include "configuration/Provider.hh"

// Include own headers
#include "configuration/defs.hh"
#include "configuration/fileParser.hh"



namespace osapi
{

namespace configuration
{

// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

TRACE_CLASSNAME( fileParser )

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


fileParser::fileParser()
{
 TRACE_POINT
}

fileParser::~fileParser()
{
 TRACE( "Destroying instance" )
}

bool fileParser::isType( const char * const token, const std::string & entry )
{
 bool ret = false;

 TRACE( "Entering isType with token=", token, " and entry=", entry )

 if( token == nullptr )
     throw_error( "Null pointer in call !" );	// This shouldn't happen
 else
   {
	 size_t pos = entry.find( token );

	 if( pos == 0 )		// The token must start in the first position of the string
	   {
		 TRACE("Found token at position:", pos )
    	 ret = true;
	   }
   }

 TRACE_EXIT

 return ret;
}


ciType fileParser::getEntryType( const std::string & entry )
{
 ciType type = ciType::UNKNOWN;

 TRACE( "Entering getEntryType with entry=", entry )

 if( isType( argument_token, entry ) )
   {
	 type = ciType::ARGUMENT;
	 TRACE( "Type=Argument" )
   }
 else
 if( isType( environment_token, entry ) )
   {
	 type = ciType::ENVIRONMENT;
	 TRACE( "Type=Environment" )
   }
 else
 if( isType( property_token, entry ) )
   {
	 type = ciType::PROPERTY;
	 TRACE( "Type=Property" )
   }

 TRACE_EXIT

 return type;
}

void fileParser::removeToken( const char * const token, std::string & entry )
{
 TRACE( "Entering isType with token:", token, " and entry=", entry )

 if( token != nullptr )
   {
     size_t len = strlen( token );
     entry.erase( 0, len );
   }

 TRACE( "Leaving with entry=", entry )
}


void fileParser::splitProperty( const std::string & entry, size_t where, std::string & name, std::string & value )
{
 name  = entry.substr( 0, where  );
 TRACE( "Name (", name, ")" )

 value = entry.substr( where + 1 );
 TRACE( "Value (", value, ")" )
}

item * fileParser::make_arg( const std::string & entry )
{
 argItem * p_item = nullptr;

 TRACE_ENTER

 // An argument uses the entire entry as the value
 if( entry.size() > 0 )
   {
	 TRACE( "Allocating new argument CI in heap" )
	 p_item = new argItem( entry );
   }

 TRACE("Exiting with pointer value=", p_item )

 return (item *) p_item;
}

item * fileParser::make_env( const std::string & entry )
{
 propertyItem *	p_item	= nullptr;
 size_t			where	= 0;

 TRACE_ENTER

 // An environment uses a property CI
 where = entry.find( property_separator );

 if( where <= 1 ) 	// There is a valid property name
	 std::cerr << "Unable to find environment separator" <<  std::endl;
 else
   {
	 std::string name, value;
	 splitProperty( entry, where, name, value );

	 TRACE( "Environment: name(", name, ") and value(", value, ")." )

	 if( name.size() > 0 && value.size() > 0 )
	   {
		 TRACE( "Allocating new environment CI in heap" )
		 p_item = new propertyItem( name, value );
	   }
   }

 TRACE("Exiting with pointer value=", p_item )

 return (item *) p_item;
}

item * fileParser::make_prop( const std::string & entry )
{
 propertyItem *	p_item	= nullptr;
 size_t			where	= 0;

 TRACE_ENTER

 // An environment uses a property CI
 where = entry.find( property_separator );

 if( where <= 1 ) 	// There is a valid property name
	 std::cerr << "Unable to find environment separator" <<  std::endl;
 else
   {
	 std::string name, value;
	 splitProperty( entry, where, name, value );

	 TRACE( "Property: name(", name, ") and value(", value, ")." )

	 if( name.size() > 0 && value.size() > 0 )
	   {
		 TRACE( "Allocating new property CI in heap" )
		 p_item = new propertyItem( name, value );
	   }

   }

 TRACE("Exiting with pointer value=", p_item )

 return (item *) p_item;
}


bool fileParser::generateItem( ciType type, std::string & entry, item ** p_item )
{
 TRACE_ENTER

 switch( type )
 	   {
 	 	 case ciType::ARGUMENT: 	removeToken( argument_token, entry );
 	 	 	 	 	 	 	 	 	*p_item = make_arg( entry );
 	 	 	 	 	 	 	 	 	break;

 	 	 case ciType::ENVIRONMENT:	removeToken( environment_token, entry );
 	 	 	 	 	 	 	 	 	*p_item = make_env( entry );
 	 	 	 	 	 	 	 	 	break;

 	 	 case ciType::PROPERTY:		removeToken( property_token, entry );
 	 	 	 	 	 	 	 	 	*p_item = make_prop( entry );
 	 	 	 	 	 	 	 	 	break;

 	 	 default:					TRACE( "No type found !" )
 	 		 	 	 	 	 	 	break;
 	   }

 TRACE("Exiting with pointer value=", *p_item )

 // Sanity check
 if( *p_item == nullptr )	return false;
 else						return true;
}



bool fileParser::parseEntry( std::string & entry, item ** p_item )
{
 bool 		ret 	= false;

 TRACE( "Entering with entry (", entry, ") and pointer value=", *p_item )

 ciType	type	= getEntryType( entry );
 ret			= generateItem( type, entry, p_item );

 TRACE("Exiting with pointer value=", *p_item )

 return ret;
}



bool fileParser::parseLine( const std::string & line, std::string & module, std::string & entry )
{
 bool	ret = false;

 TRACE_ENTER

 // First split line between module and module entry
 size_t pos = line.find( module_separator );

 // Retrieve module name and entry
 if( pos == std::string::npos )
   {
	 module = container::getDefaultName();
	 entry  = line;
   }
 else
   {
	 size_t	len = line.size();

	 module = line.substr( 0,   pos     );
	 entry  = line.substr( pos + 1, len - 1 );
   }

 if( module.size() > 0 && entry.size() > 0 )
	 ret = true;

 TRACE( "Module(", module, ") and entry(", entry, ") with result=", ret, "." )

 TRACE_EXIT

 return ret;
}


void fileParser::processLine( const std::string & line, configuration & conf )
{
 TRACE_ENTER

 std::string module, entry;

 if( parseLine( line, module, entry ) )
   {
	 TRACE( "Module(", module, ") and entry(", entry, ")." )

	 item * p_item = nullptr;
	 if( parseEntry( entry, & p_item ) )
	   {
		 TRACE("CI pointer value=", p_item )
   		 conf.addContainer( module).addItem( p_item );
	   }
   }

 TRACE_EXIT
}


void fileParser::import( const std::string & from, std::string & into )
{
 TRACE( "Entering with", from, " and", into )

 std::ifstream input_file;

 if( from.size() > 0 && into.size() > 0 )
     input_file.open( from.c_str() );

 if(  input_file.is_open() )
   {
	 std::string line;
	 unsigned int lineCounter = 0;	// Only to support traccing

	 // Get a reference for the target configuration for faster processing
	 configuration & conf = Provider::getProvider().addConfiguration( into );

	 while(  ! input_file.eof() && ! input_file.fail() )
	      {
		    getline( input_file, line );
	    	lineCounter++;

		    if( ! input_file.fail() && ! line.empty() )
		      {
			    TRACE( lineCounter, ": Reading line(", line, ")" )
			    processLine( line, conf );
		      }
	      }

	 input_file.close();
   }

 TRACE_EXIT
}




}	// End of namespace "configuration"
}	// End of osapi namespace

