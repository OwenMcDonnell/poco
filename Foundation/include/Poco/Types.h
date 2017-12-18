//
// Types.h
//
// Library: Foundation
// Package: Core
// Module:  Types
//
// Definitions of fixed-size integer types for various platforms
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// SPDX-License-Identifier:    BSL-1.0
//


#ifndef Foundation_Types_INCLUDED
#define Foundation_Types_INCLUDED


#include "Poco/Foundation.h"


#define POCO_HAVE_INT64 1


namespace Poco {

#if defined(_MSC_VER)
    //
    // Windows/Visual C++
    //

    typedef signed char            Int8;
    typedef unsigned char          UInt8;
    typedef signed short           Int16;
    typedef unsigned short         UInt16;
    typedef signed int             Int32;
    typedef unsigned int           UInt32;
    typedef signed long long       Int64;
    typedef unsigned long long     UInt64;
    #define  lit64(c) c ## LL
    #define ulit64(c) c ## ULL

    #if defined(_WIN64)
        #define POCO_PTR_IS_64_BIT 1
        typedef Int64              IntPtr;
        typedef UInt64             UIntPtr;
    #else
        typedef Int32              IntPtr;
        typedef UInt32             UIntPtr;
    #endif

#elif defined(__GNUC__) || defined(__clang__)
    //
    // Unix/GCC/Clang
    //

    typedef signed char                    Int8;
    typedef unsigned char                  UInt8;
    typedef signed short                   Int16;
    typedef unsigned short                 UInt16;
    typedef signed int                     Int32;
    typedef unsigned int                   UInt32;

    #if defined(_WIN64)
        #define POCO_PTR_IS_64_BIT 1
        typedef signed long long           Int64;
        typedef unsigned long long         UInt64;
        typedef Int64                      IntPtr;
        typedef UInt64                     UIntPtr;
        #define  lit64(c) c ##  L
        #define ulit64(c) c ## UL
    #else
        #if defined(__LP64__)
            typedef long                   Int64;
            typedef unsigned long          UInt64;
            #define  lit64(c) c ##  L
            #define ulit64(c) c ## UL

            typedef Int64                  IntPtr;
            typedef UInt64                 UIntPtr;
            #define POCO_PTR_IS_64_BIT 1
            #define POCO_LONG_IS_64_BIT 1
        #else
            typedef long long              Int64;
            typedef unsigned long long     UInt64;
            #define  lit64(c) c ##  LL
            #define ulit64(c) c ## ULL
            typedef Int32                  IntPtr;
            typedef UInt32                 UIntPtr;
        #endif
    #endif

#elif defined(__DECCXX)
    //
    // Compaq C++
    //

    typedef signed char            Int8;
    typedef unsigned char          UInt8;
    typedef signed short           Int16;
    typedef unsigned short         UInt16;
    typedef signed int             Int32;
    typedef unsigned int           UInt32;
    typedef signed __int64         Int64;
    typedef unsigned __int64       UInt64;
    typedef signed long            IntPtr;
    typedef unsigned long          UIntPtr;
    #define POCO_PTR_IS_64_BIT 1
    #define POCO_LONG_IS_64_BIT 1
    #define  lit64(c) c ##  L
    #define ulit64(c) c ## UL

#elif defined(__HP_aCC)
    //
    // HP Ansi C++
    //

    typedef signed char            Int8;
    typedef unsigned char          UInt8;
    typedef signed short           Int16;
    typedef unsigned short         UInt16;
    typedef signed int             Int32;
    typedef unsigned int           UInt32;
    typedef signed long            IntPtr;
    typedef unsigned long          UIntPtr;
    #if defined(__LP64__)
        #define POCO_PTR_IS_64_BIT 1
        #define POCO_LONG_IS_64_BIT 1
        typedef signed long        Int64;
        typedef unsigned long      UInt64;
        #define  lit64(c) c ##  L
        #define ulit64(c) c ## UL
    #else
        typedef signed long long   Int64;
        typedef unsigned long long UInt64;
        #define  lit64(c) c ##  LL
        #define ulit64(c) c ## ULL
    #endif
    #if defined(__LP64__)
        #define POCO_PTR_IS_64_BIT 1
        #define POCO_LONG_IS_64_BIT 1
        typedef Int64 IntPtr;
        typedef UInt64 UIntPtr;
    #else
        typedef Int32 IntPtr;
        typedef UInt32 UIntPtr;
    #endif

#elif defined(__SUNPRO_CC)
    //
    // SUN Forte C++
    //

    typedef signed char            Int8;
    typedef unsigned char          UInt8;
    typedef signed short           Int16;
    typedef unsigned short         UInt16;
    typedef signed int             Int32;
    typedef unsigned int           UInt32;
    typedef signed long            IntPtr;
    typedef unsigned long          UIntPtr;
    #if defined(__sparcv9)
        #define POCO_PTR_IS_64_BIT 1
        #define POCO_LONG_IS_64_BIT 1
        typedef signed long        Int64;
        typedef unsigned long      UInt64;
        #define  lit64(c) c ##  L
        #define ulit64(c) c ## UL
    #else
        typedef signed long long   Int64;
        typedef unsigned long long UInt64;
        #define  lit64(c) c ##  LL
        #define ulit64(c) c ## ULL
    #endif

#elif defined(__IBMCPP__)
    //
    // IBM XL C++
    //

    typedef signed char            Int8;
    typedef unsigned char          UInt8;
    typedef signed short           Int16;
    typedef unsigned short         UInt16;
    typedef signed int             Int32;
    typedef unsigned int           UInt32;
    typedef signed long            IntPtr;
    typedef unsigned long          UIntPtr;
    #if _MIPS_SZLONG == 64
        #define POCO_PTR_IS_64_BIT 1
        #define POCO_LONG_IS_64_BIT 1
        typedef signed long        Int64;
        typedef unsigned long      UInt64;
        #define  lit64(c) c ##  L
        #define ulit64(c) c ## UL
    #else
        typedef signed long long   Int64;
        typedef unsigned long long UInt64;
        #define  lit64(c) c ##  LL
        #define ulit64(c) c ## ULL
    #endif

#elif defined(__sgi)
    //
    // MIPSpro C++
    //

    #if _MIPS_SZLONG == 64
        #define POCO_PTR_IS_64_BIT 1
        #define POCO_LONG_IS_64_BIT 1
        typedef Int64 IntPtr;
        typedef UInt64 UIntPtr;
        #define  lit64(c) c ##  L
        #define ulit64(c) c ## UL
    #else
        typedef Int32 IntPtr;
        typedef UInt32 UIntPtr;
        #define  lit64(c) c ##  LL
        #define ulit64(c) c ## ULL
    #endif

#endif


#if defined(POCO_PTR_IS_64_BIT) && (POCO_PTR_IS_64_BIT == 1)
    #define POCO_64_BIT
#endif


} // namespace Poco


#endif // Foundation_Types_INCLUDED
