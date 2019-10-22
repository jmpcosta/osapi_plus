// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide an enumeration of the file system element types
//			This file must match the OSAPI C counter part (fs/type/fs_type_type.h)
//
// *****************************************************************************************

#ifndef OSAPI_FS_ELEMENTTYPE_HH_
#define OSAPI_FS_ELEMENTTYPE_HH_


// *****************************************************************************************
//
// Section: Module API declaration
//
// *****************************************************************************************

namespace osapi
{
namespace filesystem
{

/// @brief The elementType enum represents the possible elements of a file system
enum class elementType : int
{
  unknown		= 0, ///< Unknown element
  file			= 1, ///< The element is a file
  directory		= 2, ///< The element is a directory
  softLink		= 3, ///< The element is a soft link
  hardLink		= 4  ///< The element is a hard link
  // ...
};


}	// End of namespace "filesystem"
}	// End of namespace "osapi"

#endif /* OSAPI_FS_ELEMENTTYPE_HH_ */
