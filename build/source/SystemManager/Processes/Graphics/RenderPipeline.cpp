/******************************************************************************/
/*!
\file   Pipeline.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief  Template for all proces classes
*/
/******************************************************************************/

#include <Precompiled.h>
#include "Sprite.h"

namespace Framework
{
  RenderPipeline* G_RENDER;
  SpriteBatcher* batch = new SpriteBatcher ();

  RenderPipeline::RenderPipeline ()
  {
    G_RENDER = this;
    glClearColor (m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
    batch->Initialize ();

    for (int i = 0; i < 1; ++i)
    {
      Sprite* sprite = new Sprite ();
      sprite->SpriteSource = "Circle";
      sprite->Initialize ();
      //batch->AddSprite (sprite, ResourceManager::LoadResource("ATLAS", R_ATLAS)->Name);
    }
  }

  RenderPipeline::~RenderPipeline ()
  {
    G_RENDER = nullptr;
  }

  void RenderPipeline::Draw ()
  {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    batch->Batch ();
  }

}