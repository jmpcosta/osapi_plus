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
#include <iostream>
#include <string>

// Import OSAPI++ declarations
#include "status/trace_macros.hh"
#include "configuration/configurationItem.hh"


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

class propertyItem : configurationItem
{
public:
		explicit					propertyItem	( const std::string & propName, const std::string & propValue );
    								~propertyItem	();

    	std::string const &	 		getString		() const;
    	void						setString		( const std::string & propValue	);
    	bool 						equal			( const std::string & propName	);

private:
    	std::string 				name;
    	std::string 				value;

    	TRACE_CLASSNAME_DECLARATION
};

};	// End of namespace "osapi"




#endif /* OSAPI_PROPERTYITEM_HH_ */
