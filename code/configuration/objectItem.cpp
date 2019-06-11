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
#include "general/types.hh"
#include "status/trace.hh"

// Import own module declarations
#include "configuration/objectItem.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{

namespace configuration
{


TRACE_CLASSNAME( objectItem )


objectItem::objectItem( osapi::object * p_obj )
{
 TRACE_POINT

 // Sanity checks
 if( p_obj == nullptr )
	 throw std::invalid_argument( "Object Pointer is null" );

 iObject 	= p_obj;
 iName 		= iObject->getName();	// For easier access
}

objectItem::~objectItem()
{
 TRACE( "Destroying argument (", iName, ")" )
}

bool objectItem::equal( const std::string & name )
{
 bool ret = false;

 if( name == iName )
   {
	 TRACE( "Found matching argument:", name )
	 ret = true;
   }

 return ret;
}

std::string const & objectItem::getString() const
{
 return iName;
}


void objectItem::setString( const std::string & name )
{
 TRACE( "Setting Property value (", name, ")" )

 iName = name;
}


osapi::object *	objectItem::getObject()
{
 TRACE_POINT

 return iObject;
}


}	// End of namespace "configuration"
}	// End of namespace "osapi"
