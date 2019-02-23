// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide a argument CI type implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

// Import OSAPI++ generic headers
#include "status/trace.hh"

// Import own module declarations
#include "configuration/argItem.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{

namespace configuration
{


TRACE_CLASSNAME( argItem )


argItem::argItem( const std::string & arguments )
{
 TRACE_POINT
 arg = arguments;
}

argItem::~argItem()
{
 TRACE( "Destroying argument (", arg, ")" )
}

bool argItem::equal( const std::string & name )
{
 bool ret = false;

 if( name == arg )
   {
	 TRACE( "Found matching argument:", name )
	 ret = true;
   }

 return ret;
}

std::string const & argItem::getString() const
{
 return arg;
}


void argItem::setString( const std::string & value )
{
 TRACE( "Setting Property value (", value, ")" )

 arg = value;
}


}	// End of namespace "configuration"
}	// End of namespace "osapi"
