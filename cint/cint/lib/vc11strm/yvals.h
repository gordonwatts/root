/* yvals.h values header for Microsoft C/C++ */
#pragma once
#ifndef _YVALS
#define _YVALS
#ifndef RC_INVOKED

#include <xkeycheck.h>

#pragma pack(push,_CRT_PACKING)
#pragma push_macro("new")
#undef new

#define _CPPLIB_VER	540

#define _HAS_CPP0X     1

#define _NOEXCEPT	throw ()

/* Note on use of "deprecate":
 * Various places in this header and other headers use __declspec(deprecate) or macros that have the term DEPRECATE in them.
 * We use deprecate here ONLY to signal the compiler to emit a warning about these items. The use of deprecate
 * should NOT be taken to imply that any standard committee has deprecated these functions from the relevant standards.
 * In fact, these functions are NOT deprecated from the standard.
 *
 * Full details can be found in our documentation by searching for "Checked Iterators".
*/

#define __PURE_APPDOMAIN_GLOBAL

#ifndef __CRTDECL
#if defined(_M_CEE_PURE) || defined(MRTDLL)
#define __CRTDECL   __clrcall
#else
#define __CRTDECL   __cdecl
#endif
#endif

#ifndef __CLR_OR_THIS_CALL
#if defined(MRTDLL) || defined(_M_CEE_PURE)
#define __CLR_OR_THIS_CALL  __clrcall
#else
#define __CLR_OR_THIS_CALL
#endif
#endif

#ifndef __CLRCALL_OR_CDECL
#if defined(MRTDLL) || defined(_M_CEE_PURE)
#define __CLRCALL_OR_CDECL __clrcall
#else
#define __CLRCALL_OR_CDECL __cdecl
#endif
#endif

#ifndef __CLRCALL_PURE_OR_CDECL
#if defined(_M_CEE_PURE)
#define __CLRCALL_PURE_OR_CDECL __clrcall
#else
#define __CLRCALL_PURE_OR_CDECL __cdecl
#endif
#endif

		/* CURRENT DLL NAMES */
#ifndef _CRT_MSVCP_CURRENT
#ifdef _DEBUG
#define _CRT_MSVCP_CURRENT "MSVCP110D.dll"
#else
#define _CRT_MSVCP_CURRENT "MSVCP110.dll"
#endif
#endif

		/* NAMING PROPERTIES */
#define _WIN32_C_LIB	1

		/* THREAD AND LOCALE CONTROL */
#define _MULTI_THREAD	1	/* nontrivial locks if multithreaded */
#define _IOSTREAM_OP_LOCKS	1	/* lock iostream operations */
#define _GLOBAL_LOCALE	0	/* 0 for per-thread locales, 1 for shared */

		/* THREAD-LOCAL STORAGE */
#define _COMPILER_TLS	1	/* 1 if compiler supports TLS directly */
 #if _MULTI_THREAD
  #define _TLS_QUAL	__declspec(thread)	/* TLS qualifier, if any */

 #else /* _MULTI_THREAD */
  #define _TLS_QUAL
 #endif /* _MULTI_THREAD */

 #ifndef _HAS_EXCEPTIONS
  #define  _HAS_EXCEPTIONS  1	/* predefine as 0 to disable exceptions */
 #endif /* _HAS_EXCEPTIONS */

#define _GLOBAL_USING	1

 #ifndef _NO_LOCALES
  #define _NO_LOCALES 0
 #endif /* _NO_LOCALES */

#ifdef _ITERATOR_DEBUG_LEVEL /* A. _ITERATOR_DEBUG_LEVEL is already defined. */

	/* A1. Validate _ITERATOR_DEBUG_LEVEL. */
	#if _ITERATOR_DEBUG_LEVEL > 2 && defined(_DEBUG)
		#error _ITERATOR_DEBUG_LEVEL > 2 is not supported in debug mode.
	#elif _ITERATOR_DEBUG_LEVEL > 1 && !defined(_DEBUG)
		#error _ITERATOR_DEBUG_LEVEL > 1 is not supported in release mode.
	#endif

	/* A2. Inspect _HAS_ITERATOR_DEBUGGING. */
	#ifdef _HAS_ITERATOR_DEBUGGING /* A2i. _HAS_ITERATOR_DEBUGGING is already defined, validate it. */
		#if _ITERATOR_DEBUG_LEVEL == 2 && _HAS_ITERATOR_DEBUGGING != 1
			#error _ITERATOR_DEBUG_LEVEL == 2 must imply _HAS_ITERATOR_DEBUGGING == 1 .
		#elif _ITERATOR_DEBUG_LEVEL < 2 && _HAS_ITERATOR_DEBUGGING != 0
			#error _ITERATOR_DEBUG_LEVEL < 2 must imply _HAS_ITERATOR_DEBUGGING == 0 .
		#endif
	#else /* A2ii. _HAS_ITERATOR_DEBUGGING is not yet defined, derive it. */
		#if _ITERATOR_DEBUG_LEVEL == 2
			#define _HAS_ITERATOR_DEBUGGING 1
		#else
			#define _HAS_ITERATOR_DEBUGGING 0
		#endif
	#endif /* _HAS_ITERATOR_DEBUGGING */

	/* A3. Inspect _SECURE_SCL. */
	#ifdef _SECURE_SCL /* A3i. _SECURE_SCL is already defined, validate it. */
		#if _ITERATOR_DEBUG_LEVEL > 0 && _SECURE_SCL != 1
			#error _ITERATOR_DEBUG_LEVEL > 0 must imply _SECURE_SCL == 1 .
		#elif _ITERATOR_DEBUG_LEVEL == 0 && _SECURE_SCL != 0
			#error _ITERATOR_DEBUG_LEVEL == 0 must imply _SECURE_SCL == 0 .
		#endif
	#else /* A3ii. _SECURE_SCL is not yet defined, derive it. */
		#if _ITERATOR_DEBUG_LEVEL > 0
			#define _SECURE_SCL 1
		#else
			#define _SECURE_SCL 0
		#endif
	#endif /* _SECURE_SCL */

#else /* B. _ITERATOR_DEBUG_LEVEL is not yet defined. */

	/* B1. Inspect _HAS_ITERATOR_DEBUGGING. */
	#ifdef _HAS_ITERATOR_DEBUGGING /* B1i. _HAS_ITERATOR_DEBUGGING is already defined, validate it. */
		#if _HAS_ITERATOR_DEBUGGING > 1
			#error _HAS_ITERATOR_DEBUGGING must be either 0 or 1 .
		#elif _HAS_ITERATOR_DEBUGGING == 1 && !defined(_DEBUG)
			#error _HAS_ITERATOR_DEBUGGING == 1 is not supported in release mode.
		#endif
	#else /* B1ii. _HAS_ITERATOR_DEBUGGING is not yet defined, default it. */
		#ifdef _DEBUG
			#define _HAS_ITERATOR_DEBUGGING 1
		#else
			#define _HAS_ITERATOR_DEBUGGING 0
		#endif
	#endif /* _HAS_ITERATOR_DEBUGGING */

	/* B2. Inspect _SECURE_SCL. */
	#ifdef _SECURE_SCL /* B2i. _SECURE_SCL is already defined, validate it. */
		#if _SECURE_SCL > 1
			#error _SECURE_SCL must be either 0 or 1 .
		#endif
	#else /* B2ii. _SECURE_SCL is not yet defined, default it. */
		#if _HAS_ITERATOR_DEBUGGING == 1
			#define _SECURE_SCL 1
		#else
			#define _SECURE_SCL 0
		#endif
	#endif /* _SECURE_SCL */

	/* B3. Derive _ITERATOR_DEBUG_LEVEL. */
	#if _HAS_ITERATOR_DEBUGGING
		#define _ITERATOR_DEBUG_LEVEL 2
	#elif _SECURE_SCL
		#define _ITERATOR_DEBUG_LEVEL 1
	#else
		#define _ITERATOR_DEBUG_LEVEL 0
	#endif

#endif /* _ITERATOR_DEBUG_LEVEL */

#define _STRINGIZEX(x) #x
#define _STRINGIZE(x) _STRINGIZEX(x)

#ifndef __EDG__ /* TRANSITION */
#ifdef __cplusplus
	#ifndef _ALLOW_MSC_VER_MISMATCH
		#pragma detect_mismatch("_MSC_VER", _STRINGIZE(_MSC_VER))
	#endif /* _ALLOW_MSC_VER_MISMATCH */

	#ifndef _ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH
		#pragma detect_mismatch("_ITERATOR_DEBUG_LEVEL", _STRINGIZE(_ITERATOR_DEBUG_LEVEL))
	#endif /* _ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH */

	#ifndef _ALLOW_RUNTIME_LIBRARY_MISMATCH
		#if !defined(_DLL) && !defined(_DEBUG)
			#pragma detect_mismatch("RuntimeLibrary", "MT_StaticRelease")
		#elif !defined(_DLL) && defined(_DEBUG)
			#pragma detect_mismatch("RuntimeLibrary", "MTd_StaticDebug")
		#elif defined(_DLL) && !defined(_DEBUG)
			#pragma detect_mismatch("RuntimeLibrary", "MD_DynamicRelease")
		#elif defined(_DLL) && defined(_DEBUG)
			#pragma detect_mismatch("RuntimeLibrary", "MDd_DynamicDebug")
		#endif /* defined(_DLL) etc. */
	#endif /* _ALLOW_RUNTIME_LIBRARY_MISMATCH */
#endif /* __cplusplus */
#endif /* __EDG__ */

#ifndef _ITERATOR_DEBUG_ARRAY_OVERLOADS
	#define _ITERATOR_DEBUG_ARRAY_OVERLOADS 1
#endif /* _ITERATOR_DEBUG_ARRAY_OVERLOADS */

/* See note on use of deprecate at the top of this file */
#if !defined(_SCL_SECURE_NO_WARNINGS) && defined(_SCL_SECURE_NO_DEPRECATE)
#define _SCL_SECURE_NO_WARNINGS
#endif

#if !defined (_SECURE_SCL_DEPRECATE)
#if defined(_SCL_SECURE_NO_WARNINGS)
#define _SECURE_SCL_DEPRECATE 0
#else
#define _SECURE_SCL_DEPRECATE 1
#endif
#endif

#if defined(_SECURE_SCL_THROWS) && _SECURE_SCL_THROWS
#error _SECURE_SCL_THROWS has been removed.
#endif

		/* NAMESPACE */


namespace std {
typedef bool _Bool;
}

		/* VC++ COMPILER PARAMETERS */
#define _LLONG_MAX	0x7fffffffffffffff
#define _ULLONG_MAX	0xffffffffffffffff

		/* INTEGER PROPERTIES */
#define _C2			1	/* 0 if not 2's complement */

#define _MAX_EXP_DIG	8	/* for parsing numerics */
#define _MAX_INT_DIG	32
#define _MAX_SIG_DIG	36

typedef __int64 _Longlong;
typedef unsigned __int64 _ULonglong;

		/* STDIO PROPERTIES */
#define _Filet _iobuf

#define _IOBASE	_base
#define _IOPTR	_ptr
#define _IOCNT	_cnt

#ifndef _HAS_CHAR16_T_LANGUAGE_SUPPORT
 #define _HAS_CHAR16_T_LANGUAGE_SUPPORT 0
#endif /* _HAS_CHAR16_T_LANGUAGE_SUPPORT */

		/* uchar PROPERTIES */
 #if _HAS_CHAR16_T_LANGUAGE_SUPPORT
 #else /* _HAS_CHAR16_T_LANGUAGE_SUPPORT */
 #if !defined(_CHAR16T)
  #define _CHAR16T
typedef unsigned short char16_t;
typedef unsigned int char32_t;
 #endif /* !defined(_CHAR16T) */
 #endif /* _HAS_CHAR16_T_LANGUAGE_SUPPORT */

		/* MULTITHREAD PROPERTIES */
		/* LOCK MACROS */
#define _LOCK_LOCALE	0
#define _LOCK_MALLOC	1
#define _LOCK_STREAM	2
#define _LOCK_DEBUG		3
#define _MAX_LOCK		4	/* one more than highest lock number */

namespace std {
	enum _Uninitialized
	{
		_Noinit
	};
}

		// CLASS _Lockit
#endif /* RC_INVOKED */
#endif /* _YVALS */

/*
 * Copyright (c) 1992-2012 by P.J. Plauger.  ALL RIGHTS RESERVED.
 * Consult your license regarding permissions and restrictions.
 V6.00:0009 */
