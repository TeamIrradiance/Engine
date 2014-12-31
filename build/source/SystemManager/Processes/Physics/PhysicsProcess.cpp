/******************************************************************************/
/*!
\file   PhyiscSystemNew.cpp
\author Manas Sudhir Kulkarni
\par    Course: GAM200
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#include <Precompiled.h>
#include "RigidBody2D.h"
#include "Collider2D.h"


namespace Framework
{
    PhysicsSystem* PHYSICS = NULL;

    PhysicsSystem::PhysicsSystem(float dt, unsigned iterations) : m_dt(dt)
      , m_iterations(iterations)
    {
      PHYSICS = this;
    }

    PhysicsSystem::PhysicsSystem ()
    {
      PHYSICS = this;
      m_dt = 1.0f / 60.0f;
      m_iterations = 10;
    }


    void IntegrateForces(RigidBody2D *b, float dt)
    {
      if (b->im == 0.0f)
        return;

      b->velocity += (b->force * b->im + gravity) * (dt / 2.0f);
      //std::cout << b->velocity.x << "\n";
      b->angularVelocity += b->torque * b->iI * (dt / 2.0f);
    }

    void IntegrateVelocity(RigidBody2D *b, float dt)
    {
      if (b->im == 0.0f)
        return;

      b->position += b->velocity * dt;
      b->orient += b->angularVelocity * dt;
      b->SetOrient(b->orient);
      if (b->gameObject != nullptr)
      {
        b->gameObject->transform->position = Vector3(b->position.x, b->position.y, b->gameObject->transform->position.z);
        b->gameObject->transform->Rotate(b->angularVelocity * dt);
      }
      IntegrateForces(b, dt);
    }

    void PhysicsSystem::Step(void)
    {
      // Generate new collision info
      contacts.clear();
      for (unsigned i = 0; i < rigidBodies.size(); ++i)
      {
        RigidBody2D *A = rigidBodies[i];

        for (unsigned j = i + 1; j < rigidBodies.size(); ++j)
        {
          RigidBody2D *B = rigidBodies[j];
          if (A->im == 0 && B->im == 0)
            continue;
          Manifold m(A, B);
          m.Solve();
          if (m.contact_count)
            contacts.emplace_back(m);
        }
      }

      // Integrate forces
      for (unsigned i = 0; i < rigidBodies.size(); ++i)
        IntegrateForces(rigidBodies[i], m_dt);

      // Initialize collision
      for (unsigned i = 0; i < contacts.size(); ++i)
        contacts[i].Initialize();

      // Solve collisions
      for (unsigned j = 0; j < m_iterations; ++j)
        for (unsigned i = 0; i < contacts.size(); ++i)
          contacts[i].ApplyImpulse();

      // Integrate velocities
      for (unsigned i = 0; i < rigidBodies.size(); ++i)
        IntegrateVelocity(rigidBodies[i], m_dt);

      // Correct positions
      for (unsigned i = 0; i < contacts.size(); ++i)
        contacts[i].PositionalCorrection();

      // Clear all forces
      for (unsigned i = 0; i < rigidBodies.size(); ++i)
      {
        RigidBody2D *b = rigidBodies[i];
        b->force.Set(0, 0);
        b->torque = 0;
      }
    }

    void PhysicsSystem::Render(void)
    {
      glMatrixMode (GL_PROJECTION);
      glLoadIdentity ();
      gluPerspective
        (
        Camera::main->m_fov,
        (float) G_CORE->G_CONTEXT.GetWindowWidth () / G_CORE->G_CONTEXT.GetWindowHeight (),
        Camera::main->m_nearPlane,
        Camera::main->m_farPlane
        );
      glMatrixMode (GL_MODELVIEW);
      glLoadIdentity ();

      glm::vec3 eye, center, up;
      eye = glm::vec3 (0, 0, 1) * Camera::main->m_size + glm::vec3 (Camera::main->gameObject->transform->position.x, Camera::main->gameObject->transform->position.y, 0);
      center = Camera::main->gameObject->transform->position;
      up = glm::vec3 (0, 1, 0);

      gluLookAt (eye.x, eye.y, eye.z, center.x, center.y, center.z, up.x, up.y, up.z);

      for (unsigned i = 0; i < rigidBodies.size (); ++i)
      {
        RigidBody2D *b = rigidBodies [i];
        b->shape->Draw ();
      }

      glPointSize (4.0f);
      glBegin (GL_POINTS);
      glColor3f (1.0f, 0.0f, 0.0f);
      for (unsigned i = 0; i < contacts.size (); ++i)
      {
        Manifold& m = contacts [i];
        for (unsigned j = 0; j < m.contact_count; ++j)
        {
          Vector2 c = m.contacts [j];
          glVertex2f (c.x, c.y);
        }
      }
      glEnd ();
      glPointSize (1.0f);

      glBegin (GL_LINES);
      glColor3f (0.0f, 1.0f, 0.0f);
      for (unsigned i = 0; i < contacts.size (); ++i)
      {
        Manifold& m = contacts [i];
        Vector2 n = m.normal;
        for (unsigned j = 0; j < m.contact_count; ++j)
        {
          Vector2 c = m.contacts [j];
          glVertex2f (c.x, c.y);
          n *= 0.75f;
          c += n;
          glVertex2f (c.x, c.y);
        }
      }
      glEnd ();

      glLoadIdentity ();
    }

    RigidBody2D * PhysicsSystem::Add(ShapeCollider2D *shape, float x, float y)
    {
      assert(shape);
      RigidBody2D *b = new RigidBody2D (shape, (float)x, (float)y);
      rigidBodies.push_back(b);
      return b;
    }

    void PhysicsSystem::Remove(RigidBody2D* rb)
    {
      for (auto it = rigidBodies.begin(); it != rigidBodies.end(); ++it)
      {
        if ((*it) == rb)
        {
          rigidBodies.erase(it);
          break;
        }
      }
    }

    void PhysicsSystem::Clear()
    {
      contacts.clear();
      rigidBodies.clear();
    }

    void PhysicsSystem::VUpdate (const double dt)
    {
      Step ();
    }

    void PhysicsSystem::VInit ()
    {
    }

}
