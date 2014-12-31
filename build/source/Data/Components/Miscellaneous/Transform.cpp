/******************************************************************************/
/*!
 \file   Transform.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include "ITypeReflection.h"
#include "IComponents.h"

namespace Framework
{
/******************************************************************************/
/*!
\fn   Transform()
\brief   Constructor
*/
/******************************************************************************/
  Transform::Transform()
  {
    m_sName = Tokenize(typeid(Transform).name());
  }

/******************************************************************************/
/*!
\fn   ~Transform()
\brief   Destructor
*/
/******************************************************************************/
  Transform::~Transform()
  {
    //G_TRANSFORM->transformVectorMap [gameObject->m_layer].remove (this);
  }

/******************************************************************************/
/*!
\fn   DefineMeta()
\brief   define meta here
*/
/******************************************************************************/
  void Transform::DefineMeta()
  {

  }

  /*************************************************************************/
  // Method:    Initialize
  // FullName:  Framework::Transform::Initialize
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Initialize Component
  /*************************************************************************/
  void Transform::Initialize ()
  {
    gameObject->transform = this;
    G_TRANSFORM->AddTransform (this);
  }

  /*************************************************************************/
  // Method:    Update_Matrices
  // FullName:  Framework::Transform::Update_Matrices
  // Access:    private 
  // Returns:   void
  // Qualifier:
  // Parameter: double dt
  // Brief: Update Model, ModelViewProjection Matrix of Transform
  /*************************************************************************/
  void Transform::Update_Matrices (double dt)
  {
    G_TRANSFORM->MatrixMode (MODEL);
    G_TRANSFORM->LoadIdentity ();

    G_TRANSFORM->Translatefv ((float*)&position);
    G_TRANSFORM->Scalefv ((float*)&scale);
    G_TRANSFORM->Rotatef (rotation, 0, 0, 1);

    m_modelMatrix = G_TRANSFORM->GetModelMatrix ();

    m_modelViewProjectionMatrix =
      G_TRANSFORM->GetProjectionMatrix () *
      G_TRANSFORM->GetViewMatrix () *
      m_modelMatrix;

    G_TRANSFORM->LoadIdentity ();
  }

  //////////////////////////////////////////////////////////////////////////
  // GETTORS
  //////////////////////////////////////////////////////////////////////////


  /*************************************************************************/
  // Method:    GetModelMatrix
  // FullName:  Framework::Transform::GetModelMatrix
  // Access:    public 
  // Returns:   Matrix4x4
  // Qualifier:
  // Brief: Get Model Matrix of Transform
  /*************************************************************************/
  Matrix4x4 Transform::GetModelMatrix ()
  {
    return m_modelMatrix;
  }

  /*************************************************************************/
  // Method:    GetModelViewProjectionMatrix
  // FullName:  Framework::Transform::GetModelViewProjectionMatrix
  // Access:    public 
  // Returns:   Matrix4x4
  // Qualifier:
  // Brief: Get ModelViewProjection Matrix of Transform
  /*************************************************************************/
  Matrix4x4 Transform::GetModelViewProjectionMatrix ()
  {
    return m_modelViewProjectionMatrix;
  }

  void Transform::Translate (float x, float y, float z)
  {
    position += Vector3 (x, y, z);
  }

  void Transform::Translate (Vector3& vec)
  {
    position += vec;
  }

  void Transform::Scale (float x, float y, float z)
  {
    scale += Vector3 (x, y, z);
  }

  void Transform::Scale (float s)
  {
    scale += Vector3 (s);
  }

  void Transform::Scale (Vector3& vec)
  {
    scale += vec;
  }

  void Transform::Rotate (float r, float x, float y, float z)
  {
    rotation += r;
  }

  void Transform::Rotate (float r, Vector3& vec)
  {
    rotation += r;
  }

  void Transform::Rotate (float r)
  {
    rotation += r;
  }

}