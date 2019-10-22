// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Util module API
//
// *****************************************************************************************


#ifndef OSAPI_UTIL_HH_
#define OSAPI_UTIL_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

// Import OSAPI headers
#include "status/trace_macros.hh"

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

/// @brief Class that provides utility functions
class util
{
public:

		/// @brief Split an input string in two using a string separator
		/// @param [in] input 	- The input string
		/// @param [in] sep 	- The string separator
		/// @param [out] out1 	- The first output string
		/// @param [out] out2 	- The second output string
		static void				splitString ( const std::string & input, const char sep, std::string & out1, std::string & out2 );

		/// @brief Delete part of a string
		/// @param [in] what 	 	- The thing to erase
		/// @param [in] location 	- Start searching the what to erase in position location
		/// @param [in,out] where 	- The string to alter
		static void				stringEraser( const std::string & what, size_t location, std::string & where );

		/// @brief Transform a string into Upper case
		/// @param [in,out] str - The string to transform
		static void				toUpperCase	( std::string &	str	);

		/// @brief Transform a string into Lower case
		/// @param [in,out] str - The string to transform
		static void				toLowerCase	( std::string &	str	);

		/// @brief Translate a true or false boolean value into the respective string
		/// @param [in] value - The boolean to convert
		/// @return The boolean string
		static const char * 	bool2string ( bool value );


private:
		TRACE_CLASSNAME_DECLARATION
};

};	// End of namespace "osapi"

#endif /* OSAPI_UTIL_HH_ */
