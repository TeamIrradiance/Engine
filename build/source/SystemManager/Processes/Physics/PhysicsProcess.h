/******************************************************************************/
/*!
\file   PhysicsSystemNew.h
\author Manas Sudhir Kulkarni
\par    Course: GAM200
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#pragma once

#include <vector>
#include "Manifold.h"
#include "PhysicsLibrary.h"

namespace Framework
{
  class RigidBody2D;
  class ShapeCollider2D;

  class PhysicsSystem : public Framework::CProcess
  {
  public:
    PhysicsSystem (float dt, unsigned iterations);
    PhysicsSystem ();

    RigidBody2D *Add (ShapeCollider2D *shape, float x, float y);
    void Remove (RigidBody2D* rb);

    void Step (void);
    void Render (void);
    void Clear (void);

    void Reset ();

    virtual void VUpdate (const double dt);

    virtual void VInit ();


    float m_dt;
    unsigned m_iterations;
    std::vector<RigidBody2D *> rigidBodies;
    std::vector<Manifold> contacts;
  };

  extern PhysicsSystem* PHYSICS;
}