/*
 * util.hh
 *
 *  Created on: 18/02/2018
 *      Author: joao
 */

#ifndef LOG_LOG_HH_
#define LOG_LOG_HH_

#include <string>

namespace osapi
{

class Log
{
public:
		// delete copy and move constructors and assign operators
		Log( Log const& ) 				= delete;		// Copy construct
		Log( Log&& ) 					= delete;		// Move construct
		Log& operator=( Log const& )	= delete; 		// Copy assign
		Log& operator=( Log && )		= delete;		// Move assign

static	Log		&			getLog		(							);
							~Log		( void 						);
		void 				open		( void 						);
		void 				close		( void 						);
		// Log with a certain Log level
		void		 		debug		( std::string 				);
		void		 		info		( std::string 				);
		void		 		warn		( std::string 				);
		void		 		error		( std::string 				);
		void		 		fatal		( std::string 				);


		void				setSource	( std::string &				);
		// void				setFacility	( int						);
		// void				options		( int						);


private:
		Log();

protected:
		void *	p_log;		// void pointer to avoid using C OSAPI headers in C++ interface
};


};	// End of namespace "osapi"

#endif /*LOG_LOG_HH_ */
