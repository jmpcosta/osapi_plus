// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose: Provide the declarations for the Configuration Container API
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATION_CONTAINER_HH_
#define OSAPI_CONFIGURATION_CONTAINER_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>
#include <mutex>
#include <functional>

// Import OSAPI++ declarations
#include "general/types.hh"
#include "status/trace_macros.hh"

// include module headers
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

/// @brief Class containing the Configuration Items
class container
{
public:

	// Class methods
	/// @brief Get the default container name
	/// @return The default container name
	static const char *						getDefaultName();

	// Instance methods
	/// @brief Create a new CI container
	/// @param [in] name - Container name to create
								container		( const std::string & name );

	/// @brief Destroy the CI container
								~container		();

	/// @brief check if two containers name match
	/// @param [in] name - The container name to compare
	/// @return True if containers match. False, otherwise.
	bool						equal			( const std::string & name );

	/// @brief Add a new list of CIs to the container
	/// @param [in] list - List of CIs to add to the container
	void						addList			( const std::vector<item *> & list );

	/// @brief Add a CI to the container
	/// @param [in] newItem - A new CI to add to the container
	void						addItem			( item *	newItem							);

	/// @brief Get a CI from the container
	/// @param [in] name - The name of the CI to retrieve
	/// @param [out] item - A pointer to the CI if it exists, nullptr otherwise.
	/// @return Operation status: True if retrieved. False otherwise.
	bool			 			getItem			( const std::string & name, item ** item	);

	/// @brief Delete a CI from the container
	/// @param [in] name - The name of the item to delete
	/// @return Operation status: True if deleted. False otherwise.
	bool			 			deleteItem		( const std::string & name	);

	/// @brief Get the container name
	/// @return Reference to the container name
	std::string & 				getName			();

	/// @brief Get the number of elements in the container
	/// @return Number of elements in the container
	size_t						getNumber		();

	/// @brief Get a vector with CI strings
	/// @return Vector of C-string pointers to the container CIs
	std::vector<refConstStr> 	getStringList	();


private:
	/// @brief Each container instance has one name
	std::string							name;
	/// @brief Mutex for container access
	std::mutex							containerMutex;
	/// @brief set of associated configuration itens
	std::vector<item *>	ciList;

	TRACE_CLASSNAME_DECLARATION
};




}	// End of namespace "configuration"
}	// End of namespace "osapi"



#endif /* OSAPI_CONFIGURATION_CONTAINER_HH_ */
