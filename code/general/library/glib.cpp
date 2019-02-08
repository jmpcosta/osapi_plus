// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	GNU Library C++ functions
//		Functions that must work only with the stdc++ library
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include OSAPI C headers
#include "status/status.h"
#include "proc/proc.h"

// Include Standard headers
#include <cstring>

// Include module declarations
#include "general/general.hh"

// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

#ifdef __GLIBCXX__

namespace osapi
{


bool library::cppBaseline()	noexcept
{
 t_size		number = 0;
 t_status	st;

 // Get the number of loaded libraries in the process
 st = proc_library_getNumberOfLoaded( &number );
 if( status_failure( st ) || number == 0 ) return false;

 t_libinfo (* p_libinfo)[];

 st = proc_memory_allocate( number * sizeof( t_libinfo), (void **) &p_libinfo );

 if( status_failure( st ) ) return false;

 st = proc_library_getAllLoaded( number, p_libinfo );

 if( status_failure( st ) )
   {
	 proc_memory_deallocate( (void *) p_libinfo );
	 return false;
   }

 // Get GNU C++ library information
 char * libname		= NULL;
 t_size	libversion	= 0;
 t_size	i;

 for( i=0; i < number; i++ )
 	{
	  libname 		= proc_getLibraryName		( p_libinfo, i );
	  libversion	= proc_getLibraryVersion	( p_libinfo, i );

	  // If current library the stdc++ ?
	  if( strstr( libname, CPP_LIBRARY_NAME ) != NULL )	// Found
		  break;
 	}

 if( i == number )	// Library not found
	 return false;

 // Compare versions / check required baseline

 if( CPP_TARGET_RELEASE > libversion ) 	 return false;

 return true;
}

}	// End of namespace "osapi"



#endif // __GLIBCXX__
