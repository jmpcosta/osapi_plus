// *********************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide process state information
//
// **********************************************************************************************************

#ifndef OSAPI_PROCESS_STATE_HH_
#define OSAPI_PROCESS_STATE_HH_

// **********************************************************************************************************
//
// Section: Define possible process states (i.e. generalization of all states from all supported platforms).
//			The enum bellow must be a copy of the corresponding OSAPI C header file: proc_state.h
//
// **********************************************************************************************************

namespace osapi
{

namespace process
{

/// @brief The state enum represents the possible process states
enum class state
{
  inexistent	= 0, ///< Unknown process state, possible the process doesn't exist
  running		= 1, ///< The process is still running
  terminated	= 2, ///< The process terminated and waits status collection
  waiting		= 3, ///< The process is waiting for something (IO for instance)
  stopped		= 4  ///< The process is currently stopped
};



}	// End of namespace "process"

}	// End of namespace "osapi"


#endif /* OSAPI_PROCESS_STATE_HH_ */
