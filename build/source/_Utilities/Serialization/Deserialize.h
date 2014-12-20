/******************************************************************************/
/*!
 \file   Deserialize.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief  Creating a generic deserialization system that can serialize any kind of data
 */
/******************************************************************************/
#ifndef DESERIALIZE_HEADER
#define DESERIALIZE_HEADER
#include "Json.h"


/******************************************************************************/
/*!
 \fn   void SerializeData(T* obj,Json::Value *root,const char* name = 0)
 \brief  Serialize data like sprite, int,float, transform
 */
/******************************************************************************/
template<typename T> void DeserializeData(T* obj,Json::Value *root,const char* name);

/******************************************************************************/
/*!
 \fn     void SerializeObject(T* obj,Json::Value *root,const char* name = 0)
 \brief  It's only for gameObject or level for now
 */
/******************************************************************************/
template<typename T> void Deserialize(T* obj,Json::Value *root,const char* targetFile);

#include "Deserialize.cpp"

/******************************************************************************/
/*!
 \file   Deserialize.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief  Creating a generic Deserialize system that can serialize any kind of data
 */
/******************************************************************************/
#include "Precompiled.h"
#ifndef SERIALIZE_CPP
#define SERIALZE_CPP

#include "IComponents.h"
#include "ITypeReflection.h"

#define DCHECK_TYPE(type)\
  if(it.m_sName == "Vector3")\
  {\
    Vector3* castedObj = (Vector3*)it;\
    DeserializeData(castedObj,&root,obj->m_sName);\
  }\

#define DWRITE_BASIC_DATA(T)\
  if(  GET_TYPE_BY_STRING(#T)->id == id )\
  {\
    T data = *(T*)obj;\
    *curRoot = data;\
    return;\
  }\

/******************************************************************************/
/*!
 \fn   void SerializeData(T* obj,Json::Value *root,const char* name = 0)
 \brief  Serialize data like sprite, int,float, transform
 */
/******************************************************************************/
template<typename T>
void DeserializeData(T* obj,Json::Value *root,const char* name = 0)
{
  using namespace Component;
  using namespace std;

  //Create Variant to hold current obj
  Variant var;
  var.Set(*obj);


}//end function

/******************************************************************************/
/*!
 \fn     void SerializeObject(T* obj,Json::Value *root,const char* name = 0)
 \brief  serialize any kind of data
 */
/******************************************************************************/
template<typename T>
void Deserialize(T* obj,const char* targetFile)
{
  std::ifstream in(targetFile);
  ErrorIf(!in.is_open(),"%s is not found");
  std::stringstream sstr;
  sstr << in.rdbuf();

  Json::Value root;   // will contains the root value after parsing.

  Json::Reader reader;

  bool parsingSuccessful = reader.parse( sstr.str(), root );
  ErrorIf ( !parsingSuccessful, "json parsing failed, check opened json file's formating"  );

  std::cout <<sstr.str();

  for(auto it: obj->m_csChild)
  {
    int typeCounted = 0;
    using namespace Component;
    using namespace std;
    CHECK_TYPE(int);
    CHECK_TYPE(float);
    CHECK_TYPE(double);
    CHECK_TYPE(string);
    CHECK_TYPE(Vector2);
    CHECK_TYPE(Vector3);
    CHECK_TYPE(Vector4);
    CHECK_TYPE(Transform);
    CHECK_TYPE(Sprite);
    ErrorIf(typeCounted < typeInfosCount, "A defined type is not handled in serialization system!");
    ErrorIf(typeCounted > typeInfosCount, "A handled type is not defined or multiple definition exist!");
  }
}


#endif
#endif