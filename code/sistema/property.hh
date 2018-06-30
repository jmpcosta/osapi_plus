// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Property API
//
// *****************************************************************************************

#ifndef SISTEMA_PROPERTY_HH_
#define SISTEMA_PROPERTY_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <iostream>
#include <string>

// Import OSAPI++ declarations
#include "sistema/trace.hh"


namespace osapi
{

// *****************************************************************************************
//
// Section: Module declarations/definitions
//
// *****************************************************************************************

constexpr char property_file_separator		= '=';
constexpr char property_index_separator		= '#';


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

class property
{
public:
									property( std::string propName, std::string propValue );
    								~property();

    	const std::string & 		getValue();
    	bool 						equal( const std::string & compString );

private:
    	std::string 				name;
    	std::string 				value;
    	TRACE_CLASSNAME_DECLARATION
};

};	// End of namespace "osapi"




#endif /* SISTEMA_PROPERTY_HH_ */
