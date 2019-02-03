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
#include "general/general_types.hh"
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

// Specialization class with a single occurrence of a process to support the current working process
class Current : public planSignal, public runner
{
public:

	// Class methods (work on current process)
	static	Current &		 	get();

	// Instance methods
	bool						clone		( bool & isClone	);
	[[noreturn]] void			terminate	( bool status		);

	int64_t						getPID();
	int64_t						getParentPID();
	bool						setSession();
	bool						suspend();

	// Signals
	void						clearAllSignals();
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
