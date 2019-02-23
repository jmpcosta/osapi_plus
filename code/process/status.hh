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

/// @brief The statusInfo enum represents all possible platforms process states
enum class statusInfo
{
  // Status from POSIX platforms
  unavailable	= 0,	///< Running or dead
  available		= 1,	///< Normal exit with exit code
  signal		= 2,	///< Exit due to signal, no exit code
  core			= 3,	///< Exit and core dump, no exit code
  stopped		= 4,	///< Process stopped, no exit code
  continued		= 5		///< Process resumed, no exit code

  // Status from Windows OSs

  // Status from other platforms...
};


/// @brief The process status class encapsulates the actions that are required to obtain status information
class status
{
public:
		/// @brief Class constructor
		/// @param [in] info		- Status information
		/// @param [in] signumber	- Signal number (if terminated by signal)
		/// @param [in] exitCode	- Process exit code when normal exit
					status( int info, int signumber, int exitCode );

		/// @brief Class destructor
					~status() {}

		/// @brief Get the Process status information
		/// @return Process status information
		statusInfo	getInfo( void 			)	const noexcept;

		/// @brief Get the signal number responsible for the process termination
		/// @return Termination signal number
		int			getSignal( void			)	const noexcept;

		/// @brief Get the Process exit code
		/// @return Exit code, when process exited normally
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
