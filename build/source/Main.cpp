/******************************************************************************/
/*!
 \file   CProcess.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include <vld.h> // if it does give an error, Download visual leak detector
#include "IBaseEngine.h"
#include "IProcess.h"

#define CONNECT(Vec3,data)\

int main (void)
{
  EngineCore Engine;
  Engine.settings.consoleActive = false;
  Engine.settings.fps_cap = 60;
  Engine.settings.windowsX = 500;
  Engine.settings.windowsY = 500;
  Engine.settings.application_name = "Irradiance";

  AddProcess(new Process::WindowProcess);

  Engine.Init();
  Engine.Update();



  return 0;
}