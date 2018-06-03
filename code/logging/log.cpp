/*
 * log.cpp
 *
 *  Created on: 18/02/2018
 *      Author: joao
 */

// Include C++ system headers
#include <string>
#include <exception>

// Include C OSAPI log interface
#include "log/log.h"

// Include C++ OSAPI headers
#include "status/status.hh"
#include "util/util.hh"
#include "sistema/system.hh"
#include "logging/log.hh"


namespace osapi
{

constexpr char log_namespace[]	= "osapi.log";
constexpr char log_source[]		= "log.source";
constexpr char log_target[]  	= "log.target";
constexpr char log_options[] 	= "log.option";

Log::~Log( void ){}


Log & Log::getLog()
{
 static Log instance;

 return instance;
}


Log::Log( void )
{
 static t_log systemLog;

 p_log = (void *) &systemLog;
}

void Log::open( const char * source, const char * target, const char * options[] )
{
 t_status st;

 openMutex.lock();

 st = log_system_open( source, target, options, (t_log *) p_log );

 openMutex.unlock();

 if( status_failure( st ) )
	 throw OSAPI_STATUS( st );
}


void Log::open( void )
{
 std::vector<std::string> source;
 std::vector<std::string> target;
 std::vector<std::string> options;

	// Attempt to retrieve the System Log properties from the System Configuration
	Configuration & sysConf = Configuration::getConfiguration();

	// Get the relevant properties from Configuration
	sysConf.getPropertyValues( log_namespace, log_source,  source  );
	sysConf.getPropertyValues( log_namespace, log_target,  target  );
	sysConf.getPropertyValues( log_namespace, log_options, options );

	// Build an array of options
	size_t	sz = options.size();
	const char * opt[  sz + 1 ];

	for( size_t i = 0; i < sz; i++ )
		 opt[ i ] = options[ i ].c_str();

	opt[ sz ] = nullptr;	// Make sure that the array is null terminated

	// open system log, if at least a source and a target was provided
	if( source.size() > 0 && target.size() > 0 )
	    open( source[0].c_str(), target[0].c_str(), opt );
}

void Log::close( void )
{
	log_system_close( *( (t_log *) p_log) );
}

void Log::debug( std::string & message )
{
	log_debug_write( *( (t_log *) p_log), message.c_str() );
}

void Log::info( std::string & message )
{
	log_info_write( *( (t_log *) p_log), message.c_str() );
}

void Log::warn( std::string & message )
{
	log_warning_write( *( (t_log *) p_log), message.c_str() );
}

void Log::error( std::string & message )
{
	log_error_write( *( (t_log *) p_log), message.c_str() );
}

void Log::fatal( std::string & message )
{
	log_fatal_write( *( (t_log *) p_log), message.c_str() );
}

void Log::debug( const char * message )
{
	log_debug_write( *( (t_log *) p_log), message );
}

void Log::info( const char * message )
{
	log_info_write( *( (t_log *) p_log), message );
}

void Log::warn( const char * message )
{
	log_warning_write( *( (t_log *) p_log), message );
}

void Log::error( const char * message )
{
	log_error_write( *( (t_log *) p_log), message );
}

void Log::fatal( const char * message )
{
	log_fatal_write( *( (t_log *) p_log), message );
}


};	// End of namespace "osapi"
