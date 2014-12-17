/******************************************************************************/
/*!
 \file   Serialization.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include "Precompiled.h"
#include "json.h"
#include "ITypeReflection.h"
/******************************************************************************/
/*!
 \class   SerializeManager
 \brief   generalize serialization

 */
/******************************************************************************/
class SerializeManager
{

};

//#define DEFINE_SERIALIZEFN(type)\

template<typename T>
void serializefn(const T Data)
{
  

}
//template<typename T>
//typedef void(*SerializeFn)(T Data);
//
//std::map<std::string,SerializeFn>
//void checkSerializeType(std::string type)
//{
//  serialize<
//}
template<typename T>
void prepareSerialize(T object)
{
  Variant container;
  container.CreateVariant(object);
}