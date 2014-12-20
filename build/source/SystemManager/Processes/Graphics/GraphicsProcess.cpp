/******************************************************************************/
/*!
 \file   GraphicsProcess.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief  Template for all proces classes
 */
/******************************************************************************/
#include <Precompiled.h>

namespace Framework
{

  void GraphicsProcess::VInit()
  {
    TransformPipeline* trans = new TransformPipeline ();
    RenderPipeline* render = new RenderPipeline ();
  }

  void GraphicsProcess::VUpdate (const double dt)
  {
    G_TRANSFORM->Update (dt);
    G_RENDER->Draw ();
  }
  
  GraphicsProcess::GraphicsProcess()
  {
    std::hash<std::string> id;
    mName = std::string("graphics");
    mProcessID = id(mName); //faster access with hash instead of string
    m_bActive = true; // skip when process is deactivated
    m_bInitialized = false; //debugging purposes if initialized
    m_bAttached = false; // check if process is attached to manager
    
  }

  GraphicsProcess:: ~GraphicsProcess()
  {
    if (G_TRANSFORM != nullptr)
    {
      delete G_TRANSFORM;
    }

    if (G_RENDER != nullptr)
    {
      delete G_RENDER;
    }
  }
}