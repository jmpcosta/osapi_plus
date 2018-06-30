// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide System Configuration API
//
// *****************************************************************************************

#ifndef SISTEMA_CONFIGURATION_HH_
#define SISTEMA_CONFIGURATION_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

// Import OSAPI++ declarations
#include "sistema/propertiesProvider.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************


namespace osapi
{

// **************************************************************************************
// Description:
//
//	The purpose of the class is to provide an entry point to the respective
//	Configuration classes in each functional module (e.g. OS).
//	The class implements the Singleton pattern and a configuration can be given to the
//	class either by:
//	- Providing a file name to the location of a OSAPI++ configuration file
//	- Providing a list of pair: <property,value>
//
// **************************************************************************************

class Configuration
{
public:

#pragma GCC visibility push(default)		// Start of public interface

	static Configuration & 	getConfiguration();

	// delete copy and move constructors and assign operators
	Configuration(Configuration const&) 			= delete;		// Copy construct
	Configuration(Configuration&&) 					= delete;		// Move construct
	Configuration& operator=(Configuration const&)	= delete; 		// Copy assign
	Configuration& operator=(Configuration &&)		= delete;		// Move assign

	void				init				( int argc, char * argv[], char * env[] );
	void				import				( const std::string & pathname	);
	void				addProperty			( const std::string module, const std::string propName, const std::string propValue );
	bool				getPropertyValues	( const std::string & module, const std::string & name, std::vector<std::string> & values );
	bool				getPropertyValues	( const std::string & name, std::vector<std::string> & values );


#pragma GCC visibility pop			// End of public interface

private:
						Configuration();
						~Configuration();

	size_t				argumentCount;
	char		**		arguments;
	char		**		environment;
	std::string			classname;

};


} // End of namesoace "osapi"


#endif /* SISTEMA_CONFIGURATION_HH_ */
