// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Process module API
//
// *****************************************************************************************

#ifndef PROCESS_PLAN_HH_
#define PROCESS_PLAN_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>
#include <mutex>

// Import OSAPI++ declarations
#include "general/general.hh"
#include "status/trace_macros.hh"

// Include own module headers
#include "process/plan_signal.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace process
{

class plan : public planSignal
{
public:
							plan();
							~plan();
		bool				setCmdLine		( std::vector<std::string> & line	);
		bool				setEnvironment	( std::vector<std::string> & env	);
		void *				getRaw			( void								);

		// Add data to the instance
		bool 				addCommandLine	( std::vector<std::string> & args	);
		bool				addEnvironment	( std::vector<std::string> & env	);
		bool				addUser			( const std::string & user			);
		bool				addGroup		( const std::string & group			);
		void				addName			( const std::string & procName		);

		// Get information from a raw process structure
		std::string			getStringPID( void );
		std::string			getStringUID( void );
		std::string			getStringGID( void );


private:
		// Instance variables
		void	*	rawData;
		void	*	cmdLine;
		void	*	environment;

		std::mutex						procMutex;

		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "process"

}	// End of namespace "osapi"

#endif /* PROCESS_PLAN_HH_ */
