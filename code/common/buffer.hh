// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide a notion of a buffer
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_BUFFER_HH_
#define OSAPI_COMMON_BUFFER_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <cstdint>

// Import OSAPI++ declarations
#include "general/types.hh"
#include "status/trace_macros.hh"

namespace osapi
{


// *****************************************************************************************
//
// Section: Module Constant definitions
//
// *****************************************************************************************



// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

/// @brief Class that hides the OSAPI buffer implementation
class buffer
{
public:
		/// @brief Class constructor
		/// @param [in] size - The size of the buffer
						buffer( uint64_t size );

		/// @brief Class destructor
						~buffer();

		/// @brief Get the capacity of the buffer
		uint64_t		getCapacity();

		/// @brief Get the size of the buffer
		uint64_t		getSize();

		/// @brief Get buffer type starting address
		void	*	 	getAddress() const { return p_iBuffer; };

		/// @brief Get buffer raw data starting address
		void	*	 	getData();

private:
		void	*	  	p_iBuffer;

		TRACE_CLASSNAME_DECLARATION
};




}	// End of namespace "osapi"


#endif /* OSAPI_COMMON_BUFFER_HH_ */
