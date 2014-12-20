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
    void DefineMeta();
    void UpdateCamera ();

    // Functions

    // STATIC DATA
    static Camera* main;
    static std::unordered_map<unsigned, Camera*> allCameras;

  private:

    // DATA
    unsigned m_mask;
    float m_aspect;
    float m_fov;
    float m_size;
    float m_nearPlane;
    float m_farPlane;
    Vector3 m_viewDirection;
    Vector3 m_upVector;

  };
}