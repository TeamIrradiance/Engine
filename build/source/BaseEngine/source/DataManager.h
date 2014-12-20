/******************************************************************************/
/*!
 \file   ComponentManager.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include "IData.h"
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


namespace Framework
{
  class DataManager
  {
    ~DataManager()
    {
      for(auto it: m_dataRegistered)
      {
        delete it.second;
      }
    }

    template<typename T>
    void RegisterData(T obj)
    {
      if(m_dataRegistered[cType<T>::GetType()] != NULL) return;  //if it has existed return

      T* registerThis = new T();    // Allocate component
      registerThis->defineMeta();
      m_dataRegistered[cType<T>::GetType()] = cmp; //store it
    }

    std::map<int*,IData*> m_dataRegistered;
  };
}