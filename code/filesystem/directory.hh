// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide File system module API for directory type
//
// *****************************************************************************************

#ifndef OSAPI_FS_DIRECTORY_HH_
#define OSAPI_FS_DIRECTORY_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>
#include <vector>

// Import OSAPI++ declarations
#include "general/types.hh"
#include "status/trace_macros.hh"

// Import own Module declarations
#include "filesystem/element.hh"


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace filesystem
{

class directory : public element
{
public:
									// Constructor & Destructor
									//directory( const std::string & dirname );
		explicit					directory( const std::string & name );
									~directory();

		void						open			( void );
		void						refresh			( void );
		void						close			( void );

		bool						getEntries		( std::vector<element> & list );
		elementType					getEntryType	( std::vector<element> & list, uint64_t listItem );

private:
		void	*					p_directory;
		TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "filesystem"
}	// End of namespace "osapi"

#endif /* OSAPI_FS_DIRECTORY_HH_ */
