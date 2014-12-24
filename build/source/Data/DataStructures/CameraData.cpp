/******************************************************************************/
/*!
\file   CameraData.cpp
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#include <Precompiled.h>
#include "CameraData.h"

namespace Framework
{

  void CameraData::DefineMeta ()
  {
    meta_begin (CameraData)

      meta_child (CameraData, m_upVector)
      meta_child (CameraData, m_aspect)
      meta_child (CameraData, m_fov)
      meta_child (CameraData, m_size)
      meta_child (CameraData, m_nearPlane)
      meta_child (CameraData, m_farPlane)
      meta_child (CameraData, m_viewDirection)
      meta_child (CameraData, m_upVector)

    meta_end ()
  }

}
