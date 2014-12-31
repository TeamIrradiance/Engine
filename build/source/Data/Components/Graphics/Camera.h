/******************************************************************************/
/*!
 \file   Camera.h
 \author Manas Sudhir Kulkarni
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/

#pragma once

namespace Framework
{
/******************************************************************************/
/*!
 \class   Camera
 \brief   Camera Component
 Notes: 
 */
/******************************************************************************/
//@@ Only this 4 function is allowed in component class
  class Camera: public Component
  {
  public:
    // Constructor - Destructor
    Camera();
    ~Camera();

    // Methods
    void DefineMeta ();
    void Initialize ();

    void UpdateCamera ();
    void Zoom (float zoom);

    // Functions

    // STATIC DATA
    static Camera* main;
    static std::unordered_map<unsigned, Camera*> allCameras;

    Vector3 m_viewDirection;
    Vector3 m_upVector;
    float m_size;
    float m_aspect;
    float m_fov;
    float m_nearPlane;
    float m_farPlane;

  private:

    // DATA
    Matrix4x4 m_viewMatrix;
    Matrix4x4 m_projectionMatrix;

  };
}