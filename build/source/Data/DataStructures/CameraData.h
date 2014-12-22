/******************************************************************************/
/*!
\file   CameraData.h
\author Aji Suprana
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#pragma once

namespace Framework
{

  class CameraData : public IData
  {
  public:
    virtual void DefineMeta ();

    float m_aspect;
    float m_fov;
    float m_size;
    float m_nearPlane;
    float m_farPlane;
    Vector3 m_viewDirection;
    Vector3 m_upVector;

  };

}