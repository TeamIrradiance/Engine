/******************************************************************************/
/*!
\file   Manifold.h
\author Manas Sudhir Kulkarni
\par    Course: GAM200
\par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#ifndef MANIFOLD_H
#define MANIFOLD_H

#include "PhysicsLibrary.h"

namespace Framework
{
	class RigidBody2D;
	class Manifold
	{
	public:
	  Manifold( RigidBody2D *a, RigidBody2D *b )
	    : A( a )
	    , B( b )
	  {
	  }
	
	  void Solve( void );                 // Generate contact information
	  void Initialize( void );            // Precalculations for impulse solving
	  void ApplyImpulse( void );          // Solve impulse and apply
	  void PositionalCorrection( void );  // Naive correction of positional penetration
	  void InfiniteMassCorrection( void );
	
	  RigidBody2D *A;
	  RigidBody2D *B;
	
	  float penetration;     // Depth of penetration from collision
	  Vector2 normal;          // From A to B
	  Vector2 contacts[2];     // Points of contact during collision
	  unsigned contact_count; // Number of contacts that occured during collision
	  float e;               // Mixed restitution
	  float df;              // Mixed dynamic friction
	  float sf;              // Mixed static friction
	};
}


#endif // MANIFOLD_H