// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose: Defines the Interface for Configuration Items
//
// *****************************************************************************************

#ifndef CONFIGURATION_CONFIGURATIONITEM_HH_
#define CONFIGURATION_CONFIGURATIONITEM_HH_

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

class configurationItem
{
public:
		virtual		 				~configurationItem	();
		virtual const std::string &	getString			() const						= 0;
		virtual void				setString			( const std::string & value ) 	= 0;
		virtual bool 				equal				( const std::string & name  )	= 0;
};



}	// End of namespace

#endif /* CONFIGURATION_CONFIGURATIONITEM_HH_ */
