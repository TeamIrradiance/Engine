/******************************************************************************/
/*!
\file   Pipeline.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief  Template for all proces classes
*/
/******************************************************************************/

#include <Precompiled.h>
#include "Sprite.h"
#include "Collider2D.h"
#include "RigidBody2D.h"

namespace Framework
{
  RenderPipeline* G_RENDER;
  SpriteBatcher* batch = new SpriteBatcher ();

  RenderPipeline::RenderPipeline ()
  {
    G_RENDER = this;
    glClearColor (m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
    batch->Initialize ();

    GameObject* go = new GameObject ();
    go->m_layer = 0;
    go->AddComponent<Transform> ();
    go->GetComponent<Transform> ()->gameObject = go;
    go->GetComponent<Transform> ()->Initialize ();
    go->transform->position = glm::vec3 (0, 0, -10);
    go->AddComponent<Camera> ();
    go->GetComponent<Camera> ()->gameObject = go;
    go->GetComponent<Camera> ()->Initialize ();

    PolygonCollider2D* poly = new PolygonCollider2D ();
    poly->SetBox (10.0f, 1.0f);
    RigidBody2D* b = PHYSICS->Add (poly, 0.0f, -5.0f);
    b->SetOrient (0.0f);
    b->SetStatic ();
    b->restitution = 0.5f;
    b->staticFriction = 0.0f;
    b->dynamicFriction = 0.0f;

    CircleCollider2D* poly1 = new CircleCollider2D ();
    poly1->radius = 1.0f;
    //poly1->SetBox (0.5f, 0.5f);
    RigidBody2D* b1 = PHYSICS->Add (poly1, 0.0f, 3.0f);
    b1->SetOrient (0.1f);
    b1->SetStatic ();
    b1->restitution = 1.0f;
    b1->staticFriction = 0.0f;
    b1->dynamicFriction = 0.0f;

    {
      CircleCollider2D* poly1 = new CircleCollider2D ();
      poly1->radius = 1.0f;
      //poly1->SetBox (0.5f, 0.5f);
      RigidBody2D* b1 = PHYSICS->Add (poly1, 3.0f, 6.0f);
      b1->SetOrient (0.1f);
      //b1->SetStatic ();
      b1->restitution = 1.0f;
      b1->staticFriction = 0.0f;
      b1->dynamicFriction = 0.0f;
    }

    {
      CircleCollider2D* poly1 = new CircleCollider2D ();
      poly1->radius = 1.0f;
      //poly1->SetBox (0.5f, 0.5f);
      RigidBody2D* b1 = PHYSICS->Add (poly1, -3.0f, 6.0f);
      b1->SetOrient (0.1f);
      //b1->SetStatic ();
      b1->restitution = 1.0f;
      b1->staticFriction = 0.0f;
      b1->dynamicFriction = 0.0f;
    }
    {
      CircleCollider2D* poly1 = new CircleCollider2D ();
      poly1->radius = 1.0f;
      //poly1->SetBox (0.5f, 0.5f);
      RigidBody2D* b1 = PHYSICS->Add (poly1, -2.0f, 6.0f);
      b1->SetOrient (0.1f);
      //b1->SetStatic ();
      b1->restitution = 1.0f;
      b1->staticFriction = 0.0f;
      b1->dynamicFriction = 0.0f;
    }
    {
      PolygonCollider2D* poly1 = new PolygonCollider2D ();
      //poly1->radius = 1.0f;
      poly1->SetBox (0.5f, 0.5f);
      RigidBody2D* b1 = PHYSICS->Add (poly1, 0.0f, 0.0f);
      b1->SetOrient (0.1f);
      b1->SetStatic ();
      b1->restitution = 1.0f;
      b1->staticFriction = 0.0f;
      b1->dynamicFriction = 0.0f;
    }



    //for (int i = 0; i < 1; ++i)
    //{
    //  Sprite* sprite = new Sprite ();
    //  sprite->SpriteSource = "Circle";
    //  sprite->Initialize ();
    //  //batch->AddSprite (sprite, ResourceManager::LoadResource("ATLAS", R_ATLAS)->Name);
    //}
  }

  RenderPipeline::~RenderPipeline ()
  {
    G_RENDER = nullptr;
  }

  void RenderPipeline::Draw ()
  {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    batch->Batch ();

    PHYSICS->Render ();
  }

}