#pragma once
//#include "Precompiled.h"
#include "Variant.h"
#include "TypeInfo.h"

/******************************************************************************/
/*!
\macros  begining define a type
\brief   define a meta type 
         -store typeInfo to an array
         -link TypeLookupbyTemplate's T with type info
         -specify type name -> example: float as "float"
         -create a dummy T object for adding meta child in the next macros
         
*/
/******************************************************************************/
#define _meta_begin( T ) \
  do { \
  ( typeInfosCount < MAX_TYPE_INFOS ); \
    TypeInfo* typeInfo = typeInfos + typeInfosCount++; \
    typeInfo->id = typeInfosCount - 1;\
    typeInfo->size = sizeof( T ); \
    typeInfo->name = #T; \
    TypeLookupByTemplate< T >::GetType( typeInfo ); \
    T dummyT = T();

/******************************************************************************/
/*!
\macros  adding a child of begined object T
\brief   adding typeInfo's child_info,child_offset and child_name in a vector
\param   child_info-> type info of a child
\param   child_name-> variable name of a child example: vector.x named "x"
\param   child_offset-> offset of a child in object T, 
          -example Vec3{float x,y,z}, offset of x is 0 offset of y is 4     
*/
/******************************************************************************/
#define _meta_child(addTo,varName)\
  typeInfo->child_info.push_back(GetTypeByString(Tokenize(typeid(dummyT. ##varName).name()).c_str()));\
  typeInfo->child_offsets.push_back(offsetof(addTo, varName));\
  typeInfo->child_name.push_back(#varName);\
  typeInfo->childSize++;

#define _meta_end()\
  } while ( 0 );


