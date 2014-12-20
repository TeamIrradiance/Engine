/******************************************************************************/
/*!
 \file   TemplateProcess.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief  Template for all proces classes
 */
/******************************************************************************/
#include <Precompiled.h>
#include "Process_Template.h"
namespace Framework
{
  void TemplateProcess::VUpdate(const double dt)
  {

  }

  void TemplateProcess::VInit()
  {

  }
  
  TemplateProcess::TemplateProcess()
  {
    std::hash<std::string> id;
    mName = std::string("template");
    mProcessID = id(mName); //faster access with hash instead of string
    m_bActive = true; // skip when process is deactivated
    m_bInitialized = false; //debugging purposes if initialized
    m_bAttached = false; // check if process is attached to manager
    
  }

  TemplateProcess:: ~TemplateProcess()
  {

  }
}