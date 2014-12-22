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

namespace Framework
{
  RenderPipeline* G_RENDER;


  RenderPipeline::RenderPipeline ()
  {
    G_RENDER = this;
    glClearColor (m_clearColor.r (), m_clearColor.g (), m_clearColor.b (), m_clearColor.a ());
  }

  RenderPipeline::~RenderPipeline ()
  {
    G_RENDER = nullptr;
  }

  void RenderPipeline::Draw ()
  {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin (GL_QUADS);
    {
      glVertex2f (0.5f, 0.5f);
      glVertex2f (-0.5f, 0.5f);
      glVertex2f (-0.5f, -0.5f);
      glVertex2f (0.5f, -0.5f);
    }
    glEnd ();
  }

}