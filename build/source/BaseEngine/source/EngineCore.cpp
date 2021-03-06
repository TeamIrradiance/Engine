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
#include "Sprite.h"


EngineCore* G_CORE = 0;
/******************************************************************************/
/*!
\class   EngineCore()
\brief   Constructor
*/
/******************************************************************************/
EngineCore::EngineCore ()
{
  ErrorIf (G_CORE != 0, "Engine is created!");
  G_CORE = this;

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
    G_CONTEXT.SwapBuffers ();
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
    meta_begin (char)
    meta_end ()
    meta_begin (float)
    meta_end ()
    meta_begin (double)
    meta_end ()
    meta_begin (string)
    meta_end ()

    meta_begin (Vector2)
    meta_child (Vector2, x)
    meta_child (Vector2, y)
    meta_end ()

    meta_begin (Vector3)
    meta_child (Vector3, x)
    meta_child (Vector3, y)
    meta_child (Vector3, z)
    meta_end ()

    meta_begin (Vector4)
    meta_child (Vector4, x)
    meta_child (Vector4, y)
    meta_child (Vector4, z)
    meta_child (Vector4, w)
    meta_end ()

    meta_begin (Transform)
    meta_child (Transform, position)
    meta_child (Transform, scale)
    meta_child (Transform, rotation)
    meta_end ()

    meta_begin (Texcoord)
    meta_child (Texcoord, nw)
    meta_child (Texcoord, sw)
    meta_child (Texcoord, se)
    meta_child (Texcoord, ne)
    meta_end ()

    //////////////////////////////////////////////////////////////////////////
    meta_begin (Texture)
    meta_child (Texture, Name)
    meta_child (Texture, AtlasName)
    meta_child (Texture, Texcoords)
    meta_end ()
    //////////////////////////////////////////////////////////////////////////

    meta_begin (Sprite)
    meta_child (Sprite, SpriteSource)
    meta_child (Sprite, Color)
    meta_end ()



}