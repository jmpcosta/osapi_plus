// *********************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide the precision of a clock
//
// **********************************************************************************************************

#ifndef OSAPI_CLOCK_PRECISION_HH_
#define OSAPI_CLOCK_PRECISION_HH_

// **********************************************************************************************************
//
// Section: Define possible clock precisions
//			The enum bellow must be a copy of the corresponding OSAPI C header file: common_type_time.h
//
// **********************************************************************************************************

namespace osapi
{

/// @brief The state enum represents the precision for a fraction of a clock
enum class precision
{
    unspecified	= 0	, 	///< Unspecified precision
    second			,  	///< Precision to the second
    tsecond			,  	///< Precision to the tens of a second
    hsecond			,  	///< Precision to the hundreds of a second
    milli			,  	///< Precision to the millisecond (10^3)
    tmilli			,  	///< Precision to the tens of a millisecond (10^4)
    hmilli			,  	///< Precision to the hundreds of a millisecond (10^5)
    micro			,  	///< Precision to the microsecond (10^6)
    tmicro			,  	///< Precision to the tens of a microsecond (10^7)
    hmicro			,  	///< Precision to the hundreds of a microsecond (10^8)
    nano			,  	///< Precision to the nanosecond  (10^9)
    pico			,  	///< Precision to the picosecond  (10^12)
    femto			,  	///< Precision to the femtosecond (10^15)
    atto			,  	///< Precision to the attosecond  (10^18)
    zepto			,  	///< Precision to the zeptosecond (10^21)
    yocto			,  	///< Precision to the yoctosecond (10^24)
    planck			,  	///< Theorical smallest precision possible (10^44) of a second

    minute			,  	///< Precision to the minute
    hour	  			///< Precision to the hour
};



}	// End of namespace "osapi"


#endif /* OSAPI_CLOCK_PRECISION_HH_ */
