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

// Include the C OSAPI interfaces first
#include "status/status.h"
#include "sec/sec.h"
#include "proc/proc.h"

// Import C++ system headers
#include <iostream>
#include <string>

// Import OSAPI++ generic headers
#include "general/general.hh"
#include "status/status.hh"
#include "status/trace.hh"
#include "util/util.hh"

// Import own module declarations
#include "process/plan.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{
namespace process
{

TRACE_CLASSNAME( plan )


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

// ProcessData Instance methods

plan::plan( void )
{
 TRACE_ENTER

 // Initialize data
 environment	= nullptr;
 cmdLine		= nullptr;

 t_status st;
 st = proc_memory_allocate( sizeof(t_proc), & rawData );
 if( status_failure( st ) )
   {
	 rawData = nullptr;
     throw_error( "Unable to allocate process raw data" );
   }

 t_proc * p_proc = (t_proc *) rawData;
 st = proc_data_clear( p_proc );
 if( status_failure( st ) )
     throw_error( "Unable to clear process raw data" );

 TRACE_EXIT
}


plan::~plan()
{
 TRACE_ENTER

 // Deallocate memory from Heap
 if( cmdLine     != nullptr )	proc_memory_deallocate( cmdLine 	);
 if( environment != nullptr )	proc_memory_deallocate( environment	);
 if( rawData     != nullptr )	proc_memory_deallocate( rawData		);

 TRACE_EXIT
}


void * plan::getRaw( void )
{
 TRACE_POINT
 return rawData;
}

bool plan::setCmdLine( std::vector<std::string> & line )
{
 bool		ret			= false;
 char	**	p_array;
 t_proc	*	p_proc		= (t_proc *) rawData;
 size_t		size;

 TRACE_ENTER

 if( cmdLine != nullptr )
	 proc_memory_deallocate( cmdLine );

 ret = util::vecStr2array( line, &size, &p_array );

 if( ret )
   {
	 TRACE( "Successfully transformed vector of strings to array of char pointers" )
	 cmdLine = (void *) p_array;
	 t_status st = proc_data_setCmdLine( size, p_array, p_proc );
	 throw_on_failure( st );
   }

 TRACE_EXIT

 return ret;
}

bool plan::setEnvironment( std::vector<std::string> & env )
{
 bool		ret			= false;
 char	**	p_array;
 t_proc	*	p_proc		= (t_proc *) rawData;
 size_t		size		= env.size();

 TRACE_ENTER

 if( environment != nullptr )
	 proc_memory_deallocate( environment );

 ret = util::vecStr2array( env, &size, &p_array );

 if( ret )
   {
	 TRACE( "Successfully transformed vector of strings to array of char pointers" )
	 environment = (void *) p_array;
	 t_status st = proc_data_setEnvironment( size, p_array, p_proc );
	 throw_on_failure( st );
   }

 TRACE_EXIT

 return ret;
}

std::string	plan::getStringPID( void )
{
 t_status 	st;
 t_proc * 	p_proc = (t_proc *) rawData;
 t_pid  	pid;
 t_char 	str[ OSAPI_STRING_SIZE_PID + 1 ];

 st = proc_data_getPID( p_proc, &pid );
 throw_on_failure( st );

 st = proc_id_toString( pid, OSAPI_STRING_SIZE_PID, str );
 throw_on_failure( st );

 // Ensure that the string is null-terminated
 str[ OSAPI_STRING_SIZE_PID ] = '\0';

 return std::string( str );
}


std::string	plan::getStringUID( void )
{
 t_status 	st;
 t_proc * 	p_proc = (t_proc *) rawData;
 t_uid  	uid;
 t_char 	str[ OSAPI_STRING_SIZE_UID + 1 ];

 st = proc_data_getUID( p_proc, &uid );
 throw_on_failure( st );

 st = sec_user_idToString( uid, OSAPI_STRING_SIZE_UID, str );
 throw_on_failure( st );

 // Ensure that the string is null-terminated
 str[ OSAPI_STRING_SIZE_UID ] = '\0';

 return std::string( str );
}


std::string	plan::getStringGID( void )
{
 t_status 	st;
 t_proc * 	p_proc = (t_proc *) rawData;
 t_gid  	gid;
 t_char 	str[ OSAPI_STRING_SIZE_GID + 1 ];

 st = proc_data_getGID( p_proc, &gid );
 throw_on_failure( st );

 st = sec_group_idToString( gid, OSAPI_STRING_SIZE_GID, str );
 throw_on_failure( st );

 // Ensure that the string is null-terminated
 str[ OSAPI_STRING_SIZE_GID ] = '\0';

 return std::string( str );
}


bool plan::addCommandLine( std::vector<std::string> & args )
{
 if( args.size() <= 0 )
	 throw_error( "No command line provided !" );

 return setCmdLine( args );
}


bool plan::addEnvironment( std::vector<std::string> & env )
{
 if( env.size() <= 0 )
	 throw_error( "No environment provided !" );

 return setEnvironment( env );
}




bool plan::addUser( const std::string & user )
{
 t_status	st;
 bool 		ret = false;
 int64_t	id	= (int64_t) -1;
 t_proc	*	p_proc;
 t_uid		userID;

 // Convert the generic pointer to the concrete OSAPI t_proc pointer
 p_proc = (t_proc *) rawData;

 // The received user may be a user name or user ID
 try
 {
   // Check if it is a user ID (if conversion invalid, exception is thrown
   id = (int64_t) std::stoll( user );
 }
 catch( std::exception const & e ) {}

 if( id > -1 )		// ID is available, use it
     {
	   userID = (t_uid) id;
	   st = proc_data_setUser( userID, p_proc );
	   if( status_success( st ) )	   ret = true;
     }
   else		// Try a user name
     {
	   st = sec_user_stringToId( (char *) user.c_str(), & userID );
	   if( status_success( st ) )
	     {
		   st = proc_data_setUser( userID, p_proc );
		   if( status_success( st ) )  ret = true;
	     }
     }

 return ret;
}

bool plan::addGroup( const std::string & group )
{
 t_status	st;
 bool 		ret = false;
 int64_t	id	= (int64_t) -1;
 t_proc	*	p_proc;
 t_gid		groupID;

 // Convert the generic pointer to the concrete OSAPI t_proc pointer
 p_proc = (t_proc *) rawData;

 // The received user may be a user name or user ID
 try
 {
   // Check if it is a user ID (if conversion invalid, exception is thrown
   id = (int64_t) std::stoll( group );
 }
 catch( std::exception const & e ) {}

 if( id > -1 )		// ID is available, use it
   {
	 groupID = (t_uid) id;
	 st = proc_data_setGroup( groupID, p_proc );
	 if( status_success( st ) )	   ret = true;
   }
 else		// Try a user name
   {
	 st = sec_user_stringToId( (char *) group.c_str(), & groupID );
	 if( status_success( st ) )
	   {
		 st = proc_data_setGroup( groupID, p_proc );
		 if( status_success( st ) )  ret = true;
	   }
   }

 return ret;
}


void plan::addName( const std::string & procName )
{
 // Convert the generic pointer to the concrete OSAPI t_proc pointer
 t_proc * p_proc = (t_proc *) rawData;

 p_proc->name =  (char *) procName.c_str();
}


}	// End of namespace "process"

}	//End of OSAPI namespace
