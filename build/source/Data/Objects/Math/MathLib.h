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

namespace Framework
{


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
    void DefineMeta ();

    Vector2 ()
    {}
    Vector2 (const glm::vec2& v) : _ (v)
    {}
    operator glm::vec2 ()
    {
      return _;
    }

    float r ()
    {
      return _.r;
    }
    float g ()
    {
      return _.g;
    }

    float x ()
    {
      return _.x;
    }
    float y ()
    {
      return _.y;
    }

    // DATA
    glm::vec2 _;

  };

  /******************************************************************************/
  /*!
  \class   Vector3
  \brief   Vector3 class, we need a vector struct that inherit from IData
  for serialization and tool automation
  */
  /******************************************************************************/
  class Vector3 :public IData
  {
  public:
    void ToolInit ();
    void Serialize ();
    void DefineMeta ();

    Vector3 ()
    {}
    Vector3 (const glm::vec3& v) : _ (v)
    {}
    operator glm::vec3 ()
    {
      return _;
    }

    float r ()
    {
      return _.r;
    }
    float g ()
    {
      return _.g;
    }
    float b ()
    {
      return _.b;
    }

    float x ()
    {
      return _.x;
    }
    float y ()
    {
      return _.y;
    }
    float z ()
    {
      return _.z;
    }

    // DATA
    glm::vec3 _;

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
    void DefineMeta ();

    Vector4 ()
    {}
    Vector4 (const glm::vec4& v) : _ (v)
    {}
    operator glm::vec4 ()
    {
      return _;
    }

    float r ()
    {
      return _.r;
    }
    float g ()
    {
      return _.g;
    }
    float b ()
    {
      return _.b;
    }

    float a ()
    {
      return _.a;
    }

    float x ()
    {
      return _.x;
    }
    float y ()
    {
      return _.y;
    }
    float z ()
    {
      return _.z;
    }
    float w ()
    {
      return _.w;
    }

    // DATA
    glm::vec4 _;

  };

}