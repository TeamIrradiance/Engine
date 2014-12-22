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

EngineCore* g_csEngineCore = 0;
/******************************************************************************/
/*!
\class   EngineCore()
\brief   Constructor
*/
/******************************************************************************/
EngineCore::EngineCore ()
{
  ErrorIf (g_csEngineCore != 0, "Engine is created!");
  g_csEngineCore = this;

  g_bGameIsActive = true;
  m_bIsInitialized = false;

  g_csProcessManager = NULL;
  g_csFramerateControl = NULL;
  g_csProcessManager = new Framework::CProcessManager;
  g_csFramerateControl = new Framework::IframeRate;
}

/******************************************************************************/
/*!
\class   ~EngineCore()
\brief   destructor
*/
/******************************************************************************/
EngineCore::~EngineCore ()
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
void EngineCore::Init ()
{
  g_csProcessManager->InitProcesses ();
  g_csFramerateControl->Init (settings.fps_cap);

  m_bIsInitialized = true;
}

/******************************************************************************/
/*!
\class   Update()
\brief   game loop
*/
/******************************************************************************/
void EngineCore::Update ()
{
  ErrorIf (!m_bIsInitialized, "Engine hasn't been initialized!");
  while (g_bGameIsActive)
  {
    g_csFramerateControl->StartTime ();
    g_csProcessManager->UpdateProcesses (g_csFramerateControl->m_dDt);
    g_csFramerateControl->Update ();
  }
}

/******************************************************************************/
/*!
\class   Update()
\brief   game loop
*/
/******************************************************************************/
void EngineCore::DefineMeta ()
{
  using namespace Framework;
  using namespace std;
  // Add some type information to the reflection system
  meta_begin (int)
    meta_end ()
    meta_begin (float)
    meta_end ()
    meta_begin (double)
    meta_end ()
    meta_begin (string)
    meta_end ()

    meta_begin (Vector2)
    meta_child (Vector2, Vector2::_.x)
    meta_child (Vector2, Vector2::_.y)
    meta_end ()

    meta_begin (Vector3)
    meta_child (Vector3, Vector3::_.x)
    meta_child (Vector3, Vector3::_.y)
    meta_child (Vector3, Vector3::_.z)
    meta_end ()

    meta_begin (Vector4)
    meta_child (Vector4, Vector4::_.x)
    meta_child (Vector4, Vector4::_.y)
    meta_child (Vector4, Vector4::_.z)
    meta_child (Vector4, Vector4::_.w)
    meta_end ()

    meta_begin (Transform)
    meta_child (Transform, translation)
    meta_child (Transform, scale)
    meta_child (Transform, rotation)
    meta_end ()

    meta_begin (Sprite)
    //meta_child (Sprite, size)
    meta_end ()



}