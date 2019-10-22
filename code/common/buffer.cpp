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
#include "common/common_buffer.h"

// Import C++ system headers

// Import OSAPI+ headers
#include "status/status.hh"
#include "status/trace.hh"

// Import own module declarations
#include "common/buffer.hh"


// *****************************************************************************************
//
// Section: Module constants
//
// *****************************************************************************************

namespace osapi
{

TRACE_CLASSNAME( buffer )



// *****************************************************************************************
//
// Section: Function definition
//
// *****************************************************************************************




buffer::buffer( uint64_t size )
{
 TRACE_ENTER

 // Alloc buffer type
 p_iBuffer = (void *) new t_buffer;

 t_status st = common_buffer_allocate( (t_size) size, (t_buffer *) &p_iBuffer );

 throw_on_failure( st );

 TRACE_EXIT
}


buffer::~buffer()
{
 TRACE_ENTER

 // Deallocate raw buffer
 common_buffer_deallocate( (t_buffer *) p_iBuffer );

 // Deallocate also the type itself
 delete (t_buffer *) p_iBuffer;

 TRACE_EXIT
}


uint64_t buffer::getSize( void )
{
 TRACE_ENTER

 // Alloc buffer type
 t_buffer * p_buffer = (t_buffer *) p_iBuffer;

 t_size size = 0;
 t_status st = common_buffer_getSize( p_buffer, &size );

 throw_on_failure( st );

 TRACE_EXIT

 return (uint64_t) size;
}


uint64_t buffer::getCapacity( void )
{
 TRACE_ENTER

 // Alloc buffer type
 t_buffer * p_buffer = (t_buffer *) p_iBuffer;

 t_size size = 0;
 t_status st = common_buffer_getCapacity( p_buffer, &size );

 throw_on_failure( st );

 TRACE_EXIT

 return (uint64_t) size;
}


void * buffer::getData( void )
{
 TRACE_ENTER

 // Alloc buffer type
 t_buffer * p_buffer = (t_buffer *) p_iBuffer;

 void * p_data = nullptr;
 t_status st = common_buffer_getData( p_buffer, &p_data );

 throw_on_failure( st );

 TRACE_EXIT

 return p_data;
}


}	// End of namespace "osapi"
