// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide signal module API
//
// *****************************************************************************************

#ifndef OSAPI_PROCESS_SIGNAL_HH_
#define OSAPI_PROCESS_SIGNAL_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Standard C++ headers
#include <cstdint>
#include <csignal>

// Import OSAPI++ declarations
#include "general/general.hh"
#include "status/trace_macros.hh"



// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

// Redefine signal handler function (must match OSAPI and ANSI C definitions)
//typedef void (* signal_function)( int );

enum class signalSupportLevel { unsupported, ansi, posix, realTime };


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace process
{

/// @brief Class responsible for the signal concept
class signal
 {
 public:

	/// @brief Are signals supported, and if so, to which level?
	/// @param [out] level - The signal support level
	/// @return True if there is any support of signals in the OSAPI C platform implementation. False otherwise.
	static	bool	isSupported		( signalSupportLevel & level );

	/// @brief Destructor
					~signal			();

	/// @brief Constructor
	/// @param [in] number - The signal number for which the instance will be built.
					signal			( int number			);

	/// @brief Is the signal the same? The matching is based on the signal number
	/// @param [in] number - The signal number
	/// @return True if signals match. False otherwise.
	bool			equal			( int number			);

	/// @brief Get the signal number from the signal instance
	/// @return Signal number
	int				getNumber		( void					);

	/// @brief Set handler function to call upon signal reception
	/// @param [in] func - Function name
	void 			setHandler		( sighandler_t func		);

	/// @brief Clear any function handler set for this signal instance
	void 			clearHandler	( void					);

	/// @brief Get the function handler/address for this signal instance
	/// @return The function handler
	sighandler_t	getHandler		( void					);

	/// @brief Check if there is a valid handler for this signal instance
	/// @return True if handler valid, false otherwise
	bool			hasValidHandler	( void					);


private:
	// Instance variables
	int						sigNumber;
	sighandler_t			sigHandler;

	TRACE_CLASSNAME_DECLARATION
};




}	// End of namespace "process"

}	// End of namespace "osapi"


#endif /* OSAPI_PROCESS_SIGNAL_HH_ */

