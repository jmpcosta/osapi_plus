// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Log module API declaration
//
// *****************************************************************************************

#ifndef LOG_LOG_HH_
#define LOG_LOG_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <mutex>

// Import OSAPI headers
#include "status/trace_macros.hh"

// *****************************************************************************************
//
// Section: OS module API declaration
//
// *****************************************************************************************

namespace osapi
{

class Log
{
public:

		// delete copy and move constructors and assign operators
		Log( Log const& ) 				= delete;		// Copy construct
		Log( Log&&      ) 				= delete;		// Move construct
		Log& operator=( Log const& )	= delete; 		// Copy assign
		Log& operator=( Log &&     )	= delete;		// Move assign

	// Class methods
	static bool		isLogAvailable();
	static Log &	getLog();

	// Instance methods
					~Log	();

	// Log administration operations
	void 			open	( const char * source, const char * target, const char * options[] );
	void 			close	();

	// Log with a certain Log level
	void			debug	( const char * message	);
	void			info	( const char * message	);
	void			warn	( const char * message	);
	void			error	( const char * message	);
	void			fatal	( const char * message	);

	// Wrapper for the previous functions
	void			debug	( std::string &	message	);
	void			info	( std::string &	message	);
	void			warn	( std::string &	message	);
	void			error	( std::string &	message	);
	void			fatal	( std::string &	message	);

private:

					Log();
	std::mutex		openMutex;		// Block attempt by multiple threads to open the system log at the same time
	void *			p_log;			// void pointer to avoid using C OSAPI headers in C++ interface

	// Class variables
	static bool						logAvailable;

	TRACE_CLASSNAME_DECLARATION
};


};	// End of namespace "osapi"

#endif /*LOG_LOG_HH_ */
