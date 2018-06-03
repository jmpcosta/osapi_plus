/*
 * util.hh
 *
 *  Created on: 18/02/2018
 *      Author: joao
 */

#ifndef UTIL_UTIL_HH_
#define UTIL_UTIL_HH_

#include <string>


namespace osapi
{

class util
{
public:
		static void				splitString ( const std::string &, const char, std::string &, std::string & );
		static void				stringEraser( const std::string &, size_t,     std::string &				);
		static void				toUpperCase	( std::string &													);
		static void				toLowerCase	( std::string &													);
		static const char * 	bool2string ( bool value													);
};

};	// End of namespace "osapi"

#endif /* UTIL_UTIL_HH_ */
