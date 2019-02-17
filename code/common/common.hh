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

class common
{
public:
		static void				splitString 	( const std::string &, const char, std::string &, std::string & 				);
		static void				stringEraser	( const std::string &, size_t,     std::string &								);
		static void				toUpperCase		( std::string &																	);
		static void				toLowerCase		( std::string &																	);
		static const char * 	bool2string 	( bool value																	);
		static bool				vecStr2array	( const std::vector<std::string> & vec, size_t * p_arraySize, char *** p_array	);
		static bool				vecRefStr2array	( const std::vector<refConstStr> & vec, size_t * arraySize, char *** array 		);
		static const char *		getVecRefString	( const std::vector<refConstStr> & vec, size_t index							);

private:

		TRACE_CLASSNAME_DECLARATION
};




}	// End of namespace "osapi"




#endif /* OSAPI_COMMON_HH_ */
