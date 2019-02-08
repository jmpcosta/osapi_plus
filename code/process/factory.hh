// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Process module API
//
// *****************************************************************************************

#ifndef OSAPI_PROCESS_FACTORY_HH_
#define OSAPI_PROCESS_FACTORY_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers

// Import OSAPI++ declarations
#include "general/general.hh"
#include "status/trace_macros.hh"

// Import Module declarations
#include "process/plan.hh"
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

class factory
{
public:

	// Class methods
	static runner *  make( process::plan & planned );
	static factory & getFactory( void );

	// delete copy and move constructors and assign operators
	factory( factory const & 	)			= delete;		// Copy construct
	factory( factory && 		)			= delete;		// Move construct
	factory& operator=( factory const&)		= delete; 		// Copy assign
	factory& operator=( factory &&	)		= delete;		// Move assign

private:

	// Instance methods
	factory();
	~factory();
	runner * build( process::plan & planned );

	TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "process"

}	// End of namespace "osapi"




#endif /* OSAPI_PROCESS_FACTORY_HH_ */
