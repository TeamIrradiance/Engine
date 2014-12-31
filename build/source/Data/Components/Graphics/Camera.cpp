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
    m_fov = 45.0f;
    m_nearPlane = 0.1f;
    m_farPlane = 100.0f;
    m_size = 10.0f;
    m_aspect = (float)G_CORE->G_CONTEXT.GetWindowWidth () / G_CORE->G_CONTEXT.GetWindowHeight ();
    m_upVector = Vector3 (0, 1, 0);
    m_viewDirection = Vector3 (0, 0, 1);
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
    //allCameras.emplace (std::make_pair (m_mask, this));
  }

  void OnKeyPressed (GLFWwindow* wind, int key, int action, int scanCode, int mods)
  {
    float camSpeed = 0.1f;
    float camZoom = 0.1f;
    switch (key)
    {
    case GLFW_KEY_W:
      Camera::main->gameObject->transform->Translate (0, camSpeed, 0);
      break;
    case GLFW_KEY_S:
      Camera::main->gameObject->transform->Translate (0, -camSpeed, 0);
      break;
    case GLFW_KEY_D:
      Camera::main->gameObject->transform->Translate (camSpeed, 0, 0);
      break;
    case GLFW_KEY_A:
      Camera::main->gameObject->transform->Translate (-camSpeed, 0, 0);
      break;
    case GLFW_KEY_X:
      Camera::main->Zoom (-camZoom);
      break;
    case GLFW_KEY_Z:
      Camera::main->Zoom (camZoom);
      break;
    default:
      break;
    }
  }

  /*************************************************************************/
  // Method:    Initialize
  // FullName:  Framework::Camera::Initialize
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Initialize Camera Component
  /*************************************************************************/
  void Camera::Initialize ()
  {
    glfwSetKeyCallback (G_CORE->G_CONTEXT.GetWindow (), OnKeyPressed);
    gameObject->camera = this;
    allCameras [gameObject->m_layer] = this;

    //if (mainCamera)
    {
      Camera::main = this;
      //Camera::main->Zoom(-100.0f);
      m_viewMatrix = glm::lookAt (glm::vec3 (m_size * m_viewDirection + glm::vec3 (gameObject->transform->position.x, gameObject->transform->position.y, 0.0)), glm::vec3 (gameObject->transform->position), glm::vec3 (m_upVector));
      m_projectionMatrix = glm::perspective (m_fov * M_PI / 180, m_aspect, m_nearPlane, m_farPlane);
    }

    //OPENGL->cameras.push_back (this);
    //OPENGL->Perspective (fov, aspect, nearPlane, farPlane);
    //OPENGL->MatrixMode (MODEL);
    //OPENGL->Translatefv (const_cast <float*>(glm::value_ptr (gameObject->Transform->GetPosition ())));
    //OPENGL->MatrixMode (VIEW);
    //OPENGL->LookAt
    //  (size * viewDirection +
    //  glm::vec3 (gameObject->Transform->GetPosition ().x, gameObject->Transform->GetPosition ().y, 0.0),
    //  gameObject->Transform->GetPosition (), up);
    //OPENGL->MatrixMode (MODEL);
    //OPENGL->LoadIdentity ();
    //matricesReady = true;

  }

  void Camera::Zoom (float zoom)
  {
    m_size += zoom;
  }

  /*************************************************************************/
  // Method:    UpdateCamera
  // FullName:  Framework::Camera::UpdateCamera
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Update Camera Matrices - Model, View, Projection
  /*************************************************************************/
  void Camera::UpdateCamera ()
  {
    G_TRANSFORM->MatrixMode (VIEW);

    G_TRANSFORM->Translatefv (glm::value_ptr (glm::vec3 (gameObject->transform->position.x, gameObject->transform->position.y, gameObject->transform->position.z )));

    G_TRANSFORM->Perspective (m_fov, m_aspect, m_nearPlane, m_farPlane);
    Vector3 eye = m_size * m_viewDirection + gameObject->transform->position;
    G_TRANSFORM->LookAt (eye, (glm::vec3)gameObject->transform->position, (glm::vec3)m_upVector);
    G_TRANSFORM->MatrixMode (MODEL);
    G_TRANSFORM->LoadIdentity ();

    G_TRANSFORM->MatrixMode (MODEL);
    G_TRANSFORM->LoadIdentity ();
  }

}