#ifndef CPPFORALL_H_
#define CPPFORALL_H_

// CPPFORALL_SHARED is required for multiplatform support
#if defined( _WIN32 ) || defined( _WIN64 )
#   ifdef CPPFORALL_EXPORTS
#       define CPPFORALL_SHARED __declspec( dllexport )
#   else
#       define CPPFORALL_SHARED __declspec( dllimport )
#   endif
#else
#   define CPPFORALL_SHARED __attribute__( ( visibility( "default" ) ) )
#endif

#endif //CPPFORALL_H_
