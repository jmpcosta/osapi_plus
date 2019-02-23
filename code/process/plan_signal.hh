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

/// @brief Class that represents a plan for setting process signals
class planSignal
{
public:
		/// @brief Class constructor
							planSignal();

		/// @brief Class destructor
							~planSignal();

		/// @brief Add a new signal to the plan
		/// @param [in] sig - The new signal to add
		void 				addSignal		( process::signal  & sig	);

		/// @brief Remove one signal from the plan
		/// @param [in] signo - The signal number to add
		void				eraseSignal 	( int signo					);

		/// @brief Remove all signals from the plan
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
