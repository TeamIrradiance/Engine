/******************************************************************************/
/*!
 \file   MathLib.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once

#include <Precompiled.h>
#include "IData.h"

/******************************************************************************/
/*!
 \class   Vector2
 \brief   Vector2 class, we need a vector struct that inherit from IData
          for serialization and tool automation
 */
/******************************************************************************/
class Vector2:public IData
{
public:
  Vector2(){x = y = 0;};
  Vector2(glm::vec2 vec)
  {
    x = vec.x;
    y = vec.y;
  };
  void DefineMeta();
  
  union
  {
    struct 
    {
      float x, y;
    };
  
    struct  
    {
      float r, g;
    };
  
    float v[2];
  };
};

/******************************************************************************/
/*!
 \class   Vector3
 \brief   Vector3 class, we need a vector struct that inherit from IData
          for serialization and tool automation
 */
/******************************************************************************/
class Vector3:public IData
{
public:
  Vector3(){x = y = z = 0;}
  Vector3(glm::vec3 vec)
  {
    x = vec.x;
    y = vec.y;
    z = vec.z;
  };
  void DefineMeta();

  union
  {
    struct 
    {
      float x, y, z;
    };
  
    struct  
    {
      float r, g, b;
    };
  
    float v[3];
  };
};

/******************************************************************************/
/*!
 \class   Vector4
 \brief   Vector4 class, we need a vector struct that inherit from IData
          for serialization and tool automation
 */
/******************************************************************************/
class Vector4:public IData
{
public:
  Vector4(){x = y = z = w = 0;}
  Vector4(glm::vec4 vec)
  {
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = vec.w;
  };
  void DefineMeta();

  union
  {
    struct 
    {
      float x, y, z, w;
    };
  
    struct
    {
      float r, g, b, a;
    };
  
    float v[4];
  };
};