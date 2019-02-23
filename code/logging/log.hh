// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Log module API declaration
//
// *****************************************************************************************

#ifndef OSAPI_LOG_HH_
#define OSAPI_LOG_HH_

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

/// @brief Class responsible for interfacing with the platform system logging framework, if it exists.
class Log
{
public:

		// delete copy and move constructors and assign operators
		Log( Log const& ) 				= delete;		// Copy construct
		Log( Log&&      ) 				= delete;		// Move construct
		Log& operator=( Log const& )	= delete; 		// Copy assign
		Log& operator=( Log &&     )	= delete;		// Move assign

	// Class methods
	/// @brief Check if there is already a log instance available
	/// @return Available (true) or not (false)
	static bool		isLogAvailable();

	/// @brief Get the singleton log instance
	/// @return A reference to the system log instance
	static Log &	getLog();

	// Instance methods
	/// @brief Destructor
					~Log	();

	// Log administration operations
	/// @brief Open the system log
	/// @param [in] source	- The log source, for instance, the program name
	/// @param [in] target	- Log target such as LOG_LOCAL0 in UNIX systems
	/// @param [in] options	- Any option to pass to the system logger such as LOG_PID, in UNIX systems
	void 			open	( const char * source, const char * target, const char * options[] );

	/// @brief Close the system log
	void 			close	();

	// Log with a certain Log level

	/// @brief Log a message at level DEBUG
	/// @param [in] message
	void			debug	( const char * message	);

	/// @brief Log a message at level INFO
	/// @param [in] message
	void			info	( const char * message	);

	/// @brief Log a message at level WARNING
	/// @param [in] message
	void			warn	( const char * message	);

	/// @brief Log a message at level ERROR
	/// @param [in] message
	void			error	( const char * message	);

	/// @brief Log a message at level FATAL
	/// @param [in] message
	void			fatal	( const char * message	);

	// Wrapper for the previous functions

	/// @brief Log a message at level DEBUG
	/// @param [in] message
	void			debug	( std::string &	message	);

	/// @brief Log a message at level INFO
	/// @param [in] message
	void			info	( std::string &	message	);

	/// @brief Log a message at level WARNING
	/// @param [in] message
	void			warn	( std::string &	message	);

	/// @brief Log a message at level ERROR
	/// @param [in] message
	void			error	( std::string &	message	);

	/// @brief Log a message at level FATAL
	/// @param [in] message
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

#endif /*OSAPI_LOG_HH_ */
