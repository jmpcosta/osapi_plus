/*
 * module.cpp
 *
 *  Created on: 26/05/2018
 *      Author: joao
 */

#include <string>

#include "general/general_defs.hh"
#include "sistema/trace.hh"
#include "sistema/module.hh"

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
