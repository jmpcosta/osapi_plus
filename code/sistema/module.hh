/*
 * module.hh
 *
 *  Created on: 26/05/2018
 *      Author: joao
 */

#ifndef CODE_SISTEMA_MODULE_HH_
#define CODE_SISTEMA_MODULE_HH_

#include <string>

namespace osapi
{

// Module constants
constexpr char module_separator			= '$';
constexpr char module_default_name[]	= "default";

// Utility function

std::string getModuleName   ( const std::string & rawPropertyName );
std::string getPropertyName ( const std::string & rawPropertyName );


} // End of namespace "osapi"

#endif /* CODE_SISTEMA_MODULE_HH_ */
