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

EngineCore* g_csEngineCore = 0;
/******************************************************************************/
/*!
  \class   EngineCore()
  \brief   Constructor
  */
/******************************************************************************/
EngineCore::EngineCore()
{
  ErrorIf(g_csEngineCore != 0,"Engine is created!");
  g_csEngineCore = this;

  g_bGameIsActive = true;
  m_bIsInitialized = false;

  g_csProcessManager = NULL;
  g_csFramerateControl = NULL;
  g_csProcessManager = new BaseEngine::CProcessManager;
  g_csFramerateControl = new BaseEngine::IframeRate;
}

/******************************************************************************/
/*!
  \class   ~EngineCore()
  \brief   destructor
  */
/******************************************************************************/
EngineCore::~EngineCore()
{
  delete g_csProcessManager;
  delete g_csFramerateControl;
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
  g_csFramerateControl->Init(settings.fps_cap);

  m_bIsInitialized = true;
}

/******************************************************************************/
/*!
  \class   Update()
  \brief   game loop
  */
/******************************************************************************/
void EngineCore::Update()
{
  ErrorIf(!m_bIsInitialized,"Engine hasn't been initialized!");
  while(g_bGameIsActive)
  {
    g_csFramerateControl->StartTime();
    g_csProcessManager->UpdateProcesses(g_csFramerateControl->m_dDt);
    g_csFramerateControl->Update();
  }
}
