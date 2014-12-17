/******************************************************************************/
/*!
 \file   Variant.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include "Variant.h"
#include "TypeManager.h"

/******************************************************************************/
/*!
 \fn     Variant(std::string _name)
 \par    _name
 \par    constructor
 \brief
 */
/******************************************************************************/
Variant::Variant(std::string _name)
{
  name = _name;
  m_data = new int;
}

Variant::~Variant()
{
  //if(m_data != NULL)
  //  delete m_data; 
  //m_data = NULL;
}


/******************************************************************************/
/*!
 \fn     Variant(std::string _name)
 \par    name : name of child member
 \par    type : added child member's type
 \brief
 */
/******************************************************************************/
void Variant::Addmember(std::string name ,std::string type)
{
  std::vector<char> temp;
  std::string returnThis;
  for(int i = type.size() - 1;i >= 0 ; i--)
  {
    if(type.at(i) == ' ' || type.at(i) == ':')
      break;
    temp.push_back(type.at(i));
  }
    
  for(int i = temp.size() - 1;i >= 0 ; i--)
  {
    returnThis.push_back(temp.at(i));
  }

  members[name] = new Variant(*typemanagers.types[returnThis.c_str()]);
}

Variant& Variant::operator=(const Variant* d)
{
  name = d->name;
  members = d->members;
  return *this;
}
//Variant& Variant::operator=(const Variant* d)
//{
//
//};