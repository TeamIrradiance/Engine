/******************************************************************************/
/*!
 \file   variant.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include <Precompiled.h>

/******************************************************************************/
/*!
 \class   Variant
 \brief   defining a type and its type
 */
/******************************************************************************/
class Variant
{
public:
  Variant(){};
  Variant(std::string _name);
  ~Variant();
  void Addmember(std::string name , std::string type);

  template<typename T>
  void CreateVariant(T Object);
  Variant& operator=(const Variant *d);

  std::map<std::string, Variant*> members;
  std::string name;
  void* m_data;
};

template<typename T>
void Variant::CreateVariant(T data)
{
  Variant createThis;
  std::string type = typeid(data).name();
  std::vector<char> temp;

  for(int i = type.size() - 1;i >= 0 ; i--)
  {
    if(type.at(i) == ' ' || type.at(i) == ':')
      break;
    temp.push_back(type.at(i));
  }
   type.clear(); 
  for(int i = temp.size() - 1;i >= 0 ; i--)
  {
    type.push_back(temp.at(i));
  }
  createThis = typemanagers.types[type];
  createThis.m_data = new T;
  createThis.m_data = (void*)&data;
  *this = createThis;
}
