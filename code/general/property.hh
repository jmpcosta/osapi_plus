// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide the definition of a basic OSAPI property type
//
// *****************************************************************************************

#ifndef OSAPI_PROPERTY_HH_
#define OSAPI_PROPERTY_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>


// *****************************************************************************************
//
// Section: Type declaration/definition
//
// *****************************************************************************************


namespace osapi
{

/// @brief Definition of a property type
class property
{
public:
	/// @brief Constructor
	/// @param [in] name	- The property name
	/// @param [in] value	- The property initial value
	explicit			property	( const std::string & name, const std::string value )	{ iName = name; iValue = value;	};

	/// @brief Destructor
						~property	( void ) {};

	/// @brief Get name of property
	/// @return The property name
	std::string	const & getName		( void ) const								{ return iName;		}

	/// @brief Get property value
	/// @return Property value
	std::string const &	getValue	( void ) const								{ return iValue;	}

	/// @brief Set value of the property
	/// @param [in] value - The property new value
	void				setValue	( const std::string & value	)				{ iValue = value;	}

	bool				operator==	( const std::string & right )				{ return (iName == right);	}

private:
  std::string		iName;
  std::string		iValue;
};


};	// End of namespace "osapi"



#endif /* OSAPI_PROPERTY_HH_ */
