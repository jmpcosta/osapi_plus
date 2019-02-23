// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Defines a process interface for other processes (outside view).
//			Depending on the security privileges of the watcher, more or less information
//			can be retrieved from the target runner process.
//
// *****************************************************************************************

#ifndef OSAPI_PROCESS_RUNNER_HH_
#define OSAPI_PROCESS_RUNNER_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <cstdint>
#include <string>

// Import OSAPI++ declarations
#include "general/general.hh"
#include "status/trace_macros.hh"
#include "common/id.hh"

// Import own declarations
#include "process/state.hh"
#include "process/status.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace process
{



class runner
{
public:
			/// @brief Class constructor
			/// @param [in] pid - The process ID that the runner will represent
							runner			( int64_t pid		);

			/// @brief Class constructor
							runner			(					);

			/// @brief Class destructor
							~runner			(					);

			/// @brief Get the process ID of the runner instance
			/// @return Runner Process ID
			int64_t			getPID			( void				);

			/// @brief Obtain the parent process ID of the runner instance
			/// @return Parent Process ID
			int64_t			getParentPID	( void				);

			/// @brief Get the state of an existing process
			/// @return Process State
			state			getState		( void				);

			/// @brief Get the status of an existing process
			/// @return Process status
			status			getStatus		( void				);

			/// @brief Terminate a process
			/// @param [in] graceTime - The grace time between attempting a normal termination and a forced one.
			/// @return True if the process was terminated, false otherwise
			bool			terminate		( size_t graceTime	);

			/// @brief Check if a given process is running
			/// @param [in] pid - The ID to check
			/// @return True if the process exists. False otherwise.
			static bool		exists			( int64_t pid	);

protected:
			id::process 	id;

private:

	TRACE_CLASSNAME_DECLARATION
};



}	// End of namespace "process"

}	// End of namespace "osapi"

#endif /* OSAPI_PROCESS_RUNNER_HH_ */
