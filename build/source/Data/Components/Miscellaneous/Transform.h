/******************************************************************************/
/*!
 \file   Transform.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include <Precompiled.h>
#include "Components.h"
#include "MathLib.h"

namespace Component
{
/******************************************************************************/
/*!
 \class   Transform
 \brief   Transform Component
 Notes: 
 */
/******************************************************************************/
//@@ Only this 4 function is allowed in component class
  class Transform: public BaseEngine::Component
  {
  public:
    Transform();
    ~Transform();
    void DefineMeta();

    //DATA
    Vector3 translation;
    Vector3 scale;
    float rotation;
  };
}