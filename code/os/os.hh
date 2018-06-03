/*
 * os.hh
 *
 *  Created on: 02/02/2018
 *      Author: joao
 */

#ifndef OS_PLUS_HH_
#define OS_PLUS_HH_

#include "os/os.h"

#include <string>
#include <vector>

#include "general/general_defs.hh"
#include "sistema/trace.hh"

namespace osapi
{

constexpr char module[] = "OS";

class info
 {
 public:
	 	 	 	 	 	info();
	 std::string		get_name();
	 std::string 		get_version();
	 std::string		get_release();
	 std::string		get_node();
	 std::string		get_machine();
	 std::string		get_domain();
	 std::string		get_provider();
	 std::string		get_provider_release();
 private:
	 bool				osInfoAvailable;
	 t_osInfo			osInfo;
	 TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "osapi"

#endif /* OS_HH_ */
