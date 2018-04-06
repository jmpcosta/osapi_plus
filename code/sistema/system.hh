/*
 * system.hh
 *
 *  Created on: 16/02/2018
 *      Author: joao
 */

#ifndef SYSTEM_HH_
#define SYSTEM_HH_

#include <string>
#include <array>

#include <general/general_types.hh>

namespace osapi
{
namespace system
{


// **************************************************************************************
// Description:
//
//	The purpose of the class is to provide an entry point to the respective
//	Configuration classes in each functional module (e.g. OS).
//	The class implements the Singleton pattern and a configuration can be given to the
//	class either by:
//	- Providing a file name to the location of a OSAPI++ configuration file
//	- Providing a list of pair: <property,value>
//
// **************************************************************************************

class Configuration
{
public:

		static Configuration & 	getInstance();

		// delete copy and move constructors and assign operators
		Configuration(Configuration const&) 			= delete;		// Copy construct
		Configuration(Configuration&&) 					= delete;		// Move construct
		Configuration& operator=(Configuration const&)	= delete; 		// Copy assign
		Configuration& operator=(Configuration &&)		= delete;		// Move assign

		void					import( const std::string & );
		void					addProperty( std::string, std::string, std::string, std::vector<EPROPERTY> & );

private:
		const std::array<const char *,1>	modules = {	os::module };

											Configuration();
											~Configuration();
		void								pushModules( std::vector<EPROPERTY> & );

};




}	// End of namespace "system"

}	// End of namespace "osapi"



#endif /* SYSTEM_HH_ */
