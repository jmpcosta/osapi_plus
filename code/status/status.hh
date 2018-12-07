// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Status module API
//
// *****************************************************************************************

#ifndef STATUS_PLUS_HH_
#define STATUS_PLUS_HH_


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

class status : public std::exception
{
public:
		explicit		status	( const char *, const char *, const char *	);
		explicit		status	( const std::string & message				);
						~status	();
		const char *	what() const noexcept;

private:
		std::string		reason;

		TRACE_CLASSNAME_DECLARATION
};


}

#endif /* STATUS_HH_ */
