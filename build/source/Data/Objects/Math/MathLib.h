/******************************************************************************/
/*!
\file   MathLib.h
\author Aji Suprana
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#include "IData.h"

#pragma once


/******************************************************************************/
/*!
\class   Vector2
\brief   Vector2 class, we need a vector struct that inherit from IData
for serialization and tool automation
*/
/******************************************************************************/
class Vector2 : public IData
{
public:
  void ToolInit ();
  void Serialize ();
  void DefineMeta (){}
  Vector2 ()
  {
    x = y = 0;
  }
  Vector2 (float _x, float _y) : x (_x), y (_y)
  {}
  Vector2 (double _x, double _y) : x ((float) _x), y ((float) _y)
  {}
  Vector2 (const glm::vec2& vec)
  {
    x = vec.x;
    y = vec.y;
  }
  operator glm::vec2 ()
  {
    return glm::vec2 (x, y);
  }

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

    float v [2];
  };

};

/******************************************************************************/
/*!
\class   Vector3
\brief   Vector3 class, we need a vector struct that inherit from IData
for serialization and tool automation
*/
/******************************************************************************/
struct Vector3 : public IData
{
  void ToolInit ();
  void Serialize ();
  void DefineMeta (){}
  Vector3 ()
  {
    x = y = z = 0;
  }
  Vector3 (glm::vec3& vec)
  {
    x = vec.x;
    y = vec.y;
    z = vec.z;
  }
  Vector3 (float _x, float _y, float _z) : x (_x), y (_y), z (_z)
  {}
  Vector3 (double _x, double _y, double _z) : x ((float) _x), y ((float) _y), z ((float) _z)
  {}
  operator glm::vec3 ()
  {
    return glm::vec3 (x, y, z);
  }

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

    float v [3];
  };
};

/******************************************************************************/
/*!
\class   Vector4
\brief   Vector4 class, we need a vector struct that inherit from IData
for serialization and tool automation
*/
/******************************************************************************/
class Vector4 : public IData
{
public:
  void ToolInit ();
  void Serialize ();
  void DefineMeta (){}
  Vector4 ()
  {
    x = y = z = w = 0;
  }
  Vector4 (const glm::vec4& vec)
  {
    x = vec.x;
    y = vec.y;
    z = vec.z;
    w = vec.w;
  }
  Vector4 (float _x, float _y, float _z, float _w) : x (_x), y (_y), z (_z), w (_w)
  {}
  Vector4 (double _x, double _y, double _z, double _w) : x ((float)_x), y ((float)_y), z ((float)_z), w ((float)_w)
  {}
  operator glm::vec4 ()
  {
    return glm::vec4 (x, y, z, w);
  }

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

    float v [4];
  };

};