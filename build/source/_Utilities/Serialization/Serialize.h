/******************************************************************************/
/*!
 \file   Serialize.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief  Creating a generic serialization system that can serialize any kind of data
 */
/******************************************************************************/
#ifndef SERIALIZE_HEADER
#define SERIALIZE_HEADER
#include "Json.h"


/******************************************************************************/
/*!
 \fn   void SerializeData(T* obj,Json::Value *root,const char* name = 0)
 \brief  Serialize data like sprite, int,float, transform
 */
/******************************************************************************/
template<typename T> void SerializeData(T* obj,Json::Value *root,const char* name);

/******************************************************************************/
/*!
 \fn     void SerializeObject(T* obj,Json::Value *root,const char* name = 0)
 \brief  It's only for gameObject or level for now
 */
/******************************************************************************/
template<typename T> void Serialize(T* obj,Json::Value *root,const char* targetFile);

#include "Serialize.cpp"
/******************************************************************************/
/*!
 \file   Serialize.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief  Creating a generic serialization system that can serialize any kind of data
 */
/******************************************************************************/
#include "Precompiled.h"
#ifndef SERIALIZE_CPP
#define SERIALZE_CPP

#include "IComponents.h"
#include "ITypeReflection.h"

#define CHECK_TYPE(type)\
  if( GET_TYPE_BY_STRING(#type)->id == id )\
  {\
    SerializeData((type*)curData,curRoot, curChildName);\
  }\
  ++typeCounted

#define WRITE_BASIC_DATA(T)\
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
void SerializeData(T* obj,Json::Value *root,const char* name = 0)
{
  using namespace Component;
  using namespace std;

  //Create Variant to hold current obj
  Variant var;
  var.Set(*obj);

  //set current typeid
  int id = var.m_csTypeInfo->id;

  //if this is the highest parents of the data set name as stringizes type-> float as "float"
  //it only becames not null when it is called from inside SerializeData function
  if(name == NULL)
    name = var.m_csTypeInfo->name;

  //Setting up current root
  Json::Value* curRoot = &(*root)[name] ;

  //if it's not a struct or a class
  if(var.m_csTypeInfo->childSize <=0)
  {
    //check only default types
    WRITE_BASIC_DATA(int);
    WRITE_BASIC_DATA(float);
    WRITE_BASIC_DATA(double);
    WRITE_BASIC_DATA(string);
    return;
  }//endif
  else
  {

    for(int i = 0; i < var.m_csTypeInfo->childSize;++i)
    {
      char* dummy = (char *)var.GetValue< T >( );
      const char* curChildName = var.m_csTypeInfo->child_name[i];
      void* curData = (dummy + var.m_csTypeInfo->child_offsets[i]);
      int curTypeID =  var.m_csTypeInfo->child_info[i]->id;
      
      //we can just put non-default type here, but I put it anyway, for debuging purposes
      CheckAllType<int>(curData,curRoot,curTypeID,curChildName);
      if(i == i)
        i = i;
    }//for loop
  }//end else

}//end function

/******************************************************************************/
/*!
 \fn     void SerializeObject(T* obj,Json::Value *root,const char* name = 0)
 \brief  serialize any kind of data
 */
/******************************************************************************/
template<typename T>
void Serialize(T* obj,const char* targetFile)
{
  Json::Value Root;
  

  Json::StyledWriter writer;
  std::ofstream write(targetFile);

  //ifIsGameObject
  {
    ;
  for(auto it : obj->m_csChild)
  {
    Json::Value* curRoot = &(Root)["GameObject"]; 
    int id = GET_TYPE_BY_STRING(it.second->m_sName.c_str())->id;
    CheckAllType<int>(it.second,curRoot,id,it.second->m_sName.c_str());
  }
  }
  //@@@@TODO SERIALIZE LEVEL
  //ifIsLevel
  //root
  {
  }

  std::string outputConfig = writer.write( Root );
  write << outputConfig;
}



/******************************************************************************/
/*!
 \fn     CheckAllType(void* curData,Json::Value& curRoot,int id,const char* curChildName,int& typeCounted)
 \brief  check which type to cast, we have to put every defined meta here
 */
/******************************************************************************/
template<typename T>
void CheckAllType(void* curData,Json::Value* curRoot,int id,const char* curChildName)
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

#endif

#endif