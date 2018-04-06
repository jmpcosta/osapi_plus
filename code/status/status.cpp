/*
 * status.c
 *
 *  Created on: 02/02/2018
 *      Author: joao
 */

#include "status/status.h"
#include "status/status.hh"


namespace osapi
{

status::status(int code, const char * mod, const char * function, const char * errMsg )
{
	reason = "Exception in function ";
	reason += function;
	reason += " of module ";
	reason += mod;
	// reason += " with error code ";
	//reason += code;
	reason += " with message: ";
	reason += errMsg;
}

status::status( const char * mod, const char * function, const char * errMsg )
{
 // Code is irrelevant in this case, set it to 0
 status( 0, mod, function, errMsg );
}

status::status( int code, uint8_t mod, uint8_t type, const char * function )
{

 status( code, status_moduleByID_get( mod ), function, status_errorByType_get( code, mod, type) );
}

status::~status() throw() {}

const char * status::what() const noexcept
{
	return reason.c_str();
}


} // End of namespace osapi
