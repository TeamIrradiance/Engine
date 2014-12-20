#pragma once
#include <Precompiled.h>
#include "TypeInfo.h"
#include "TypeReflectionMacros.h"
// Allows code to get a pointer to a TypeInfo through a template type lookup ID.
#define _GET_TYPE_BY_TEMPLATE( T ) TypeLookupByTemplate< T >::GetType( NULL )
#define _GET_TYPE_BY_STRING( typeNameCharPointer ) GetTypeByString( typeNameCharPointer )
 
struct Variant
{
  // Functions to initialize the data and typeInfo pointers
  void Set( void* dataPtr, TypeInfo* typeInfoPtr )
  {
    m_vData = dataPtr;
    m_csTypeInfo = typeInfoPtr;
  }
 
  template < typename T >
  void Set( T& typedData )
  {
    m_vData = &typedData;
    m_csTypeInfo = _GET_TYPE_BY_TEMPLATE( T );
  }
 
  // If any could would like to retrieve the explicit data the code
  // must provide a templated type to cast to.
  template < typename T >
  T* GetValue( )
  {
    // An assert here can force type safety
    ErrorIf( _GET_TYPE_BY_TEMPLATE( T ) != m_csTypeInfo, "Variant try to cast data to different type");
 
    return (T*)m_vData;
  }

 
  void* m_vData;
  TypeInfo* m_csTypeInfo;
};
