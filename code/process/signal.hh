// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide signal module API
//
// *****************************************************************************************

#ifndef PROCESS_SIGNAL_HH_
#define PROCESS_SIGNAL_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Generic OSAPI includes

// Standard C++ headers
#include <cstdint>

// Import OSAPI++ declarations
#include "general/general_types.hh"
#include "status/trace_macros.hh"



// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

// Redefine signal handler function (must match OSAPI definition)
typedef void (* signal_function)( int );


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

class signal
 {
 public:
					// Constructor & Destructor
					~signal();
					signal			( int number			);
	bool			equal			( int number			);
	int				getID			( void					);
	void 			setHandler		( signal_function func	);
	void 			clearHandler	( void					);
	signal_function	getHandler		( void					);


 private:

	// Instance variables
	int						signumber;
	signal_function			handler;

	TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "osapi"


#endif /* PROCESS_SIGNAL_HH_ */

