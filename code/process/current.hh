// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Defines a process interface from own process (inside view).
//			The API allows complete control of the available OS process services.
//
// *****************************************************************************************

#ifndef OSAPI_PROCESS_CURRENT_HH_
#define OSAPI_PROCESS_CURRENT_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <cstdint>
#include <string>
#include <vector>
#include <mutex>

// Import OSAPI++ declarations
#include "general/general.hh"
#include "status/trace_macros.hh"

// Import Module declarations
#include "process/signal.hh"
#include "process/plan_signal.hh"
#include "process/runner.hh"

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace process
{

/// @brief Specialization class with a single occurrence of a process to support the current working process
class Current : public planSignal, public runner
{
public:

	// Class methods (work on current process)
	/// @brief Get the current singleton instance (only one running process)
	/// @return The singleton instance
	static	Current &		 	get();

	// Instance methods
	/// @brief Clone the current process (Fork in UNIX systems)
	/// @param [out] isClone - Indicates if the current process is the clone or the original
	/// @return Operation status, True if cloned, false otherwise
	bool						clone		( bool & isClone	);

	/// @brief Terminate the current process
	/// @param [in] normal - The exit is a normal exit or not?
	[[noreturn]] void			terminate	( bool normal		);

	/// @brief Get the current process ID
	/// @return The own process ID
	int64_t						getPID();

	/// @brief Obtain the Process ID of the parent process
	/// @return The parent PID
	int64_t						getParentPID();

	/// @brief Promote itself as session leader
	/// @return Operation status, True if process was able to set itself as Session Leader. False otherwise.
	bool						setSession();

	/// @brief Suspend the current working process
	/// @return False if an error occurred, if suspended, upon resuming it will return True
	bool						suspend();

	// Signals
	/// @brief Clear all process signals disposition in the current process
	void						clearAllSignals();

	/// @brief Enable all planned signals disposition in the current process
	void						activateAllSignals();

	// delete copy and move constructors and assign operators
	Current( Current const & 	)			= delete;		// Copy construct
	Current( Current && 		)			= delete;		// Move construct
	Current& operator=( Current const&)		= delete; 		// Copy assign
	Current& operator=( Current &&	)		= delete;		// Move assign

private:

							    // Instance methods
								Current();
								~Current();

	// Instance variables
	std::mutex					procMutex;

	TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "process"

}	// End of namespace "osapi"

#endif /* OSAPI_PROCESS_CURRENT_HH_ */
