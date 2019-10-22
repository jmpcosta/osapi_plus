// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide the definition of a basic OSAPI object
//
// *****************************************************************************************

#ifndef OSAPI_COMMON_OBJECT_HH_
#define OSAPI_COMMON_OBJECT_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <cstddef>
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
	void 	*		getData	( void );

private:
	std::string			iName;
	uint64_t			iSize;
	void 		*		iData;
};


};	// End of namespace "osapi"

#endif /* OSAPI_COMMON_OBJECT_HH_ */
