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

    glm::vec4 _;
  };

}