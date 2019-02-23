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
#include <configuration/item.hh>
#include <string>
#include <vector>

// Import OSAPI++ declarations
#include "status/trace_macros.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************


namespace osapi
{

namespace configuration
{

class argItem : public item
{
public:
	/// @brief Class constructor
	/// @param [in] arguments - The string with one or more arguments

	explicit					argItem		( const std::string & arguments	);

	/// @brief Class destructor
								~argItem	();

	/// @brief Check if a CI argument is the same (to find a given argument)
	/// @param [in] name - The name of the argument to compare
	/// @return Match (true) or not (false)
	bool 						equal		( const std::string & name		);

	/// @brief Replace the current CI property value
	/// @param [in] value - The new argument value
	void						setString	( const std::string & value		);

	/// @brief Obtain a reference to this CI in string format
	/// @return The CI string reference
	const std::string &			getString	() const;

private:
	std::string					arg;

	TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "configuration"

}	// End of namespace "osapi"



#endif /* OSAPI_CONFIGURATION_ARGITEM_HH_ */
