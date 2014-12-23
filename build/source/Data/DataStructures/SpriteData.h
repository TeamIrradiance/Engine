/******************************************************************************/
/*!
\file   SpriteData.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#pragma once

namespace Framework
{

  class SpriteData : public IData
  {

  public:
    void DefineMeta ();

    std::string m_shader;
    std::string m_texture;
    Vector4 m_color;
    Vector2 m_texcoord;
    bool m_visible;
    unsigned m_layerID;

  };

}