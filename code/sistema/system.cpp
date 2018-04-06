/*
 * system.cpp
 *
 *  Created on: 16/02/2018
 *      Author: joao
 */
/*
#include <iostream>
#include <fstream>
#include <string>

#include <status/status.hh>
#include <util/util.hh>
#include <os/os.hh>

#include <sistema/system.hh>	// Include my own interface

namespace osapi
{

namespace system
{

constexpr char module[] = "SYSTEM";
constexpr char property_file_separator = '=';
constexpr char property_name_separator = '.';

Configuration & Configuration::getInstance()
{
	static	Configuration instance;

	return instance;
}

// Private Constructor
Configuration::Configuration()  {}

// Private Destructor
Configuration::~Configuration() {}



void Configuration::addProperty( std::string module, std::string name, std::string value, std::vector<EPROPERTY> & props )
{
 EPROPERTY prop;

 prop.module = module;
 prop.name   = name;
 prop.value  = value;
 props.push_back( prop );

}

void Configuration::pushModules( std::vector<EPROPERTY> & eProperties )
{
 std::vector<PROPERTY> props ( eProperties.size() ) ;

	os::Configuration & osi = os::Configuration::getInstance();

	for( auto i : props )
	{
		//i.name =
		 //osi.add( properties );
	}
}

void Configuration::import( const std::string & pathname )
{
 std::string			modName, name, value;
 std::vector<EPROPERTY>	vProperties;

	std::cout << "Reading:" << pathname << std::endl;
	std::ifstream propFile( pathname );

	// Process system property file
	for( std::string line; std::getline(propFile, line); )
	   {
	     if( line.length() )
	       {
	    	 util::splitString( line, property_file_separator, name, value );
			 for (auto & c : name) c = char( toupper(c) );	// Convert Property name to Upper case

			 // Get module name
			 std::string ignore;
			 util::splitString( name, property_name_separator, modName, ignore );

			 addProperty( modName, name, value, vProperties );
	       }
	   }

	for( auto i : modules )
		 std::cout << i ;

	// pushModules( vProperties );
}








} 	// End of namespace "system"

}	// End of namespace "osapi"

*/
