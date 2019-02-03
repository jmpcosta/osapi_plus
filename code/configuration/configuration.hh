// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose: Defines the Interface for a Configuration
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATION_HH_
#define OSAPI_CONFIGURATION_HH_


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
#include "status/trace_macros.hh"
#include "configuration/configurationItem.hh"
#include "configuration/ciContainer.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************


namespace osapi
{

class configuration
{
public:

#pragma GCC visibility push(default)		// Start of public interface

		explicit 					configuration	( const std::string & name 														);
				 	 	 	 		~configuration	();

		bool						equal			( const std::string & name 														);

		ciContainer &				addContainer	();										// Return a reference to the default container
		ciContainer & 				addContainer	( const std::string & container	);		// Return a reference to a new or existent container

		bool		 				deleteContainer	( const std::string & container	);

		ciContainer &				getContainer	( 																				);		// Get the default container
		ciContainer &				getContainer	( const std::string & name														);		// Get a container matching "name"

		size_t						getNumber		();
		const std::string &			getName			() const;




#pragma GCC visibility pop					// End of public interface


private:
		// Instance variables
		std::string						configurationName;
		std::mutex						confMutex;
		std::vector<ciContainer *>		ciContainers;


		TRACE_CLASSNAME_DECLARATION
};



}	// End of namespace



#endif /* OSAPI_CONFIGURATION_HH_ */
