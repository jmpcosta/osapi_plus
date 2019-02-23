// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module API
//
// *****************************************************************************************

#ifndef OSAPI_STATUS_HH_
#define OSAPI_STATUS_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <stdexcept>

// Import own module macros
#include "status/trace_macros.hh"


// *****************************************************************************************
//
// Section: OS module API declaration
//
// *****************************************************************************************


namespace osapi
{

/// @brief Class responsible for reporting OSAPI C++ exceptions
class status : public std::exception
{
public:

		/// @brief Constructor to support the OSAPI C API
		///
		/// Parameters are not described since these should not be used by OSAPI C++ client applications
		explicit		status	( const char *, const char *, const char *	);

		/// @brief Constructor to support the OSAPI C++ API
		explicit		status	( const std::string & message				);

		/// @brief Destructor
						~status	();

		/// @brief Override the parent what method
		/// @return Get the exception explanation
		const char *	what() const noexcept;

private:
		std::string		reason;

		TRACE_CLASSNAME_DECLARATION
};


}

#endif /* OSAPI_STATUS_HH_ */
