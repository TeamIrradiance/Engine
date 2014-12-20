/******************************************************************************/
/*!
 \file   TypeInfo.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include <Precompiled.h>
#define MAX_TYPE_INFOS 128
/******************************************************************************/
/*!
 \class   TypeInfo
 \brief   a class to specify types, purpose: to get the data member by calling
          typeData.data
 */
/******************************************************************************/
struct TypeInfo
{
  const char* name;
  int size;
  int childSize;
  int id;
  std::vector<const char*> child_name;
  std::vector<TypeInfo*> child_info;
  std::vector<int> child_offsets;
};

/******************************************************************************/
/*!
 \struct  TypeLookupByTemplate
 \brief   a class to specify types, purpose: to get the data member by calling
          typeData.data
 */
/******************************************************************************/
template < typename T >
struct TypeLookupByTemplate
{
  static TypeInfo* GetType( TypeInfo* typeInfo )
  {
    static TypeInfo* s_typeInfo = NULL;
 
    if ( !s_typeInfo )
    {
      s_typeInfo = typeInfo;
    }

    ErrorIf(s_typeInfo == NULL, "%s hasn't been defined as meta type",typeid(T).name());
    return s_typeInfo;
  }

};

//global pointer to types
extern TypeInfo typeInfos[ MAX_TYPE_INFOS ];
extern int typeInfosCount;

//Functions front declaration
TypeInfo* GetTypeByString( const char* typeNameCharPointer );
std::string Tokenize(const char* name);
