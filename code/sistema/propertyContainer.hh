// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide PropertyContainer API declaration
//
// *****************************************************************************************

#ifndef SISTEMA_PROPERTYCONTAINER_HH_
#define SISTEMA_PROPERTYCONTAINER_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

// Import OSAPI++ declarations
#include "sistema/property.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

class propertyContainer
{
public:
									propertyContainer	( const std::string & containerName										);
									~propertyContainer	();

	void							addProperty			( const std::string & propertyName, const std::string & propertyValue	);
	bool							equal				( const std::string & container 										);

		// Input property name, output is property values
	bool							getProperty			( const std::string & name, std::vector<std::string> & values 			);

private:

	std::string						name;				// Each container instance has one name
	std::vector<property *>			propertyList;		// and a set of associated properties
	TRACE_CLASSNAME_DECLARATION
};



};	// End of namespace "osapi"



#endif /* SISTEMA_PROPERTYCONTAINER_HH_ */
