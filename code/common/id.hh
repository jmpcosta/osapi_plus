// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide General Identifier interfaces
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_ID_HH_
#define OSAPI_COMMON_ID_HH_


// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <cstdint>



namespace osapi
{
namespace id
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

/// @brief Class that represents a Process ID
class process
{
public:
		/// @brief Class constructor
		/// @param [in] pid - The new process ID
						process		( int64_t pid	);

		/// @brief Class destructor
						~process() {}

		/// @brief Get the Process ID
		int64_t		 	get			( void			);

		/// @brief Set the Process ID
		/// @param [in] newId - Overwrite the ID with a new process ID
		void			set			( int64_t newId	);

private:
		int64_t		  	myPID;

		TRACE_CLASSNAME_DECLARATION
};


/// @brief Class that represents a User ID
class user
{
public:
		/// @brief Class constructor
		/// @param [in] uid - The new user ID
						user( std::string & uid );
		/// @brief Class destructor
						~user() {}

		/// @brief Get the Process ID
		std::string	& 	get( void );

		/// @brief Verify if there is such user created in the system
		static bool		exists( std::string id );

private:
		std::string 	myUID;

		TRACE_CLASSNAME_DECLARATION
};


/// @brief Class that represents a Group ID
class group
{
public:
		/// @brief Class constructor
		/// @param [in] gid - The new group ID

						group( std::string & gid );

		/// @brief Class destructor
						~group() {}

		std::string	& 	get( void );
		static bool		exists( std::string id );

private:
		std::string 	myGID;

		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "process"

}	// End of namespace "osapi"


#endif /* OSAPI_COMMON_ID_HH_ */
