/******************************************************************************/
/*!
 \file   ITypeReflection.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include <Precompiled.h>
#include "Variant.h"
#include "TypeManager.h"
#include "TypeData.h"

/******************************************************************************/
/*!
 \macros DEFINE_TYPE
 \par    name
          - the type name, like: int, float, double .etc
 \brief
 */
/******************************************************************************/
#define DEFINE_TYPE(name)\
  Variant type_##name (#name);\
  typeData<name> info_##name = typeData<name>();\
  typemanagers.AddType(&type_##name);\


/******************************************************************************/
/*!
 \macros GET_TYPE
 \par    name std::string
          - the type name, like: int, float, double .etc
 \brief  return type variant
 */
/******************************************************************************/
#define GET_VARIANT(name)\
  typemanagers.types[name]

/******************************************************************************/
/*!
 \macros GET_TYPE_DATA
 \par    name std::string
          - the type name, like: int, float, double .etc
 \brief  return type data, it's a struct. example of use GET_TYPE_DATA(int).data
 */
/******************************************************************************/
#define GET_DATA(name)\
  typemanagers.types[name]
//@TODO: get the data of a type

/******************************************************************************/
/*!
 \macros ADDMEMBERS
 \par    Variant addTo
          - name of metatype existing defined to add to
 \par    var
          - addTo's member variable
 */
/******************************************************************************/
#define ADDMEMBERS(addTo,var)\
{\
  std::string type;\
  type = typeid( info_##addTo .data. ##var ).name();\
  /*ErrorIf( typemanagers.types.find(type) == typemanagers.types.end())*/ \
  typemanagers.types[#addTo] ->Addmember( #var ,type.c_str());\
}

