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

#include "general/general_types.hh"

namespace osapi
{

constexpr char module[] = "OS";

class Configuration
{
public:

		static Configuration & 	getInstance();

		// delete copy and move constructors and assign operators
		Configuration(Configuration const&) 			= delete;		// Copy construct
		Configuration(Configuration&&) 					= delete;		// Move construct
		Configuration& operator=(Configuration const&)	= delete; 		// Copy assign
		Configuration& operator=(Configuration &&)		= delete;		// Move assign

		void					add( std::vector<PROPERTY> & );

private:
								Configuration()		{}
								~Configuration()	{}
};


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
 };


}	// End of namespace "osapi"

#endif /* OS_HH_ */
