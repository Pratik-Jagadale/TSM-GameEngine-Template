#pragma once

//#define TSM_PLATFORM_WINDOWS

#ifdef TSM_PLATFORM_WINDOWS
	#ifdef  TSM_BUILD_DLL
		#define TSM_API __declspec(dllexport)
	#else
		#define TSM_API __declspec(dllimport)
	#endif //  TSM_BUILD_DLL
#include<Windows.h>
#else

#error TSM Only Supports The Windows!

#endif // TSM_PLATFORM_WINDOWS

#ifdef TSM_ENABLE_ASSERT
	#define TSM_ASSERT(x, ...){ if(!(X)) {TSM_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
	#define TSN_ASSERT(x, ...){ if(!(X)) {TSM_CORE_ERROR("Assertion Failed : {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define TSM_ASSERT(x, ...)
	#define TSN_ASSERT(x, ...)
#endif // TSM_ENABLE_ASSERT


