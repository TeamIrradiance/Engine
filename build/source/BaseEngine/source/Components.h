/******************************************************************************/
/*!
 \file   Comopnents.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include <Precompiled.h>
#include "IData.h"
#include "TypeInfo.h"
#include "DataManager.h"
namespace BaseEngine
{
  class GameObject;
  class Component;

/******************************************************************************/
/*!
 \class   GameObject
 \brief  
 */
/******************************************************************************/
  class GameObject
  {
  public:
    GameObject(){};     
    ~GameObject(){};   //@DO NOTHING, DELETE EVERYTHING IN DATA MANAGER
    
    template<typename T>
    T* Get()
    {
      //get static int* from cType it's the index of map
      T* returnThis = (T*)(m_csChild[cType<T>().GetType()]);

      if(returnThis) return returnThis;  //check if the component exist.
      else           return NULL;  //return NULL 
    }

    template<typename T>
    void Add()
    {
      if(m_csChild[cType<T>::GetType()] != NULL) return;  //if it has existed return

      T* cmp = new T();    // Allocate component
      cmp->m_csBase = this;    //assign created component's base
      m_csChild[cType<T>::GetType()] = cmp; //store it
    }

    std::map<int*,Component*> m_csChild; //name it as child to have the same structure as levels
  };

/******************************************************************************/
/*!
 \class   Component
 \brief  
 */
/******************************************************************************/
  //@@TODO:DELETE IDATA
  class Component : public ::IData
  {
  public:
    virtual void DefineMeta() = 0;
    friend class GameObject;
    GameObject* m_csBase;
    std::string m_sName;
  };
}