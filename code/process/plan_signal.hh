// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide common process functionality
//
// *****************************************************************************************

#ifndef OSAPI_PROCESS_COMMON_HH_
#define OSAPI_PROCESS_COMMON_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>
#include <mutex>
#include <memory>

// Import OSAPI++ declarations
#include "general/general.hh"
#include "status/trace_macros.hh"

// Include own headers
#include "process/signal.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace process
{

// Alias to make it easier to read
using signal_list = std::vector<process::signal>;

class planSignal
{
public:
							planSignal();
							~planSignal();

		// Add data to the instance
		void 				addSignal		( process::signal  & sig	);

		// Remove data from the instance
		void				eraseSignal 	( int signo					);
		void				eraseAllSignals	( void						);


protected:
		// Instance variables

		signal_list			sigList;
		std::mutex			signalMutex;

private:

		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "process"

}	// End of namespace "osapi"

#endif /* OSAPI_PROCESS_COMMON_HH_ */
