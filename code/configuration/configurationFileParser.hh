// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose: Defines the Interface for parsing itens in configuration files
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATIONFILEPARSER_HH_
#define OSAPI_CONFIGURATIONFILEPARSER_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <iostream>
#include <fstream>

// Import configuration headers
#include "configuration/configurationItemType.hh"
#include "configuration/configuration.hh"
#include "configuration/configurationParser.hh"


namespace osapi
{

// *****************************************************************************************
//
// Section: Module declarations/definitions
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

class configurationFileParser : configurationParser
{
public:
		explicit		configurationFileParser();
    					~configurationFileParser();

    	void	 		import( const std::string & from, std::string & into );

private:

    	// Instance methods

    	void 				processLine		( const std::string & line, configuration & conf									);
    	bool				parseLine		( const std::string & line, std::string & module, std::string & entry				);
    	bool				parseEntry		( std::string & entry, configurationItem ** p_item 									);
    	ciType				getEntryType	( const std::string & entry															);
    	bool				isType			( const char * const token, const std::string & entry								);
    	void				removeToken		( const char * const token, std::string & entry										);
    	bool				generateItem	( ciType type, std::string & entry, configurationItem ** p_item						);
    	configurationItem * make_arg		( const std::string & entry 														);
    	configurationItem * make_env		( const std::string & entry 														);
    	configurationItem * make_prop		( const std::string & entry 														);
    	void				splitProperty	( const std::string & entry, size_t where, std::string & name, std::string & value	);

    	// Instance variables
    	TRACE_CLASSNAME_DECLARATION
};

};	// End of namespace "osapi"




#endif /* OSAPI_CONFIGURATIONFILEPARSER_HH_ */
