/******************************************************************************/
/*!
 \file   Transform.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include "Precompiled.h"
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
    gameObject->transform = this;
    G_TRANSFORM->transformVectorMap [gameObject->m_layer].push_back (this);
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
    G_TRANSFORM->transformVectorMap [gameObject->m_layer].remove (this);
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

  void Transform::Update_Matrices (double dt)
  {
    G_TRANSFORM->MatrixMode (MODEL);
    G_TRANSFORM->LoadIdentity ();

    G_TRANSFORM->Translatefv (glm::value_ptr (translation._));
    G_TRANSFORM->Scalefv (glm::value_ptr (scale._));
    G_TRANSFORM->Rotatef (rotation, 0, 0, 1);

    m_modelMatrix = G_TRANSFORM->GetModelMatrix ();

    m_modelViewProjectionMatrix =
      G_TRANSFORM->GetProjectionMatrix () *
      G_TRANSFORM->GetViewMatrix () *
      m_modelMatrix;

    G_TRANSFORM->LoadIdentity ();
  }

  Matrix4x4 Transform::GetModelMatrix ()
  {
    return m_modelMatrix;
  }

  Matrix4x4 Transform::GetModelViewProjectionMatrix ()
  {
    return m_modelViewProjectionMatrix;
  }

}