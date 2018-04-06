/*
 * log.cpp
 *
 *  Created on: 18/02/2018
 *      Author: joao
 */

#include <string>

#include "log/log.h"
#include "logging/log.hh"

namespace osapi
{

Log::~Log( void ){}


Log & Log::getLog()
{
 static Log instance;

 return instance;
}


Log::Log( void )
{
 static t_log systemLog;

 systemLog.ident    = "Placeholder";
 systemLog.option   = LOG_PID | LOG_CONS;
 systemLog.facility = LOG_USER;

 p_log = (void *) &systemLog;
}

void Log::open( void )
{
	t_log * p_myLog;

	p_myLog = (t_log *) p_log;

	log_system_open( *p_myLog );
}

void Log::close( void )
{
	log_system_close( *( (t_log *) p_log) );
}

void Log::debug( std::string message )
{
	log_debug_write( *( (t_log *) p_log), message.c_str() );
}

void Log::info( std::string message )
{
	log_info_write( *( (t_log *) p_log), message.c_str() );
}

void Log::warn( std::string message )
{
	log_warning_write( *( (t_log *) p_log), message.c_str() );
}

void Log::error( std::string message )
{
	log_error_write( *( (t_log *) p_log), message.c_str() );
}

void Log::fatal( std::string message )
{
	log_fatal_write( *( (t_log *) p_log), message.c_str() );
}

void Log::setSource( std::string & source )
{
 t_log * p_myLog;

  p_myLog = (t_log *) p_log;

  if( p_myLog != nullptr )
      log_source( source.c_str(), p_myLog );
}



};	// End of namespace "osapi"
