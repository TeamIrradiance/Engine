/******************************************************************************/
/*!
\file   Pipeline.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief  Template for all proces classes
*/
/******************************************************************************/

#include "Precompiled.h"

namespace Framework
{
  RenderPipeline* G_RENDER;


  RenderPipeline::RenderPipeline ()
  {
    G_RENDER = this;
  }

  RenderPipeline::~RenderPipeline ()
  {
    G_RENDER = nullptr;
  }

  void RenderPipeline::Draw ()
  {

  }

}