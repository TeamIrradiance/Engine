//******************************************************************************/
//*!
// \file   Sprite.h
// \author Aji Suprana
// \par    Course: GAM250
// \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
// \brief
// */
//******************************************************************************/

#pragma once

namespace Framework
{
//******************************************************************************/
//*!
// \macros   Sprite
// \brief   Sprite Component
// Notes: 
// */
//******************************************************************************/
  class Sprite: public Framework::Component
  {
  public:
    Sprite();
    ~Sprite();

    void DefineMeta();

    //DATA
    //Vector2 size;
    std::string m_textureName;

  };
}