/******************************************************************************/
/*!
 \file   IDebugAssertion.h
 \author 
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once

//Define the debug break using the MS specific or general using assembly interrupt 3
#ifdef _MSC_VER
#define G_DEBUG_BREAK __debugbreak()
#else
#define G_DEBUG_BREAK do { __asm int 3 } while(0)
#endif

//By defining G_ENABLE_DEBUG_DIAGNOSTICS you can explicitly 
//enable or disable debugging and diagnostic macros
#if !defined(G_ENABLE_DEBUG_DIAGNOSTICS) 
#   if defined(_DEBUG)
#       define G_ENABLE_DEBUG_DIAGNOSTICS 1
#   else
#       define G_ENABLE_DEBUG_DIAGNOSTICS 0
#   endif
#endif

//Implement these functions to control how errors and
//debug printing are handled
bool SignalErrorHandler(const char * expression, const char * file,int line, const char * formatMessage = 0, ...);

#if G_ENABLE_DEBUG_DIAGNOSTICS

#define ErrorIf(exp, ...) \
	do { if( (exp) && SignalErrorHandler(#exp, __FILE__, __LINE__,__VA_ARGS__ )) \
	G_DEBUG_BREAK; } while(0)

#define ErrorIfNot(exp, ...) \
	do { if( (!(exp)) && SignalErrorHandler(#exp, __FILE__, __LINE__,__VA_ARGS__ )) \
	G_DEBUG_BREAK; } while(0)

#else

//If the diagnostics are disabled all the debug functions
//are no ops
#define ErrorIf(...) ((void)0)
#define GAssert(...) ((void)0)

#endif

