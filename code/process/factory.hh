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

/// @brief Class responsible for the creation of new OS processes
class factory
{
public:

	// Class methods
	/// @brief Creates a new process from a plan
	/// @param [in] planned - The process plan
	/// @return A pointer to a new runner instance
	static runner *  	make		( process::plan & planned 	);

	/// @brief Get an instance of the factory
	/// @return The singleton instance
	static factory & 	getFactory	( void 						);

	/// @brief Check if the new process is the creator or the child
	/// @param [in] planned - Process plan
	/// @return True if creator or False otherwise (False doesn't mean child)
	static bool			isParent	( process::plan & planned 	);

	/// @brief Check if the new process is the child
	/// @param [in] planned - Process plan
	/// @return True if child. False otherwise (False doesn't mean parent)
	static bool			isChild		( process::plan & planned 	);

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
