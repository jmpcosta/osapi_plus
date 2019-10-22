// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide File system module API for file type
//
// *****************************************************************************************

#ifndef OSAPI_FS_FILE_HH_
#define OSAPI_FS_FILE_HH_

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
#include "common/buffer.hh"

// Import own Module declarations
#include "filesystem/element.hh"
#include "filesystem/fileInfo.hh"

// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{

namespace filesystem
{

class file : public element
{
public:
								// Constructor & Destructor
	explicit					file( const std::string & filename );
								~file();

			void				setOpenMode		( const std::string & mode );	// To avoid that other elements have a mode parameter on the open method
			void				open			( void );
			void			 	refresh			( void );

			// read and write functions to handle binary data
			// need operators << and >> for read/write strings into the file
			void				write	( const osapi::buffer & buf );
			// Returns eof
			bool				read	( osapi::buffer & buf );
			void				close	( void );

private:
			void	*					p_iFile;
			std::vector<std::string>	iOpenMode;

			TRACE_CLASSNAME_DECLARATION
};


}	// End of namespace "filesystem"
}	// End of namespace "osapi"

#endif /* OSAPI_FS_FILE_HH_ */
