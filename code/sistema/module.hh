// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide system module declarations/definitions
//
// *****************************************************************************************

#ifndef SISTEMA_MODULE_HH_
#define SISTEMA_MODULE_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>


namespace osapi
{

// *****************************************************************************************
//
// Section: Constant section
//
// *****************************************************************************************

// Module constants
constexpr char module_separator			= '$';
constexpr char module_default_name[]	= "default";


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

// Utility functions
std::string getModuleName   ( const std::string & rawPropertyName );
std::string getPropertyName ( const std::string & rawPropertyName );


} // End of namespace "osapi"

#endif /* SISTEMA_MODULE_HH_ */
