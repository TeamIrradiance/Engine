/******************************************************************************/
/*!
 \file   WindowProcess.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include "WindowProcess.h"
namespace Process
{
  void WindowProcess::VUpdate(const double dt)
  {

  }

  void WindowProcess::VInit()
  {

  }
  
  WindowProcess::WindowProcess()
  {
    std::hash<std::string> id;
    mName = std::string("window");
    mProcessID = id(mName); //faster access with hash instead of string
    m_bActive = true; // skip when process is deactivated
    m_bInitialized = false; //debugging purposes if initialized
    m_bAttached = false; // check if process is attached to manager
  }

  WindowProcess::~WindowProcess()
  {

  }
}