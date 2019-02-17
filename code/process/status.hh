// *********************************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide process status information
//
// **********************************************************************************************************

#ifndef OSAPI_PROCESS_STATUS_HH_
#define OSAPI_PROCESS_STATUS_HH_

// **********************************************************************************************************
//
// Section: Define all possible process status (i.e. superset of all status from all supported platforms).
//			The enum bellow must contain all status from all platforms of the corresponding OSAPI C headers.
//
// **********************************************************************************************************

namespace osapi
{

namespace process
{


enum class statusInfo
{
  // Status from POSIX platforms
  unavailable	= 0,	// Running or dead
  available		= 1,	// Normal exit with exit code
  signal		= 2,	// Exit due to signal, no exit code
  core			= 3,	// Exit and core dump, no exit code
  stopped		= 4,	// Process stopped, no exit code
  continued		= 5		// Process resumed, no exit code

  // Status from Windows OSs

  // Status from other platforms...
};


class status
{
public:
					status( int info, int signumber, int exitCode );
					~status() {}

		statusInfo	getInfo( void 			)	const noexcept;
		int			getSignal( void			)	const noexcept;
		int			getCode( void			)	const noexcept;

private:
		statusInfo	i_info;
		int			i_sigNumber;
		int			i_exitCode;

		TRACE_CLASSNAME_DECLARATION
};

}	// End of namespace "process"

}	// End of namespace "osapi"


#endif /* OSAPI_PROCESS_STATUS_HH_ */
