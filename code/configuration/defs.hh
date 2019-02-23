// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Configuration Module common definitions
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATION_DEFS_HH_
#define OSAPI_CONFIGURATION_DEFS_HH_

namespace osapi
{

namespace configuration
{

// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

/// @brief The file parser container/module separator
constexpr char module_separator[]	=	"|";
/// @brief The property/environment CI separator
constexpr char property_separator[]	=	"=";
/// @brief The CI specifier for properties
constexpr char property_token[]		=	"prop:";
/// @brief The CI specifier for arguments
constexpr char argument_token[]		=	"arg:";
/// @brief The CI specifier for environment variables
constexpr char environment_token[]	=	"env:";


}	// End of namespace "configuration"
}	// End of namespace

#endif /* OSAPI_CONFIGURATION_DEFS_HH_ */
