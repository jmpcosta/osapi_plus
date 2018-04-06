/*
 * types.hh
 *
 *  Created on: 18/02/2018
 *      Author: joao
 */

#ifndef GENERAL_TYPES_HH_
#define GENERAL_TYPES_HH_

#include <string>

namespace osapi
{

struct s_prop
{
	std::string name;
	std::string value;
};

using PROPERTY = struct s_prop;

struct s_eprop
{
	std::string	module;
	std::string name;
	std::string value;
};

using EPROPERTY = struct s_eprop;

};	// End of namespace "osapi"

#endif /* GENERAL_TYPES_HH_ */
