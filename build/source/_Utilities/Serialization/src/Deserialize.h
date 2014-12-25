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
//#include <Precompiled.h>
#include "Json.h"
#include "Components.h"
#include "IComponents.h"

/******************************************************************************/
/*!
 \fn   void SerializeData(T* obj,Json::Value *root,const char* name = 0)
 \brief  Serialize data like sprite, int,float, transform
 */
/******************************************************************************/
template<typename T> void DeserializeData(T* obj,Json::Value *root);

/******************************************************************************/
/*!
 \fn     void SerializeObject(T* obj,Json::Value *root,const char* name = 0)
 \brief  It's only for gameObject or level for now
 */
/******************************************************************************/
template<typename T> void Deserialize(T* obj,const char* targetFile);

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

#ifndef SERIALIZE_CPP
#define SERIALZE_CPP

#include "IComponents.h"
#include "ITypeReflection.h"

#define DCHECK_TYPE(type)\
  if(var.m_csTypeInfo->name == #type)\
  {\
    type* castedObj = (type*)curData;\
    castedObj = \
  }

#define CHECK_COMPONENT(type)\
  if(curType == std::string(#type))\
  {\
    obj->AddComponent<type>();\
    DeserializeData(obj->GetComponent<type>(),&curRoot[curType.c_str()]);\
  }

#define READ_BASIC_DATA(T)\
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
void DeserializeData(T* obj,Json::Value *root)
{
  Variant var;
  var.Set(*obj);

  using namespace Framework;
  for(Json::ValueIterator itr = root->begin() ; itr != root->end() ; itr++ )
  {
    Json::Value curRoot = *itr;
    char* dummy = (char *)var.GetValue< T >( );
    int curTypeID = 0;

    std::string curType = itr.memberName();
    for(int i = 0; i < var.m_csTypeInfo->childSize; ++i)
    {
      if(std::string(var.m_csTypeInfo->child_name[i]) == curType)
      {
        curTypeID = i;
        break;
      }
    }

    void* curData = (dummy + var.m_csTypeInfo->child_offsets [curTypeID]);;
    
    // if this is a struct
    if( var.m_csTypeInfo->child_info[curTypeID]->childSize > 0)
    {
      std::cout <<"is a struct" << std::endl;
      if(var.m_csTypeInfo->child_info[curTypeID]->name == "Vector2")
      {
        Vector2* castedObj = (Vector2*)curData;
        DeserializeData(castedObj,&(*itr));
      }
      if(var.m_csTypeInfo->child_info[curTypeID]->name == "Vector3")
      {
        Vector3* castedObj = (Vector3*)curData;
        DeserializeData(castedObj,&(*itr));
      }
      if (var.m_csTypeInfo->child_info [curTypeID]->name == "Texcoord")
      {
        Texcoord* castedObj = (Texcoord*) curData;
        DeserializeData (castedObj, &(*itr));
      }
      if (var.m_csTypeInfo->child_info [curTypeID]->name == "std::string")
      {
        std::string* castedObj = (std::string*) curData;
        DeserializeData (castedObj, &(*itr));
      }
    }
    else
    {
      using std::string;
      std::cout << var.m_csTypeInfo->child_info [curTypeID]->name << "\n";
      std::cout <<"not a struct" << std::endl;
      if(var.m_csTypeInfo->child_info[curTypeID]->name == "int")
      {
        int* castedObj = (int*)curData;
        *castedObj = curRoot.asInt();
      }
      if(var.m_csTypeInfo->child_info[curTypeID]->name == "float")
      {
        float* castedObj = (float*)curData;
        *castedObj = (float)curRoot.asDouble();
      }
      if(var.m_csTypeInfo->child_info[curTypeID]->name == "double")
      {
        double* castedObj = (double*)curData;
        *castedObj = curRoot.asDouble();
      }
      if (var.m_csTypeInfo->child_info [curTypeID]->name == "string")
      {
        string* castedObj = (string*) curData;
        *castedObj = curRoot.asString ();
      }
    }
  }

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
  using namespace Framework;
  using namespace Framework;
  using namespace std;
  std::ifstream in(targetFile);
  ErrorIf(!in.is_open(),"%s is not found");
  std::stringstream sstr;
  sstr << in.rdbuf();

  Json::Value& root = Json::Value();   // will contains the root value after parsing.
  Json::Reader reader;
  bool parsingSuccessful = reader.parse( sstr.str(), root );
  ErrorIf ( !parsingSuccessful, "json parsing failed, check opened json file's formating"  );
  Json::Value& curRoot = root["GameObject"];

  std::cout << root;
  //Constructing object
  for(Json::ValueIterator itr = curRoot.begin() ; itr != curRoot.end() ; itr++ )
  {
    std::string curType = std::string(itr.memberName());
    //if It's a game Object or a level
    
    CHECK_COMPONENT(Sprite);
    CHECK_COMPONENT(Transform);

  }
}


#endif
#endif