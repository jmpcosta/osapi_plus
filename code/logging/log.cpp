// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Log API implementation
//
// *****************************************************************************************

// Include C++ system headers
#include <configuration/Provider.hh>
#include <string>
#include <vector>
#include <exception>

// Include C OSAPI log interface
#include "general/general_baseline.h"
#include "status/status.h"
#include "log/log.h"

// Include C++ OSAPI headers
#include "status/status.hh"
#include "util/util.hh"
#include "status/trace.hh"
#include "logging/log.hh"



// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{

TRACE_CLASSNAME( Log )

// *****************************************************************************************
//
// Section: Class variables initialization
//
// *****************************************************************************************

bool Log::logAvailable = false;


// *****************************************************************************************
//
// Section: Class methods
//
// *****************************************************************************************

Log & Log::getLog()
{
 static Log instance;

 return instance;
}

bool Log::isLogAvailable()
{
 return logAvailable;
}

// *****************************************************************************************
//
// Section: Instance method creation & Destruction
//
// *****************************************************************************************

Log::~Log( void ){}

Log::Log( void )
{
 static t_log systemLog;

 p_log = (void *) &systemLog;
}


// *****************************************************************************************
//
// Section: Definitions for Log Administration
//
// *****************************************************************************************

void Log::open( const char * source, const char * target, const char * options[] )
{
 t_status st;

 // Make sure that the Mutex is always unlock when it goes out-of-scope
 std::lock_guard<std::mutex> guard( openMutex );

 st = log_system_open( source, target, options, (t_log *) p_log );

 throw_on_failure( st );

 logAvailable = true;
}


void Log::close( void )
{
 if( logAvailable )
	 log_system_close( *( (t_log *) p_log) );
}


// *****************************************************************************************
//
// Section: Definitions for Log Operations
//
// *****************************************************************************************


void Log::debug( std::string & message )
{
 if( logAvailable )
 	 log_debug_write( *( (t_log *) p_log), message.c_str() );
}

void Log::info( std::string & message )
{
 if( logAvailable )
 	 log_info_write( *( (t_log *) p_log), message.c_str() );
}

void Log::warn( std::string & message )
{
 if( logAvailable )
	 log_warning_write( *( (t_log *) p_log), message.c_str() );
}

void Log::error( std::string & message )
{
 if( logAvailable )
	 log_error_write( *( (t_log *) p_log), message.c_str() );
}

void Log::fatal( std::string & message )
{
 if( logAvailable )
	 log_fatal_write( *( (t_log *) p_log), message.c_str() );
}

void Log::debug( const char * message )
{
 if( logAvailable )
	 log_debug_write( *( (t_log *) p_log), message );
}

void Log::info( const char * message )
{
 if( logAvailable )
	 log_info_write( *( (t_log *) p_log), message );
}

void Log::warn( const char * message )
{
 if( logAvailable )
	 log_warning_write( *( (t_log *) p_log), message );
}

void Log::error( const char * message )
{
 if( logAvailable )
	 log_error_write( *( (t_log *) p_log), message );
}

void Log::fatal( const char * message )
{
 if( logAvailable )
	 log_fatal_write( *( (t_log *) p_log), message );
}


};	// End of namespace "osapi"
