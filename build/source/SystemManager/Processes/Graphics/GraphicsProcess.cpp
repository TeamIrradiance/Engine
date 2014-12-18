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
#include "GraphicsProcess.h"
namespace Process
{
  void GraphicsProcess::VUpdate(const double dt)
  {

  }

  void GraphicsProcess::VInit()
  {

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

  }
}