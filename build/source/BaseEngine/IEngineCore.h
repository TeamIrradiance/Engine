/******************************************************************************/
/*!
 \file   IEngineCore.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include "IBaseEngine.h"
#define EngineSettings g_csEngineCore->settings


struct EngineSetup
{
  //Engine Settings
  bool consoleActive;
  int windowsX;
  int windowsY;
  int fps_cap;
  std::string application_name;
};

/******************************************************************************/
/*!
 \class   EngineCore
 \brief   Storing core system's global pointer.
            - Process Manager
            - EventPool
            - GarbageCollector
 */
/******************************************************************************/
struct EngineCore
{
  EngineCore();
  ~EngineCore();

  void Init();
  void Update();

  //GLOBAL SYSTEMS
  BaseEngine::IframeRate* g_csFramerateControl;
  BaseEngine::CProcessManager* g_csProcessManager;

  //GLOBAL VARIABLES
  bool g_bGameIsActive;
  GLFWwindow* g_glWindow;
  EngineSetup settings;

  //Debugging purposes
  bool m_bIsInitialized;
};

extern EngineCore* g_csEngineCore;
