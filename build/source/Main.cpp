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
//#include <vld.h> // if it does give an error, Download visual leak detector
#include "IBaseEngine.h"
#include "IProcess.h"
#include "TypeReflection_Sample.h"
#include "Json.h"
struct Vec3
{
  float x, y, z;
};
int main (void)
{
  EngineCore Engine;
  Engine.settings.consoleActive = true;
  Engine.settings.fps_cap = 60;
  Engine.settings.windowsX = 1024;
  Engine.settings.windowsY = 576;
  Engine.settings.application_name = "Irradiance";

  AddProcess (new Framework::ResourceManager);
  AddProcess(new Framework::WindowProcess);
  AddProcess(new Framework::GraphicsProcess);

  //Engine.DefineMeta();
  Engine.Init();
  //type_sample();


  Engine.Update();

  return 0;
}