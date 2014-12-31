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
  Vector2 (float s) : x (s), y (s)
  {}
  Vector2 (float _x, float _y) : x (_x), y (_y)
  {}
  Vector2 (const glm::vec2& vec) : x (vec.x), y (vec.y)
  {}
  operator glm::vec2 ()
  {
    return glm::vec2 (x, y);
  }
  void Set (float x_, float y_)
  {
    x = x_;
    y = y_;
  }

  Vector2 operator-(void) const
  {
    return Vector2 (-x, -y);
  }

  Vector2 operator*(float s) const
  {
    return Vector2 (x * s, y * s);
  }

  Vector2 operator/(float s) const
  {
    return Vector2 (x / s, y / s);
  }

  void operator*=(float s)
  {
    x *= s;
    y *= s;
  }

  Vector2 operator+(const Vector2& rhs) const
  {
    return Vector2 (x + rhs.x, y + rhs.y);
  }

  Vector2 operator+(float s) const
  {
    return Vector2 (x + s, y + s);
  }

  void operator+=(const Vector2& rhs)
  {
    x += rhs.x;
    y += rhs.y;
  }

  Vector2 operator-(const Vector2& rhs) const
  {
    return Vector2 (x - rhs.x, y - rhs.y);
  }

  void operator-=(const Vector2& rhs)
  {
    x -= rhs.x;
    y -= rhs.y;
  }

  float LenSqr (void) const
  {
    return x * x + y * y;
  }

  float Len (void) const
  {
    return std::sqrt (x * x + y * y);
  }

  void Rotate (float radians)
  {
    float c = std::cos (radians);
    float s = std::sin (radians);

    float xp = x * c - y * s;
    float yp = x * s + y * c;

    x = xp;
    y = yp;
  }

  void Normalize (void)
  {
    float len = Len ();

    if (len > EPSILON)
    {
      float invLen = 1.0f / len;
      x *= invLen;
      y *= invLen;
    }
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

inline Vector2 operator*(float s, const Vector2& v)
{
  return Vector2 (s * v.x, s * v.y);
}

inline Vector2 Min (const Vector2& a, const Vector2& b)
{
  return Vector2 (std::min (a.x, b.x), std::min (a.y, b.y));
}

inline Vector2 Max (const Vector2& a, const Vector2& b)
{
  return Vector2 (std::max (a.x, b.x), std::max (a.y, b.y));
}

inline float Dot (const Vector2& a, const Vector2& b)
{
  return a.x * b.x + a.y * b.y;
}

inline float DistSqr (const Vector2& a, const Vector2& b)
{
  Vector2 c = a - b;
  return Dot (c, c);
}

inline Vector2 Cross (const Vector2& v, float a)
{
  return Vector2 (a * v.y, -a * v.x);
}

inline Vector2 Cross (float a, const Vector2& v)
{
  return Vector2 (-a * v.y, a * v.x);
}

inline float Cross (const Vector2& a, const Vector2& b)
{
  return a.x * b.y - a.y * b.x;
}

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
  Vector3 (float s) : x (s), y (s), z (s)
  {}
  Vector3 (float _x, float _y) : x (_x), y (_y), z (0)
  {}
  Vector3 (float _x, float _y, float _z) : x (_x), y (_y), z (_z)
  {}
  operator glm::vec3 ()
  {
    return glm::vec3 (x, y, z);
  }
  void Set (float x_, float y_)
  {
    x = x_;
    y = y_;
  }

  Vector3 operator-(void) const
  {
    return Vector3 (-x, -y, -z);
  }

  Vector3 operator*(float s) const
  {
    return Vector3 (x * s, y * s, z * s);
  }

  Vector3 operator/(float s) const
  {
    return Vector3 (x / s, y / s, z / s);
  }

  void operator*=(float s)
  {
    x *= s;
    y *= s;
    z *= s;
  }

  Vector3 operator+(const Vector3& rhs) const
  {
    return Vector3 (x + rhs.x, y + rhs.y, z + rhs.z);
  }

  Vector3 operator+(float s) const
  {
    return Vector3 (x + s, y + s, z + s);
  }

  void operator+=(const Vector3& rhs)
  {
    x += rhs.x;
    y += rhs.y;
  }

  Vector3 operator-(const Vector3& rhs) const
  {
    return Vector3 (x - rhs.x, y - rhs.y, z - rhs.z);
  }

  void operator-=(const Vector3& rhs)
  {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
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

inline Vector3 operator*(float s, const Vector3& v)
{
  return Vector3 (s * v.x, s * v.y, s * v.z);
}

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
  Vector4 (float s) : x (s), y (s), z (s), w (s)
  {}
  Vector4 (float _x, float _y) : x (_x), y (_y), z (0), w (0)
  {}
  Vector4 (float _x, float _y, float _z) : x (_x), y (_y), z (_z), w (0)
  {}
  Vector4 (float _x, float _y, float _z, float _w) : x (_x), y (_y), z (_z), w (_w)
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