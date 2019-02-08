// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide process state information
//
// *****************************************************************************************

#ifndef OSAPI_PROCESS_STATE_HH_
#define OSAPI_PROCESS_STATE_HH_

// *****************************************************************************************
//
// Section: Define possible process states
//			The enum bellow must be a copy of the corresponding OSAPI C header file: proc_state.h
//
// *****************************************************************************************

namespace osapi
{

namespace process
{


enum process_state
{
  inexistent	= 0,
  running		= 1,
  terminated	= 2,
  waiting		= 3,
  stopped		= 4
};



}	// End of namespace "process"

}	// End of namespace "osapi"


#endif /* OSAPI_PROCESS_STATE_HH_ */
