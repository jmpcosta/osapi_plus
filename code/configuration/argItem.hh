// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATION_ARGITEM_HH_
#define OSAPI_CONFIGURATION_ARGITEM_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

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

class argItem : public configurationItem
{
public:
								argItem		( const std::string & arguments	);
								~argItem	();
	bool 						equal		( const std::string & name		);
	void						setString	( const std::string & value		);
	const std::string &			getString	() const;

private:
	std::string					arg;

	TRACE_CLASSNAME_DECLARATION
};




}	// End of namespace



#endif /* OSAPI_CONFIGURATION_ARGITEM_HH_ */
