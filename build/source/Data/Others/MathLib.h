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
class Vector2 : public IData
{
  public:
    // Constructor - Destructor
    Vector2 (){}

    // Methods
    void DefineMeta();

    // Functions

    // Data
    glm::vec2 m_vec2;
};

/******************************************************************************/
/*!
 \class   Vector3
 \brief   Vector3 class, we need a vector struct that inherit from IData
          for serialization and tool automation
 */
/******************************************************************************/
class Vector3 : public IData
{
  public:
    // Constructor - Destructor
    Vector3 (){}

    // Methods
    void DefineMeta();

    // Functions

    // Data
    glm::vec3 m_vec3;
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
    // Constructor - Destructor
    Vector4 (){}

    // Methods
    void DefineMeta();

    // Functions

    // Data
    glm::vec4 m_vec4;
};