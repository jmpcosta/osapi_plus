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

class process
{
public:
						process		( int64_t pid	);
						~process() {}

		int64_t		 	get			( void			);
		void			set			( int64_t newId	);

private:
		int64_t		  	myPID;

		TRACE_CLASSNAME_DECLARATION
};


class user
{
public:
						user( std::string & uid );
						~user() {}

		std::string	& 	get( void );
		static bool		exists( std::string id );

private:
		std::string 	myUID;

		TRACE_CLASSNAME_DECLARATION
};


class group
{
public:
						group( std::string & gid );
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
