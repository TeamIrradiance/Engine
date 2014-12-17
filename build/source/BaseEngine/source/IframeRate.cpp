/******************************************************************************/
/*!
 \file   IframeRate.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include "Precompiled.h"
#include "IBaseEngine.h"
#include "FrameRate.h"
namespace BaseEngine
{
  struct pFrameRate
  {
    BaseEngine::frameRate frameRate;
  };

    // Initialize mFrameRate;
  void IframeRate::Init(double frameRate)
  {
    _private->frameRate.Init(frameRate);
  }

    // Start mFrameRate timer
  void IframeRate::StartTime()
  {
    _private->frameRate.StartTime();
  }

    // Update mFrameRate timer, get dt, process timeElapsed
  void IframeRate::Update()
  {
    _private->frameRate.Update();
    //  // update public dt value
    m_dDt= _private->frameRate.m_dDt;
     // update public timeElapsed value
    m_dTimeElapsed = _private->frameRate.m_dTimeElapsed;
  }

  IframeRate::IframeRate(void)
  {
    _private = new pFrameRate;
    gEngineCore->g_csFramerateControl = this;
    m_dDt = 0.f;
  }

  IframeRate::~IframeRate(void)
  {
    delete _private;
  }
}