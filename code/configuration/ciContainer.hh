// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose: Provide the declarations for the Configuration Container API
//
// *****************************************************************************************

#ifndef CODE_CONFIGURATION_CICONTAINER_HH_
#define CODE_CONFIGURATION_CICONTAINER_HH_


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


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

class ciContainer
{
public:

	// Class methods
	static const char *						getDefaultName();

	// Instance methods

								ciContainer		( const std::string & containerName				);
								~ciContainer	();


	bool						equal			( const std::string & container 				);

		// Add/Get a CI to/from the container
	void						addList			( const std::vector<configurationItem *> & list			);

	void						addItem			( configurationItem *	item							);
	bool			 			getItem			( const std::string & name, configurationItem ** p_item	);
	bool			 			deleteItem		( const std::string & name								);

	std::string & 				getName			();
	size_t						getNumber		();
	std::vector<std::string> 	getStringList	();


private:

	std::string							name;			// Each container instance has one name
	std::mutex							containerMutex; // Mutex for container access
	std::vector<configurationItem *>	ciList;			// and a set of associated configuration itens

	TRACE_CLASSNAME_DECLARATION
};



};	// End of namespace "osapi"



#endif /* CODE_CONFIGURATION_CICONTAINER_HH_ */