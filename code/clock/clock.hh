// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide Clock module API
//
// *****************************************************************************************

#ifndef OSAPI_CLOCK_HH_
#define OSAPI_CLOCK_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>

// Import OSAPI++ declarations
#include "general/types.hh"
#include "status/trace_macros.hh"

// Import own Module declarations
#include "clock/precision.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

/// @brief Class that provides clock functionality
/// A clock is a time representation
class clock
{
public:

		/// @brief Are clocks supported by this platform?
		/// @return True if supported, False otherwise
		static bool				isSupported	( void );

		/// @brief Default Clock constructor
		/// This constructor will initialize the clock instance with current machine/OS standard time
								clock	( void );
		/// @brief Default destructor
								~clock	( void );

		/// @brief Construct a clock using a time zone code
		/// @param [in] timezone - The time zone information (e.g. CST)
		explicit 				clock 	( const std::string & 		timezone	);

		/// @brief Construct a clock using a time zone code
		/// @param [in] timezone - The time zone information (e.g. CST)
		explicit 				clock 	( const char * 		  		timezone	);

		/// @brief Construct a clock using a time offset from standard time
		/// @param [in] seconds   - The number of seconds since the machine time origin
		/// @param [in] fraction  - The fraction of a second
		/// @param [in] precision - The level of precision of the clock (milli, micro, nano seconds, etc.)
		explicit 				clock 	( int64_t seconds, uint64_t fraction, precision	prec	);

		/// @brief Get the level of precision of the clock instance
		/// @return The precision of the clock
		precision				getPrecision	( void );

		/// @brief Update current clock time
		void					update			( void );

		/// @brief Get the clock Standard Time. This call doesn't update the time of the clock instance
		/// @param [out] seconds   - The number of seconds since the machine time origin
		/// @param [out] fraction  - The fraction of a second
		/// @param [out] precision - The level of precision of the clock (milli, micro, nano seconds, etc.)
		void					getTime			( int64_t & seconds, uint64_t & fraction, precision	& prec );

		/// @brief Get the clock local time. This call doesn't update the time of the clock instance
		/// @param [out] seconds   - The number of seconds since the machine time origin
		/// @param [out] fraction  - The fraction of a second
		/// @param [out] precision - The level of precision of the clock (milli, micro, nano seconds, etc.)
		void					getLocalTime	( int64_t & seconds, uint64_t & fraction, precision	& prec );

private:
		void 		*			p_iClock;

		TRACE_CLASSNAME_DECLARATION
};



}	// End of namespace "osapi"


#endif /* OSAPI_CLOCK_HH_ */
