// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Implementation of the OSAPI+ library interface
//
// *****************************************************************************************

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Include OSAPI C headers
#include "proc/proc_resource.h"

// Import C++ system headers
#include <stdexcept>

// Import own module declarations
#include "general/object.hh"

// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************

namespace osapi
{


object::object( std::string & name, uint64_t size, void * data )
{
 // Sanity checks
 if( iData == nullptr )
	 throw std::invalid_argument( "Object Name missing" );

 if( size < 1 )
	 throw std::invalid_argument( "Object Size must be greater than 0" );

 if( iData == nullptr )
	 throw std::invalid_argument( "Object Data pointer is null" );

 // All conditions are met, assign
 iName = std::move( name );
 iSize = size;
 iData = data;
}


object::~object()
{
 proc_memory_deallocate( iData );
}

}	// End of namespace "osapi"
