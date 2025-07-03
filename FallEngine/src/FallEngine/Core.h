#pragma once

#ifdef F_PLATFORM_WINDOWS
	#ifdef F_BUILD_DLL
		#define FALL_API __declspec(dllexport)
	#else
		#define FALL_API __declspec(dllimport)
	#endif
#else
	#error FallEngine only support window!
#endif 