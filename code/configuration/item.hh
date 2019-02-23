// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose: Defines the Interface for Configuration Items
//
// *****************************************************************************************

#ifndef OSAPI_CONFIGURATIONITEM_HH_
#define OSAPI_CONFIGURATIONITEM_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>


// *****************************************************************************************
//
// Section: Interface for any Configuration Item
//
// *****************************************************************************************


namespace osapi
{

namespace configuration
{

/// @brief The Configuration Item interface class
class item
{
public:
		/// @brief The virtual Class destructor
		virtual		 				~item				();

		/// @brief The interface to retrieve the CI in string format
		/// @return A reference to the CI in string format
		virtual std::string const &	getString			() const						= 0;

		/// @brief The interface to set the CI (string format)
		/// @param [in] value - The CI in string format
		virtual void				setString			( const std::string & value ) 	= 0;

		/// @brief The interface to verify if two CIs are identical
		/// @param [in] name - The name of the CI
		/// @return True if both CIs are identical, false otherwise
		virtual bool 				equal				( const std::string & name  )	= 0;
};


}	// End of namespace "configuration"

}	// End of namespace

#endif /* OSAPI_CONFIGURATIONITEM_HH_ */
