/*
 * util.c
 *
 *  Created on: 18/02/2018
 *      Author: joao
 */

#include <string>

#include <general/general_types.hh>
#include <util/util.hh>

namespace osapi
{



void util::splitString( const std::string & line, const char sep, std::string & name, std::string & value )
{
 size_t pos = line.find( sep );

 if( pos != std::string::npos )
   {
	 name  = line.substr( 0, pos  );
	 value = line.substr( pos + 1 );
   }
}


void util::stringEraser( const std::string & what, size_t location, std::string & where )
{
 size_t pos = where.find( what, location );
 size_t len = what.length();

 if( pos != std::string::npos )
	 where.erase( pos, len );
}

}; // End of namespace "osapi"
