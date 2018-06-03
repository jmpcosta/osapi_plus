/*
 * util.hh
 *
 *  Created on: 18/02/2018
 *      Author: joao
 */

#ifndef LOG_LOG_HH_
#define LOG_LOG_HH_

#include <string>
#include <mutex>

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

static	Log		&			getLog		( void																);
							~Log		( void 																);
		void 				open		( const char * source, const char * target, const char * options[]	);
		void 				open		( void						 										);
		void 				close		( void 																);

		// Log with a certain Log level
		void		 		debug		( const char * message												);
		void		 		info		( const char * message												);
		void		 		warn		( const char * message												);
		void		 		error		( const char * message												);
		void		 		fatal		( const char * message												);
		// Wrapper for the previous functions
		void		 		debug		( std::string &	message												);
		void		 		info		( std::string &	message												);
		void		 		warn		( std::string &	message												);
		void		 		error		( std::string &	message												);
		void		 		fatal		( std::string &	message												);

private:
		Log();
		std::mutex			openMutex;		// Block attempt by multiple threads to open the system log at the same time
		void *				p_log;			// void pointer to avoid using C OSAPI headers in C++ interface
};


};	// End of namespace "osapi"

#endif /*LOG_LOG_HH_ */
