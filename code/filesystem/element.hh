// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide File system module API
//
// *****************************************************************************************

#ifndef OSAPI_FS_ELEMENT_HH_
#define OSAPI_FS_ELEMENT_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <ctime>

// Import OSAPI++ declarations
#include "general/types.hh"
#include "status/trace_macros.hh"

// Import own Module declarations
#include "filesystem/elementType.hh"

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace filesystem
{

class element
{
public:
		// delete copy and move constructors and assign operators
		element( element const& ) 				= delete;		// Copy construct
		element( element&&      ) 				= delete;		// Move construct
		element& operator=( element const& )	= delete; 		// Copy assign
		element& operator=( element &&     )	= delete;		// Move assign

		bool	operator==(element const & elem1 );


		static bool						exists				( const std::string & path 	);
		static elementType				getType				( const std::string & path	);

		// CRUD operations. The Creation can't be performed for a generic FS element and Update also doesn't make sense
		static bool						remove				( const std::string & path 	);
		static bool						copy				( const std::string & source, const std::string & target );
		static bool						copy				( const std::string & source, const std::string & target, bool overwrite );
		//static bool					copy				( const std::string & source, const std::string & target, const std::vector<std::string> & options );
		static bool						move				( const std::string & source, const std::string & target );

		// The following operations are specific to each FS element type
		virtual void					open				( void ) = 0;
		virtual void					refresh				( void ) = 0;
		virtual void					close				( void ) = 0;

		// The following operations can use a generic implementation
		/*
		virtual void					getUID				( void );
		virtual void					getGID				( void );
		virtual std::string const &		getName				( void ) const { return name; }
		virtual elementType				getType				( void ) const { return type; }
		virtual uint64_t				getSize				( void ) const { return size; }
		virtual std::time_t				getCreationTime		( void );
		virtual std::time_t				getModificationTime	( void );
		virtual std::time_t				getAccessTime		( void );
		*/

protected:
		// Methods
										element				( void );
		virtual							~element			( void );

		// Variables
		std::string				name;		// Every element has a name
		elementType				type;		// Every element has a type;
		uint64_t				size;		// Size of element on filesystem
private:

		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "filesystem"
}	// End of namespace "osapi"

#endif /* OSAPI_FS_ELEMENT_HH_ */
