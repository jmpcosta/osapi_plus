// *****************************************************************************************
//
// File description:
//
// Author:	Joao Costa
// Purpose:	Provide tracing macros
//
// *****************************************************************************************


// *****************************************************************************************
//
// Section: Supporting macros
//
// *****************************************************************************************


#ifdef OSAPI_TRACING
 #define TRACE_CLASSNAME_DECLARATION	static const char *	classname;
 #define TRACE_CLASSNAME(x)				const char * x::classname= #x ;
 #define TRACE_ENTER					trace	( classname, "::", __FUNCTION__, " - Entering"			);
 #define TRACE_EXIT						trace	( classname, "::", __FUNCTION__, " - Leaving"			);
 #define TRACE_POINT					trace	( classname, "::", __FUNCTION__, " - Passing through"	);
 #define TRACE(...)						trace	( classname, "::", __FUNCTION__, " - ", __VA_ARGS__		);		// For instance methods
#else
 #define TRACE_CLASSNAME_DECLARATION
 #define TRACE_CLASSNAME(x)
 #define TRACE_ENTER
 #define TRACE_EXIT
 #define TRACE_POINT
 #define TRACE(...)
#endif
