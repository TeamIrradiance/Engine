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
#include "IData.h"
#include "TypeInfo.h"
#include "DataManager.h"
namespace Framework
{
  class GameObject;
  class Component;
  class Transform;
  class Sprite;
  class Camera;
  class ShapeCollider2D;
  class RigidBody2D;

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
    T* GetComponent()
    {
      //get static int* from cType it's the index of map
      T* returnThis = (T*)(m_csChild[cType<T>().GetType()]);

      if(returnThis) return returnThis;  //check if the component exist.
      else           return NULL;  //return NULL 
    }

    template<typename T>
    void AddComponent()
    {
      if(m_csChild[cType<T>::GetType()] != NULL) return;  //if it has existed return

      T* cmp = new T();    // Allocate component
      cmp->gameObject = this;    //assign created component's base
      m_csChild[cType<T>::GetType()] = cmp; //store it
    }

    std::map<int*,Component*> m_csChild; //name it as child to have the same structure as levels
    unsigned m_layer;

    // Pointers to Components
    Transform* transform;
    Sprite* sprite;
    Camera* camera;
    ShapeCollider2D* collider;
    RigidBody2D* rigidBody;

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
    // Constructor - Destructor
    virtual ~Component (){}

    // Methods
    virtual void DefineMeta () = 0;
    virtual void Initialize () = 0;

    friend class GameObject;

    // DATA
    GameObject* gameObject;
    std::string m_sName;
  };
}