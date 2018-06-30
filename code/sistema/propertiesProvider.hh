// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide PropertiesProvider API
//
// *****************************************************************************************

#ifndef SISTEMA_PROPERTIESPROVIDER_HH_
#define SISTEMA_PROPERTIESPROVIDER_HH_

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
#include "sistema/property.hh"
#include "sistema/propertyContainer.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

class PropertiesProvider
{
public:

	static PropertiesProvider & 	getProvider();

	// delete copy and move constructors and assign operators
	PropertiesProvider(PropertiesProvider const&) 				= delete;		// Copy construct
	PropertiesProvider(PropertiesProvider&&     )				= delete;		// Move construct

	PropertiesProvider& operator=(PropertiesProvider const&)	= delete; 		// Copy assign
	PropertiesProvider& operator=(PropertiesProvider &&    )	= delete;		// Move assign

	void								importProperties	( const std::string & pathname );
	void								addProperty			( const std::string & module,       const std::string & propName, const std::string & propValue );
	void								addProperty			( const std::string & propertyName, const std::string & propertyValue );

	bool								getPropertyValues	( const std::string & module, const std::string & name, std::vector<std::string> & values );
	bool								getPropertyValues	( const std::string & name, std::vector<std::string> & values );

private:
										// Constructor & Destructor
										PropertiesProvider();
										~PropertiesProvider();

	propertyContainer *					newContainer		( const std::string & containerName );
	bool								parsePropertyName	( const std::string & fullname, std::string & module, std::string & name );
	bool								parseLine			( const std::string & line,     std::string & module, std::string & name, std::string & value );

	std::mutex							provMutex;
	std::vector<propertyContainer *>	containerList;
	TRACE_CLASSNAME_DECLARATION
};



};	// End of namespace "osapi"


#endif /* SISTEMA_PROPERTIESPROVIDER_HH_ */
