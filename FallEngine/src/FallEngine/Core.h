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

#ifdef FALL_ENABLE_ASSERTS
	#define FALL_CORE_ASSERT(x, ...) { if (!(x)) { F_CORE_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
	#define FALL_ASSERT(x, ...)      { if (!(x)) { F_ERROR("Assertion Failed: {}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FALL_CORE_ASSERT(x, ...)
	#define FALL_ASSERT(x, ...)
#endif