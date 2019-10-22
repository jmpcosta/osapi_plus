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
#include <functional>

// Import OSAPI++ generic headers
#include "general/general.hh"
#include "status/status.hh"
#include "status/trace.hh"
#include "common/common.hh"

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
 t_status st;

 TRACE_ENTER

 rawData = (void *) new t_proc;

 st = proc_data_clear( (t_proc *) rawData );
 if( status_failure( st ) )
     throw_error( "Unable to clear process raw data" );

 TRACE_EXIT
}


plan::~plan()
{
 TRACE_ENTER

 // Deallocate memory from Heap
 if( rawData != nullptr )
   {
	 t_proc	*	p_proc	= (t_proc *) rawData;

	 char	**	p_array;
	 size_t		size;

	 t_status st = proc_data_getEnvironment( p_proc, &size, &p_array );
	 if( status_success( st ) )
	   {
		 if( p_array != nullptr ) delete p_array;
		 TRACE( "Successfully deallocated process environment" )
	   }

	 // Deallocate command line
	 st = proc_data_getCmdLine( p_proc, &size, &p_array );
	 if( status_success( st ) )
	   {
		 if( p_array != nullptr ) delete p_array;
		 TRACE( "Successfully deallocated process environment" )
	   }

	 delete (t_proc *) rawData;
   }

 TRACE_EXIT
}


void * plan::getRaw( void )
{
 TRACE_POINT
 return rawData;
}

bool plan::addCommandLine( const std::vector<const char *> & line )
{
 t_status			st;
 char	**			p_array		= nullptr;
 std::size_t		vsize		= line.size();
 t_size				asize		= 0;

 t_proc	*	p_proc		= (t_proc *) rawData;

 TRACE_ENTER

 if( vsize <= 0 )
	 throw_error( "No command line provided !" );

 st = proc_data_getCmdLine( p_proc, &asize, &p_array );

 if( status_failure( st ) )
   {
	 TRACE( "Environment already exists." )
	 return false;
   }

 p_array = new char * [ vsize + 1 ];

 for( std::size_t i = 0; i < vsize; i++ )
	  p_array[ i ] = (char *) line[ i ];

 p_array[ vsize ] = nullptr;

 st = proc_data_setCmdLine( vsize + 1, p_array, p_proc );
 if( status_success( st ) )
   { TRACE( "Successfully set the process environment with ", vsize, " values." ) }

 TRACE_EXIT

 return true;
}

bool plan::addEnvironment( const std::vector<const char *> & env )
{
 t_status			st;
 char	**			p_array		= nullptr;
 std::size_t		vsize		= env.size();
 t_size				asize		= 0;

 t_proc	*	p_proc		= (t_proc *) rawData;

 TRACE_ENTER

 if( vsize <= 0 )
	 throw_error( "No command line provided !" );

 st = proc_data_getEnvironment( p_proc, &asize, &p_array );

 if( status_failure( st ) )
   {
	 TRACE( "Environment already exists." )
	 return false;
   }

 p_array = new char * [ vsize + 1 ];

 for( std::size_t i = 0; i < vsize; i++ )
	  p_array[ i ] = (char *) env[ i ];

 p_array[ vsize ] = nullptr;

 st = proc_data_setEnvironment( vsize + 1, p_array, p_proc );
 if( status_success( st ) )
   { TRACE( "Successfully set the process environment with ", vsize, " values." ) }

 TRACE_EXIT

 return true;
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

 st = proc_data_getUser( p_proc, &uid );
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

 st = proc_data_getGroup( p_proc, &gid );
 throw_on_failure( st );

 st = sec_group_idToString( gid, OSAPI_STRING_SIZE_GID, str );
 throw_on_failure( st );

 // Ensure that the string is null-terminated
 str[ OSAPI_STRING_SIZE_GID ] = '\0';

 return std::string( str );
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


bool plan::addName( const std::string & procName )
{
 // Convert the generic pointer to the concrete OSAPI t_proc pointer
 t_proc * p_proc = (t_proc *) rawData;

 p_proc->name = (char *) procName.c_str();

 return true;	// To keep the interfaces consistent
}


bool plan::getCommandLine( std::vector<const char *> & cmdLine )
{
 t_proc *				p_proc	= (t_proc *) rawData;
 char **				p_line	= nullptr;
 t_size					nargs	= 0;

 TRACE_ENTER

 t_status st = proc_data_getCmdLine( p_proc, &nargs, &p_line );

 if( status_failure( st ) ) return false;

 TRACE( "Successfully retrieved process environment" )

 cmdLine.clear();
 for( t_size i=0; i < nargs; i++ )
	 cmdLine.push_back( (const char *) p_line[ i ] );

 TRACE_EXIT

 return true;
}

bool plan::getEnvironment( std::vector<const char *> & env )
{
 t_proc *				p_proc	= (t_proc *) rawData;
 char **				p_env	= nullptr;
 t_size					nargs	= 0;

 TRACE_ENTER

 t_status st = proc_data_getEnvironment( p_proc, &nargs, &p_env );

 if( status_failure( st ) ) return false;

 TRACE( "Successfully retrieved process environment" )

 env.clear();
 for( t_size i=0; i < nargs; i++ )
	  env.push_back( (const char *) p_env[ i ] );

 TRACE_EXIT

 return true;
}


/*
char * plan::getUser( void )
{

 t_proc * p_proc = (t_proc *) rawData;

 TRACE_ENTER

 TRACE_EXIT
}


char * plan::getGroup( void	)
{

 t_proc * p_proc = (t_proc *) rawData;

 TRACE_ENTER

 TRACE_EXIT
}
*/

char * plan::getName( void )
{
 TRACE_ENTER

 if( rawData == nullptr )
	 throw_error( "No process plan data found" );

 t_proc * p_proc = (t_proc *) rawData;
 char   * procName;
 t_status st;

 st = proc_data_getName( p_proc, &procName );

 // Ensure that there is a valid content
 if( status_failure( st ) )
   {
	 TRACE( "No process name available, using sane values" )
     procName=(char *) empty_string;
   }

 TRACE_EXIT

 return procName;
}




}	// End of namespace "process"

}	//End of OSAPI namespace
