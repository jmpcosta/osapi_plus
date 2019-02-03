// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide propertyItem implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>

// Import OSAPI++ generic headers
#include "status/trace.hh"

// Import own module declarations
#include "configuration/propertyItem.hh"

// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{

TRACE_CLASSNAME( propertyItem )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


propertyItem::propertyItem( const std::string & propName, const std::string & propValue )
{
 name = propName;
 value = propValue;

 TRACE( "Creating property:|", name, "=", value, "|" )
}

propertyItem::~propertyItem()
{
  TRACE( "Destroying property:|", name, "|" )
}

const std::string & propertyItem::getString() const
{
 TRACE( "Returning value from property:|", value, "|" )
 return value;
}

bool propertyItem::equal( const std::string & propName )
{
 TRACE( "Comparing Properties (", propName, "|", name, ")" )

 return ( propName == name );
}


void propertyItem::setString( const std::string & propValue )
{
 TRACE( "Setting Property value (", propValue, ")" )

 value = propValue;
}



}	// End of namespace "osapi"
