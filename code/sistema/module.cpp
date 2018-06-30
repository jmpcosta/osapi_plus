// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide "Module" implementation
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
#include "sistema/trace.hh"
#include "general/general_types.hh"

// Import own module declarations
#include "sistema/module.hh"


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{


std::string getModuleName( const std::string & rawPropertyName )
{
 std::string	module;

 // Check the propertyName for a namespace

 size_t pos = rawPropertyName.find( module_separator );

 if( pos == std::string::npos )
	 module = module_default_name;
 else
	 module  = rawPropertyName.substr( 0, pos  );

 STRACE( "Returning:|", module, "|" )

 return module;
}


std::string getPropertyName( const std::string & rawPropertyName )
{
 std::string	name;

 // Check the propertyName for a namespace

 size_t pos = rawPropertyName.find( module_separator );

 if( pos == std::string::npos )
	 name = rawPropertyName;
 else
	 name  = rawPropertyName.substr( pos+1, std::string::npos );

 STRACE( "Returning:|", name, "|" )

 return name;
}


} // End namespace osapi
