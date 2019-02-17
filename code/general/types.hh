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
#include <functional>

// *****************************************************************************************
//
// Section: Type declaration/definition
//
// *****************************************************************************************


namespace osapi
{

constexpr	char empty_string[]	= "";
constexpr	char trueString[]	= "true";
constexpr	char falseString[]	= "false";

// Useful type declaration for containers

using refConstStr = std::reference_wrapper<const std::string>;

};	// End of namespace "osapi"

#endif /* OSAPI_GENERAL_TYPES_HH_ */
