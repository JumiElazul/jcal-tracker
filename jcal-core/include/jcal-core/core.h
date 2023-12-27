#pragma once

#ifdef JUMI_WINDOWS

    #ifdef JUMI_EXPORT_API
        #define JUMI_API __declspec(dllexport)
    #else
        #define JUMI_API __declspec(dllimport)
    #endif

#else

    #define JUMI_API __attribute__((visibility("default")))

#endif
