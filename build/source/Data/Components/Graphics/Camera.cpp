/******************************************************************************/
/*!
 \file   Camera.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>

namespace Framework
{
  std::unordered_map<unsigned, Camera*> Camera::allCameras;
  Camera* Camera::main;


/******************************************************************************/
/*!
\fn      Camera()
\brief   Default constructor
*/
/******************************************************************************/
  Camera::Camera()
  {
    m_sName = Tokenize(typeid(Camera).name());
    gameObject->camera = this;
  }

/******************************************************************************/
/*!
\fn   ~Camera()
\brief   destructor
*/
/******************************************************************************/
  Camera::~Camera()
  {

  }

/******************************************************************************/
/*!
\fn   DefineMeta()
\brief   define meta here
*/
/******************************************************************************/
  void Camera::DefineMeta()
  {
    allCameras.emplace (std::make_pair (m_mask, this));
  }

  void Camera::UpdateCamera ()
  {
    G_TRANSFORM->MatrixMode (VIEW);

    G_TRANSFORM->Translatefv (glm::value_ptr (gameObject->transform->translation._));

    G_TRANSFORM->Perspective (m_fov, m_aspect, m_nearPlane, m_farPlane);
    Vector3 eye = m_size * m_viewDirection._ + glm::vec3 (gameObject->transform->translation.x (), gameObject->transform->translation.y (), 0.0);
    G_TRANSFORM->LookAt (eye, gameObject->transform->translation, m_upVector);
    G_TRANSFORM->MatrixMode (MODEL);
    G_TRANSFORM->LoadIdentity ();

    G_TRANSFORM->MatrixMode (MODEL);
    G_TRANSFORM->LoadIdentity ();
  }

}