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

namespace configuration
{

TRACE_CLASSNAME( propertyItem )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


propertyItem::propertyItem( const std::string & name, const std::string & value ) : data( name, value )
{

 TRACE( "Creating property:|", name, "=", value, "|" )
}

propertyItem::~propertyItem()
{
  TRACE( "Destroying property:|", data.getName(), "|" )
}

std::string const & propertyItem::getString() const
{
 TRACE( "Returning value from property:|", data.getValue(), "|" )
 return data.getValue();
}

bool propertyItem::equal( const std::string & name )
{
 TRACE( "Comparing Properties (", name, "|", data.getName(), ")" )

 return ( data == name );
}


void propertyItem::setString( const std::string & value )
{
 TRACE( "Setting Property value (", value, ")" )

 data.setValue( value );
}


property & propertyItem::getAttribute( const std::string & name )
{
 TRACE_POINT

 for( auto & i: iAttributes )
	  if( i == name )
		  return i;

 throw status( "No attribute found" );
}


void propertyItem::addAttributes( std::vector<property> & attributes )
{
 // insert the new attributes at the end of the vector
 iAttributes.insert( std::end( iAttributes ), std::begin( attributes ), std::end( attributes ) );
}

void propertyItem::addAttribute( property & attribute )
{
 // Add the new attribute at the end of the vector
 iAttributes.push_back( attribute );
}

void propertyItem::deleteAttribute( const std::string & name )
{
 std::vector<property>::iterator i = iAttributes.begin();

 TRACE_ENTER

 for( ; i != iAttributes.end(); i++ )
    {
      if( (*i) == name )
    	  break;		// Attribute found
    }

 // If a CI exists, delete CI
 if( i != iAttributes.end() )
	 iAttributes.erase( i );

 TRACE_EXIT
}

}	// End of namespace "configuration"
}	// End of namespace "osapi"
