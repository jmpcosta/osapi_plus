// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide PropertyItem API
//
// *****************************************************************************************

#ifndef OSAPI_PROPERTYITEM_HH_
#define OSAPI_PROPERTYITEM_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <configuration/item.hh>
#include <iostream>
#include <string>

// Import OSAPI++ declarations
#include "status/trace_macros.hh"


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

/// @brief The class is responsible for managing Property Items
class propertyItem : item
{
public:
		/// @brief Class destructor
		/// @param [in] name  - The new Property name
		/// @param [in] value - The new Property value
		explicit					propertyItem	( const std::string & name, const std::string & value );

		/// @brief Class destructor
    								~propertyItem	();

    	/// @brief Obtain a reference to this CI in string format
    	/// @return The CI string reference
    	std::string const &	 		getString		() const;

    	/// @brief Replace the current CI property value
    	/// @param [in] value - The new Property value
    	void						setString		( const std::string & value	);

    	/// @brief Check if a CI property name is the same (to find a given property)
    	/// @param [in] name - The name of the property to compare
    	/// @return Property match (true) or not (false)
    	bool 						equal			( const std::string & name	);

private:
    	std::string 				name;
    	std::string 				value;

    	TRACE_CLASSNAME_DECLARATION
};

}	// End of namespace "configuration"
}	// End of namespace "osapi"




#endif /* OSAPI_PROPERTYITEM_HH_ */
