/******************************************************************************/
/*!
 \file   EngineCore.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include <Precompiled.h>
#include "IEngineCore.h"

EngineCore* gEngineCore = 0;
/******************************************************************************/
/*!
  \class   EngineCore()
  \brief   Constructor
  */
/******************************************************************************/
EngineCore::EngineCore()
{
  ErrorIf(gEngineCore != 0,"Engine is created!");
  gEngineCore = this;

  gEngineCore->g_csProcessManager = NULL;
}

/******************************************************************************/
/*!
  \class   ~EngineCore()
  \brief   destructor
  */
/******************************************************************************/
EngineCore::~EngineCore()
{

};

/******************************************************************************/
/*!
  \class   Init()
  \brief   Initialize systems
  */
/******************************************************************************/
void EngineCore::Init()
{
  g_csProcessManager->InitProcesses();
}

/******************************************************************************/
/*!
  \class   Update()
  \brief   game loop
  */
/******************************************************************************/
void EngineCore::Update()
{
  while(g_bGameIsActive)
  {
      //glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS
  while(!glfwWindowShouldClose(gEngineCore->g_glWindow) )
  {

    // Draw nothing, see you in tutorial 2 !
 
      // Swap buffers
      glfwSwapBuffers(gEngineCore->g_glWindow);
      glfwPollEvents();

  }
  }
}
