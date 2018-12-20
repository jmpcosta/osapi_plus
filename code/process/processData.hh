// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Process module API
//
// *****************************************************************************************

#ifndef PROCESS_PROCESSDATA_HH_
#define PROCESS_PROCESSDATA_HH_

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
#include "general/general_types.hh"
#include "status/trace_macros.hh"


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

class CurrentProcess;

class processData
{
public:
					processData();
					~processData();
		bool		setCmdLine		( std::vector<std::string> & line	);
		bool		setEnvironment	( std::vector<std::string> & env	);
		void *		getRaw			( void								);

private:
		void	*	data;
		void	*	cmdLine;
		void	*	environment;

private:
		std::mutex					dataMutex;
		TRACE_CLASSNAME_DECLARATION
};



}	// End of namespace "osapi"

#endif /* PROCESS_PROCESSDATA_HH_ */
