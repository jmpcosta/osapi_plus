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



// *****************************************************************************************
//
// Section: OS module API declaration
//
// *****************************************************************************************


namespace osapi
{

class status : std::exception
{
public:
						status( int, const char *, const char *, const char * );
						status( const char *, const char *, const char * );
						status( int, uint8_t, uint8_t, const char * );
						status( const std::string message );
						~status();
		const char *	what() const noexcept;

private:
		std::string		reason;
};


}

#endif /* STATUS_HH_ */
