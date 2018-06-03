/*
 * property.hh
 *
 *  Created on: 13/05/2018
 *      Author: joao
 */

#ifndef CODE_SISTEMA_PROPERTY_HH_
#define CODE_SISTEMA_PROPERTY_HH_

#include <iostream>
#include <string>

#include "sistema/trace.hh"

namespace osapi
{


class property
{
public:
		property( std::string propName, std::string propValue );
    	~property();

    	const std::string & getValue();
    	bool equal( const std::string & compString );

private:
    	std::string name;
    	std::string value;
    	TRACE_CLASSNAME_DECLARATION
};

constexpr char property_file_separator		= '=';
constexpr char property_index_separator		= '#';

};	// End of namespace "osapi"




#endif /* CODE_SISTEMA_PROPERTY_HH_ */
