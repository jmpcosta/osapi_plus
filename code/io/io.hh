// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide IO module API
//
// *****************************************************************************************

#ifndef OSAPI_IO_HH_
#define OSAPI_IO_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>

// Import OSAPI++ declarations
#include "general/types.hh"
#include "status/trace_macros.hh"

// Import own Module declarations



// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

class directory
{
public:
						// Constructor & Destructor
						directory();
						~directory();
		bool			change( const std::string & dirname );


protected:
		// Instance variables

		//std::mutex					ioMutex;

private:

		TRACE_CLASSNAME_DECLARATION
};

/*
class file
{
public:
						// Constructor & Destructor
						directory();
						~directory();
		bool			change( const std::string & dirname );


protected:
		// Instance variables

		//std::mutex					ioMutex;

private:

		TRACE_CLASSNAME_DECLARATION
};

*/

}	// End of namespace "osapi"

#endif /* OSAPI_IO_HH_ */
