/******************************************************************************/
/*!
\file   Manifold.cpp
\author Manas Sudhir Kulkarni
\par    Course: GAM200
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#include <Precompiled.h>
#include "Manifold.h"
#include "Collision.h"
#include "PhysicsLibrary.h"
#include "RigidBody2D.h"
#include "Collider2D.h"

namespace Framework
{
  void Manifold::Solve (void)
  {
    Dispatch [A->shape->GetType ()][B->shape->GetType ()] (this, A, B);
  }

  void Manifold::Initialize (void)
  {
    // Calculate average restitution
    e = (std::min)(A->restitution, B->restitution);

    // Calculate static and dynamic friction
    sf = std::sqrt (A->staticFriction * A->staticFriction);
    df = std::sqrt (A->dynamicFriction * A->dynamicFriction);

    for (unsigned i = 0; i < contact_count; ++i)
    {
      // Calculate radii from COM to contact
      Vector2 ra = contacts [i] - A->position;
      Vector2 rb = contacts [i] - B->position;

      Vector2 rv = B->velocity + Cross (B->angularVelocity, rb) -
        A->velocity - Cross (A->angularVelocity, ra);


      // Determine if we should perform a resting collision or not
      // The idea is if the only thing moving this object is gravity,
      // then the collision should be performed without any restitution
      if (rv.LenSqr () < (dt * gravity).LenSqr () + EPSILON)
        e = 0.0f;
    }
  }

  void Manifold::ApplyImpulse (void)
  {
    // Early out and positional correct if both objects have infinite mass
    if (Equal (A->im + B->im, 0))
    {
      InfiniteMassCorrection ();
      return;
    }

    for (unsigned i = 0; i < contact_count; ++i)
    {
      // Calculate radii from COM to contact
      Vector2 ra = contacts [i] - A->position;
      Vector2 rb = contacts [i] - B->position;

      // Relative velocity
      Vector2 rv = B->velocity + Cross (B->angularVelocity, rb) -
        A->velocity - Cross (A->angularVelocity, ra);

      // Relative velocity along the normal
      float contactVel = Dot (rv, normal);

      // Do not resolve if velocities are separating
      if (contactVel > 0)
        return;

      float raCrossN = Cross (ra, normal);
      float rbCrossN = Cross (rb, normal);
      float invMassSum = A->im + B->im + Sqr (raCrossN) * A->iI + Sqr (rbCrossN) * B->iI;

      // Calculate impulse scalar
      float j = -(1.0f + e) * contactVel;
      j /= invMassSum;
      j /= (float) contact_count;

      // ***** SUPER BUG AHEAD
      //if ((OBJECTSYSTEM->ptrPlayer != nullptr) && (OBJECTSYSTEM->ptrPlayer->RigidBody2D->velocity.Len()) > 1000)
      //  __debugbreak();
      //

      // Apply impulse         !!  SUPER BUG IS HERE  !
      Vector2 impulse = normal * j;
      A->ApplyImpulse (-impulse, ra);
      B->ApplyImpulse (impulse, rb);

      // ***** SUPER BUG ABOVE
      //if ((OBJECTSYSTEM->ptrPlayer != nullptr) && (OBJECTSYSTEM->ptrPlayer->RigidBody2D->velocity.Len()) > 1000)
      //  __debugbreak();
      //

      // Friction impulse
      rv = B->velocity + Cross (B->angularVelocity, rb) -
        A->velocity - Cross (A->angularVelocity, ra);

      Vector2 t = rv - (normal * Dot (rv, normal));
      t.Normalize ();

      // j tangent magnitude
      float jt = -Dot (rv, t);
      jt /= invMassSum;
      jt /= (float) contact_count;

      // Don't apply tiny friction impulses
      if (Equal (jt, 0.0f))
        return;

      // Coulumb's law
      Vector2 tangentImpulse;
      if (std::abs (jt) < j * sf)
        tangentImpulse = t * jt;
      else
        tangentImpulse = t * -j * df;

      // Apply friction impulse
      A->ApplyImpulse (-tangentImpulse, ra);
      B->ApplyImpulse (tangentImpulse, rb);
    }
  }

  void Manifold::PositionalCorrection (void)
  {
    const float k_slop = 0.05f; // Penetration allowance
    const float percent = 0.4f; // Penetration percentage to correct
    Vector2 correction = ((std::max)(penetration - k_slop, 0.0f) / (A->im + B->im)) * normal * percent;
    A->position -= correction * A->im;
    B->position += correction * B->im;
    if (A->gameObject != nullptr)
      A->gameObject->transform->position = Vector3 (A->position.x, A->position.y);
    if (B->gameObject != nullptr)
      B->gameObject->transform->position = Vector3 (B->position.x, B->position.y);
  }

  void Manifold::InfiniteMassCorrection (void)
  {
    A->velocity.Set (0, 0);
    if (!A->shape->isStatic)
      A->gameObject->transform->position = Vector3 (0, 0);
    B->velocity.Set (0, 0);
    if (!B->shape->isStatic)
      B->gameObject->transform->position = Vector3 (0, 0);
  }
}

