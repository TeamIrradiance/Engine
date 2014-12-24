/******************************************************************************/
/*!
\file   SpriteData.cpp
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#include <Precompiled.h>
#include "SpriteData.h"

namespace Framework
{
  void SpriteData::DefineMeta ()
  {
    meta_begin (SpriteData)

    meta_child (SpriteData, m_shader)
    meta_child (SpriteData, m_texture)
    meta_child (SpriteData, m_color)
    meta_child (SpriteData, m_visible)
    meta_child (SpriteData, m_layerID)

    meta_end ()
  }

}