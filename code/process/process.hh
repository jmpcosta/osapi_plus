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

// Import OSAPI++ declarations
#include "general/general_types.hh"
#include "status/trace_macros.hh"


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

class process
 {
 public:
			// Constructor & Destructor
			process();
			~process();

	// Class methods (work on current process)
	static	intmax_t	getPID();
	static	intmax_t	getParentPID();
	static	bool		suspend();

 private:

		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "osapi"

#endif /* PROCESS_PROCESS_HH_ */
