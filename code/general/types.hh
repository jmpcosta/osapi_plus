// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide General (cross module) module type declarations/definitions
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_TYPES_HH_
#define OSAPI_GENERAL_TYPES_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <common/object.hh>
#include <common/property.hh>
#include <functional>

// Include other more complex OSAPI types

// *****************************************************************************************
//
// Section: Type declaration/definition
//
// *****************************************************************************************


namespace osapi
{

/// @brief The empty string
///
/// The purpose of this string is to have a single place in memory to point to (instead of several places).
constexpr	char empty_string[]	= "";

/// @brief The string that represents the boolean value "true"
constexpr	char trueString[]	= "true";

/// @brief The string that represents the boolean value "false"
constexpr	char falseString[]	= "false";

// Useful type declaration for containers
using refConstStr = std::reference_wrapper<const std::string>;


};	// End of namespace "osapi"

#endif /* OSAPI_GENERAL_TYPES_HH_ */
