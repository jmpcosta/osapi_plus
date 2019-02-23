// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	API declaration for managing shared libraries
//
// *****************************************************************************************

#ifndef OSAPI_PROCESS_LIBRARY_HH_
#define OSAPI_PROCESS_LIBRARY_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

// Import OSAPI++ declarations
#include "general/general.hh"
#include "status/trace_macros.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace process
{

/// @brief Class that represents a shared library
class library
{
public:
		/// @brief Class constructor
		/// @param [in] name 	- Library name
		explicit			library		( std::string & name );

		/// @brief Class destructor
							~library	();

		/// @brief Load the shared library into the current process
		/// @param [in] options	- Vector of strings with system specific load options
		/// @return Operation status, True if successful, False otherwise
		bool				load		( std::vector<std::string> & options );

		/// @brief Unload the shared library from the current process
		/// @return Operation status, True if successful, False otherwise
		bool				unload		( void );

		/// @brief Get the current library release number
		/// @return A string containing the release number
		std::string			getRelease	( void );

		/// @brief Get the last library error
		/// @return A string containing the last error
		std::string	&		getLastError( void );


private:
		// Instance variables

		bool				isLoaded;
		std::string 		libName;
		std::string			lastError;
		void			*	libInfo;


		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "process"

}	// End of namespace "osapi"




#endif /* OSAPI_PROCESS_LIBRARY_HH_ */
