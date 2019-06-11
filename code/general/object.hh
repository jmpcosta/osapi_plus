// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide the definition of a basic OSAPI object
//
// *****************************************************************************************

#ifndef OSAPI_GENERAL_OBJECT_HH_
#define OSAPI_GENERAL_OBJECT_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <string>

// *****************************************************************************************
//
// Section: Type declaration/definition
//
// *****************************************************************************************


namespace osapi
{

/// @brief Definition of an opaque Object type
class object
{
public:
	explicit		object	( std::string & name, uint64_t size, void * data );
					~object	( void );

	// Inline methods
	std::string	&	getName	( void ) 		{ return iName; }
	uint64_t		getSize	( void ) 		{ return iSize; }
	void 	*		getData	( void ) const 	{ return iData; }

private:
  std::string		iName;
  uint64_t			iSize;
  void 		*		iData;
};


};	// End of namespace "osapi"

#endif /* OSAPI_GENERAL_OBJECT_HH_ */
