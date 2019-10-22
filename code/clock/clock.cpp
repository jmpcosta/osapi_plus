// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Clock module implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "clock/clock.h"
#include "common/common_helper.h"
#include "clock/clock_helper.h"

// Import C++ system headers
#include <string>

// Import OSAPI++ generic headers
#include "general/types.hh"
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "clock/precision.hh"
#include "clock/clock.hh"


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

namespace osapi
{

TRACE_CLASSNAME( clock )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************


bool clock::isSupported	( void )
{
 TRACE_POINT

 t_status st = clock_module_supported();

 return (status_success( st ) ? true: false );
}

clock::~clock()
{
 TRACE_POINT

 delete (t_clock *) p_iClock;
}



clock::clock( const char * timezone	)
{
 t_status		st;
 t_time			tm;

 TRACE_ENTER

 st = clock_time_get( &tm );
 throw_on_failure( st );

 t_clock * p_clock = new t_clock;

 st = clock_instance_createTimezone( &tm, timezone, p_clock );

 if( status_failure( st ) )
   {
	 delete p_clock;
	 throw_on_failure( st );
   }

 p_iClock = (void *) p_clock;

 TRACE_EXIT
}

clock::clock( const std::string & timezone ) : clock( timezone.c_str() )
{ TRACE_POINT }


clock::clock( void )
{
 t_status		st;
 t_time			tm;
 t_time_offset	offset;

 TRACE_ENTER

 st = clock_offset_make( (int64_t) 0, (uint64_t) 0, &offset );
 throw_on_failure( st );

 st = clock_time_get( &tm );
 throw_on_failure( st );

 t_clock * p_clock = new t_clock;

 st = clock_instance_createOffset( &tm, &offset, p_clock );

 if( status_failure( st ) )
   {
	 delete p_clock;
	 throw_on_failure( st );
   }

 p_iClock = (void *) p_clock;

 TRACE_EXIT
}

clock::clock( int64_t seconds, uint64_t fraction, precision	prec )
{
 t_status		st;
 t_time			tm;
 t_time_offset	offset;

 TRACE_ENTER

 st = clock_time_make( seconds, fraction, &tm );
 throw_on_failure( st );

 st = clock_offset_make( (int64_t) 0, (uint64_t) 0, &offset );
 throw_on_failure( st );

 t_clock * p_clock = new t_clock;

 st = clock_instance_createOffset( &tm, &offset, p_clock );

 if( status_failure( st ) )
   {
	 delete p_clock;
	 throw_on_failure( st );
   }

 p_iClock = (void *) p_clock;

 TRACE_EXIT
}

precision clock::getPrecision( void )
{
 t_clock * p_clock = (t_clock *) p_iClock;

 return static_cast<precision>( get_clock_precision( p_clock ) );
}


void clock::update( void )
{
 t_status	st;
 t_clock *	p_clock = (t_clock *) p_iClock;

 TRACE_ENTER

 st = clock_time_get( &(get_clock_time( p_clock ) ) );
 throw_on_failure( st );

 TRACE_EXIT
}

void clock::getTime( int64_t & seconds, uint64_t & fraction, precision	& prec )
{
 t_status	st;
 t_time  	tm;
 t_clock *	p_clock = (t_clock *) p_iClock;

 st = clock_instance_getTime( p_clock, &tm );
 throw_on_failure( st );

 seconds	= get_clock_seconds		( p_clock );
 fraction	= get_clock_fraction	( p_clock );
 prec		= static_cast<precision> get_clock_precision ( p_clock );
}

void clock::getLocalTime( int64_t & seconds, uint64_t & fraction, precision	& prec )
{
 t_status 	st;
 t_time  	tm;
 t_clock *	p_clock = (t_clock *) p_iClock;

 st = clock_instance_getLocalTime( p_clock, &tm );
 throw_on_failure( st );

 seconds	= get_clock_seconds		( p_clock );
 fraction	= get_clock_fraction	( p_clock );
 prec		= static_cast<precision> get_clock_precision ( p_clock );
}



}   // End of namespace "osapi"
