// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Process module implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import OSAPI++ generic headers
#include "status/trace.hh"

// Import own module declarations
#include "process/status.hh"


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************

namespace osapi
{
namespace process
{

TRACE_CLASSNAME( status )


// *****************************************************************************************
//
// Section: Process Function definition
//
// *****************************************************************************************

status::status( int info, int sigNumber, int exitCode )
{
 i_info 		= static_cast<statusInfo>( info );
 i_sigNumber	= sigNumber;
 i_exitCode		= exitCode;
}


statusInfo status::getInfo( void ) const noexcept
{
 return i_info;
}


int status::getSignal( void	) const noexcept
{
 return i_sigNumber;
}

int status::getCode( void )	const noexcept
{
 return i_exitCode;
}


}	// End of namespace "process"

}   // End of namespace "osapi"
