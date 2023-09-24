#pragma once

#ifdef HK_PLATFORM_WINDOWS
    #ifdef HK_BUILD_DLL
        #define HIKARU_API __declspec(dllexport)
    #else
        #define HIKARU_API __declspec(dllimport)
    #endif
#else
	#error Hikaru only supports Windows!
#endif // HK_PLATFORM_WINDOWS
