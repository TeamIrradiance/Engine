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

namespace BaseEngine
{
  class GameObject;
  class Component;

/******************************************************************************/
/*!
 \class   cType
 \brief  for component map indexing purposes
 */
/******************************************************************************/
  template<typename T>
  struct cType // start with c to be able to differentiate with "type" c means class
  {
    static int* GetType(void) //get a unique type identifier in the form of a void* for any class T
    {
      static int typeId;
      return &typeId;
    }

    T* type;
  };

/******************************************************************************/
/*!
 \class   GameObject
 \brief  
 */
/******************************************************************************/
  class GameObject
  {
    GameObject(){};     
    ~GameObject(){};   //@DO NOTHING, DELETE EVERYTHING IN DATA MANAGER
    
    template<typename T>
    T* Get()
    {
      //get static int* from cType it's the index of map
      T* returnThis = (T*)(components[cType<T>().GetType()]);
      if(returnThis) return returnThis;  //check if the component exist.
      else           return NULL;  //return NULL 
    }

    template<typename T>
    void Add()
    {
      if(components[cType<T>::GetType()] != NULL) return;  //if it has existed return

      T* cmp = new T();    // Allocate component
      cmp->base = this;    //assign created component's base
      components[cType<T>::GetType()] = cmp; //store it
    }

  private:
    std::map<int*,Component*> components;
  };

/******************************************************************************/
/*!
 \class   Component
 \brief  
 */
/******************************************************************************/
  class Component : public ::IData
  {
  public:
    friend class GameObject;
    virtual void ToolInit() = 0;
    virtual void Serialize() = 0;

  private:
    GameObject* base;
  };
}