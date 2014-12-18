/******************************************************************************/
/*!
 \file   Transform.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include "Components.h"

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
    void ToolInit();
    void Serialize();
    Transform();
    ~Transform();

    //DATA
    Vector3 translation;
    Vector2 scale;
    float rotation;
  };
}