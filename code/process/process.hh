// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Process module API
//
// *****************************************************************************************

#ifndef PROCESS_PROCESS_HH_
#define PROCESS_PROCESS_HH_

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
#include "general/general_types.hh"
#include "status/trace_macros.hh"

// Import Module declarations
#include "process/signal.hh"

// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

constexpr char module[] = "Process";

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

class CurrentProcess;

class process
{
public:
	// Class methods
	static CurrentProcess &	getCurrent();

						// Constructor & Destructor
						process();
						~process();

	void 				addSignal		( signal & sig	);
	void				eraseSignal 	( int signo		);
	void				eraseAllSignals	( void			);

protected:
		// Instance variables
		std::vector<osapi::signal>	sigList;
		std::mutex					signalMutex;
private:

		TRACE_CLASSNAME_DECLARATION
};


// Specialization class with a single occurrence of a process to support the current working process
class CurrentProcess : public process
{
public:

	// Class methods (work on current process)
	static CurrentProcess & getInstance();

	// Instance methods
	unsigned long	getPID();
	unsigned long	getParentPID();
	bool			suspend();
	// Signals
	void			clearSignals();
	void			activateSignals();

	void			activateAll();	// Activate all planed settings

	// delete copy and move constructors and assign operators
	CurrentProcess( CurrentProcess const & 	)			= delete;		// Copy construct
	CurrentProcess( CurrentProcess && 		)			= delete;		// Move construct
	CurrentProcess& operator=( CurrentProcess const&)	= delete; 		// Copy assign
	CurrentProcess& operator=( CurrentProcess &&	)	= delete;		// Move assign

private:

						// Instance methods
						CurrentProcess();
						~CurrentProcess();

		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "osapi"

#endif /* PROCESS_PROCESS_HH_ */
