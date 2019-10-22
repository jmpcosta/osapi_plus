// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Process module API
//
// *****************************************************************************************

#ifndef PROCESS_PLAN_HH_
#define PROCESS_PLAN_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>
#include <mutex>

// Import OSAPI++ declarations
#include "general/general.hh"
#include "status/trace_macros.hh"

// Include own module headers
#include "process/plan_signal.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace process
{

/// @brief Class that represents a process plan
///
/// A process plan is a blueprint for the creation of a new process
class plan : public planSignal
{
public:
		/// @brief Class constructor
							plan();

		/// @brief Class destructor
							~plan();

		/// @brief Get access to the OSAPI C plan type
		/// @return Pointer to the OSAPI C type/structure containing the information about the planned process plan
		void *				getRaw			( void );

		// Add data to the instance
		/// @brief Add a command line for the planned process
		/// @param [in] line - The planned command line
		/// @return Operation status, True if successful, False otherwise
		bool 				addCommandLine	( const std::vector<const char *> & line	);

		/// @brief Add a process environment for the planned process
		/// @param [in] env - The planned process environment
		/// @return Operation status, True if successful, False otherwise
		bool				addEnvironment	( const std::vector<const char *> & env );

		/// @brief Add the User ID under which the process will run
		/// @param [in] user - User ID
		/// @return Operation status, True if successful, False otherwise
		bool				addUser			( const std::string & user );

		/// @brief Add the Group ID under which the process will run
		/// @param [in] group - Group ID
		/// @return Operation status, True if successful, False otherwise
		bool				addGroup		( const std::string & group	);

		/// @brief Set the Process runtime name
		/// @param [in] name - Process name
		/// @return Operation status, True if successful, False otherwise
		bool				addName			( const std::string & name );

		// Retrieve data from the instance
		/// @brief Get a command line from the planned process
		/// @return The command line as a vector of pointers to C-strings
		bool				getCommandLine	( std::vector<const char *> & cmdLine );

		/// @brief Get the process environment from the planned process
		/// @return The process environment as a vector of pointers to C-strings
		bool				getEnvironment	( std::vector<const char *> & env	);
		/*
		std::string			getUser			( void 								);
		std::string			getGroup		( void 								);
		*/

		/// @brief Get the Process runtime name
		/// @return The name of the planned process
		char *				getName			( void 								);

		// Get information from a raw process structure

		/// @brief
		std::string			getStringPID( void );
		std::string			getStringUID( void );
		std::string			getStringGID( void );


private:
		// Instance variables
		void	*	rawData;

		std::mutex						procMutex;

		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "process"

}	// End of namespace "osapi"

#endif /* PROCESS_PLAN_HH_ */
