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
#include "configuration/itemType.hh"
#include "configuration/configuration.hh"
#include "configuration/parser.hh"


namespace osapi
{

namespace configuration
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

/// @brief An implementation of a configuration parser interface that reads a set of CIs
///
/// A file parser imports Configuration Items into a configuration. Each line is in the form:<BR>
/// <HR>
/// [container name] <B>|</B> [Configuration Item type]<BR>
/// <HR>
/// Where a Configuration type can be:<BR>
/// <HR>
/// prop:[property name]=[property value]<BR>
/// env:[variable name]=[variable value]<BR>
/// arg:[arguments]<BR>
class fileParser : public parser
{
public:
		/// @brief class destructor
		explicit		fileParser();

		/// @brief Class destructor
    					~fileParser();

    	/// @brief Import a property file into a configuration name
    	/// @param [in] from - Property file name to import
    	/// @param [in] into - Destination configuration name
    	void	 		import( const std::string & from, std::string & into );

private:

    	// Instance methods
    	/// @brief Process a line of text from the input file
    	/// @param [in] line	- The input line to parse
    	/// @param [in] conf	- The configuration where to store the parsed CI
    	void 				processLine		( const std::string & line, configuration & conf );

    	/// @brief Split a text line into module and raw CI entry
    	/// @param [in] line	- The line to parser. If parsing is successful it will split it in module and entry
    	/// @param [out] module	- The module/container name
    	/// @param [out] entry	- The raw CI
    	/// @return Operation status. Success/true. Failure/false otherwise.
    	bool				parseLine		( const std::string & line, std::string & module, std::string & entry );

    	/// @brief Generate a CI from the text entry
    	/// @param [in] entry	- The raw CI entry
    	/// @param [in] ci 		- The new CI
    	/// @return Operation status. Success/true. Failure/false otherwise.
    	bool				parseEntry		( std::string & entry, item ** item	);

    	/// @brief Get the type of CI: env, arg, prop(erty), etc..
    	/// @param [in] entry	- The text entry
    	/// @return Enum value that defines the CI type
    	ciType				getEntryType	( const std::string & entry	);

    	/// @brief Check if a given entry contains a token that identifies a CI type
    	/// @param [in] token - The token string that identifies a CI type
    	/// @param [in] entry - The text entry
    	/// @return Operation status. Found type/true. Not found type/false otherwise.
    	bool				isType			( const char * const token, const std::string & entry );

    	/// @brief Deletes a token from a string
    	/// @param [in] token
    	/// @param [in,out] entry - The string from where the token must be removed
    	void				removeToken		( const char * const token, std::string & entry	);

    	/// @brief Create a CI
    	/// @param [in] type	- The CI type to create
    	/// @param [in] entry	- The text entry
    	/// @param [out] item	- New CI
    	/// @return Operation status. Create/true. Not created/false otherwise.
    	bool				generateItem	( ciType type, std::string & entry, item ** item );

    	/// @brief Create an argument CI
    	/// @param [in] entry - The text entry
    	/// @return The new argument CI
    	item 	*			make_arg		( const std::string & entry );

    	/// @brief Create an environment CI
    	/// @param [in] entry - The text entry
    	/// @return The new environment CI
    	item	*			make_env		( const std::string & entry );

    	/// @brief Create a property CI
    	/// @param [in] entry - The text entry
    	/// @return The new property CI
    	item 	*			make_prop		( const std::string & entry );

    	/// @brief Split a property in property name and value
    	/// @param [in] entry - The text entry
    	/// @param [in] where - From which location the split can be carried out
    	/// @param [out] name - Property name
    	/// @param [out] value- Property value
    	void				splitProperty	( const std::string & entry, size_t where, std::string & name, std::string & value	);

    	// Instance variables
    	TRACE_CLASSNAME_DECLARATION
};

}	// End of namespace "configuration"

}	// End of namespace "osapi"




#endif /* OSAPI_CONFIGURATIONFILEPARSER_HH_ */
