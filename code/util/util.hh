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

class util
{
public:
		static void				splitString ( const std::string &, const char, std::string &, std::string & );
		static void				stringEraser( const std::string &, size_t,     std::string &				);
		static void				toUpperCase	( std::string &													);
		static void				toLowerCase	( std::string &													);
		static const char * 	bool2string ( bool value													);
		static bool				vecStr2array( const std::vector<std::string>, size_t *, char ***			);

private:
		TRACE_CLASSNAME_DECLARATION
};

};	// End of namespace "osapi"

#endif /* OSAPI_UTIL_HH_ */
