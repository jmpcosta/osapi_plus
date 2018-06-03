/*
 * property.cpp
 *
 *  Created on: 03/06/2018
 *      Author: joao
 */

#include <string>

#include "sistema/trace.hh"
#include "sistema/property.hh"

namespace osapi
{


property::property( std::string propName, std::string propValue )
{
 name = propName;
 value = propValue;
 TRACE_CLASSNAME( "property" )
 TRACE( "Creating property:|", name, "=", value, "|" )
}

property::~property()
{
  TRACE( "Destroing property:|", name, "|" )
}

const std::string & property::getValue()
{
 TRACE( "Returning value from property:|", value, "|" )
 return value;
}

bool property::equal( const std::string & compString )
{
 // Match only the part of the string name until it finds the index separator character
 size_t 		pos = name.find( property_index_separator );
 std::string 	str = name.substr(0, pos );

 TRACE( "Comparing Properties (", compString, "|", str, ")" )

 return ( compString == str );
}




}	// End of namespace "osapi"
