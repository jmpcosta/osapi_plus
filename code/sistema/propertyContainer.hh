/*
 * propertyContainer.hh
 *
 *  Created on: 13/05/2018
 *      Author: joao
 */

#ifndef CODE_SISTEMA_PROPERTYCONTAINER_HH_
#define CODE_SISTEMA_PROPERTYCONTAINER_HH_

#include <string>
#include <vector>

#include "sistema/property.hh"

namespace osapi
{

class propertyContainer
{
public:
						propertyContainer( const std::string & containerName );
						~propertyContainer();

		void			addProperty	( const std::string & propertyName, const std::string & propertyValue );
		bool			equal		( const std::string & container );
		// Input property name, output is property values
		bool			getProperty	( const std::string & name, std::vector<std::string> & values );
private:
		std::string						name;				// Each container instance has one name
		std::vector<property *>			propertyList;		// and a set of associated properties
		TRACE_CLASSNAME_DECLARATION
};



};	// End of namespace "osapi"



#endif /* CODE_SISTEMA_PROPERTYCONTAINER_HH_ */
