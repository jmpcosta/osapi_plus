// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide OSAPI wide templates
//
// *****************************************************************************************

#ifndef OSAPI_TEMPLATES_HH_
#define OSAPI_TEMPLATES_HH_

// *****************************************************************************************
//
// Section: Import headers
//
// *****************************************************************************************

// Import C++ system headers
#include <memory>

// *****************************************************************************************
//
// Section: Trace API declaration/definition
//
// *****************************************************************************************

namespace osapi
{


// C++11 Doesn't have the construction to create std::unique_ptr(s)
// note: this implementation does not disable this overload for array types

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}




}	// End of namespace "osapi"

#endif /* OSAPI_TEMPLATES_HH_ */
