// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATION_OBJITEM_HH_
#define OSAPI_CONFIGURATION_OBJITEM_HH_


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

// Import module declarations
#include "configuration/item.hh"

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************


namespace osapi
{

namespace configuration
{

class objectItem : public item
{
public:
	/// @brief Class constructor
	/// @param [in] obj	- A pointer to the object item


								objectItem	( osapi::object * obj );

	/// @brief Class destructor
								~objectItem	();

	/// @brief Check if a CI argument is the same (to find a given argument)
	/// @param [in] name - The name of the object to compare
	/// @return Match (true) or not (false)
	bool 						equal		( const std::string & name		);

	/// @brief Sets the name of the object
	/// @param [in] name - The new object name
	void						setString	( const std::string & name		);

	/// @brief Returns the object name
	/// @return The CI string reference
	const std::string &			getString	() const;

	/// @brief Returns a reference to the object
	/// @return Object reference
	osapi::object	*			getObject();

private:
	object			*			iObject;
	std::string					iName;

	TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "configuration"

}	// End of namespace "osapi"



#endif /* OSAPI_CONFIGURATION_OBJITEM_HH_ */
