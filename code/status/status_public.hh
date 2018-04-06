/*
 * status_public.hh
 *
 *  Created on: 07/02/2018
 *      Author: joao
 */

#ifndef STATUS_PUBLIC_PLUS_HH_
#define STATUS_PUBLIC_PLUS_HH_

#include <stdexcept>

namespace osapi
{

class status : std::exception
{
public:
						status( int, const char *, const char *, const char * );
						status( const char *, const char *, const char * );
						status( int, uint8_t, uint8_t, const char * );
						~status();
		const char *	what() const noexcept;
		void 			set( int );

private:
		std::string		reason;
};


}

#endif /* STATUS_PUBLIC_PLUS_HH_ */
