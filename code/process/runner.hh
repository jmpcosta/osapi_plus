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
#include "general/general_types.hh"
#include "status/trace_macros.hh"
#include "common/id.hh"

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
							// Constructor & Destructor
							runner			( int64_t pid	);
							runner			(				);
							~runner			(				);

			int64_t			getPID			(				);
			int64_t			getParentPID	(				);

			static bool		exists			( int64_t pid	);

protected:
			id::process 	id;

private:

	TRACE_CLASSNAME_DECLARATION
};



}	// End of namespace "process"

}	// End of namespace "osapi"

#endif /* OSAPI_PROCESS_RUNNER_HH_ */
