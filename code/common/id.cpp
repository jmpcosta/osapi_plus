// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide General ID implementation
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "sec/sec_identity.h"
#include "proc/proc_identity.h"
#include "proc/proc_instance.h"

// Import C++ system headers
#include <string>

// Import OSAPI+ headers
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "common/id.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{
namespace id
{

TRACE_CLASSNAME( process )
TRACE_CLASSNAME( user    )
TRACE_CLASSNAME( group   )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************




process::process( int64_t pid )
{ myPID = pid; }


int64_t process::get( void )
{ return myPID; }

void process::set( int64_t pid )
{ myPID = pid; }


bool user::exists( std::string id )
{
 t_status 	st;
 t_uid		iUid;

 // Convert from string to platform type
 st = sec_user_getIdFromName( (t_char *) id.c_str(), &iUid );
 if( status_failure( st ) ) return false;

 // Test the existence of the User
 st = sec_user_exists( iUid );
 if( status_failure( st ) ) return false;

 return true;
}

user::user( std::string & uid )
{
 if( ! exists( uid ) )
	 throw status("Process ID doesn't exist.");

 // If the group exists in the system, create instance of Group ID
 myUID = uid;
}

std::string & user::get( void )
{
 return myUID;
}



bool group::exists( std::string id )
{
 t_status 	st;
 t_uid		iUid;

 // Convert from string to platform type
 st = sec_user_getIdFromName( (t_char *) id.c_str(), &iUid );
 if( status_failure( st ) ) return false;

 // Test the existence of the User
 st = sec_group_exists( iUid );
 if( status_failure( st ) ) return false;

 return true;
}


group::group( std::string & gid )
{
 if( ! exists( gid ) )
	 throw status("Process ID doesn't exist.");

 // If the group exists in the system, create instance of Group ID
 myGID = gid;
}

std::string & group::get( void )
{
 return myGID;
}



}	// End of namespace "process"

}	// End of namespace "osapi"
