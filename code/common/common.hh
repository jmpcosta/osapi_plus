// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide the API for the Common module
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_HH_
#define OSAPI_COMMON_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

// Import OSAPI++ declarations
#include "general/types.hh"
#include "status/trace_macros.hh"

// Include own module headers

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

/// @brief Class that provides common (among functional modules) functionality
class common
{
public:
		/// @brief Split an input string in two using a string separator
		/// @param [in] input 	- The input string
		/// @param [in] sep 	- The string separator
		/// @param [out] out1 	- The first output string
		/// @param [out] out2 	- The second output string
		static void				splitString 	( const std::string & input, const char sep, std::string & out1, std::string & out2	);

		/// @brief Delete part of a string
		/// @param [in] what 	 	- The thing to erase
		/// @param [in] location 	- Start searching the what to erase in position location
		/// @param [in,out] where 	- The string to alter
		static void				stringEraser	( const std::string & what, size_t location, std::string & where				);

		/// @brief Transform a string into Upper case
		/// @param [in,out] str - The string to transform
		static void				toUpperCase		( std::string &	str																);

		/// @brief Transform a string into Lower case
		/// @param [in,out] str - The string to transform
		static void				toLowerCase		( std::string &	str																);

		/// @brief Translate a true or false boolean value into the respective string
		/// @param [in] value - The boolean to convert
		/// @return The boolean string
		static const char * 	bool2string 	( bool value																	);

		/// @brief Convert a Vector of strings into a vector of C-array
		///
		/// The call creates an array of char pointers to the C-strings from a vector of C++ strings. It doesn't copy those strings.
		/// @param [in]  source - Vector containing the C++ strings
		/// @param [out] target - The vector containing pointers to C-strings
		static void				vecStrings		( const std::vector<std::string> & source, std::vector<const char *> & target	);


private:

		TRACE_CLASSNAME_DECLARATION
};




}	// End of namespace "osapi"




#endif /* OSAPI_COMMON_HH_ */
