/******************************************************************************/
/*!
 \file   FrameRate.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include "Precompiled.h"
#include "FrameRate.h"
#include "IDebugAssertion.h"

namespace Framework
{
  void frameRate::Init(double frameRate)
  {
    LARGE_INTEGER li;

      //get pc frequency
    ErrorIf(!QueryPerformanceFrequency(&li),"QueryPerformanceFrequency failed!\n");
    m_dFrequency = double(li.QuadPart);
    QueryPerformanceCounter(&li);

      //frameRate System Variant initialization
    m_dCurTime = 0.0;
    m_dPrevTime = 0.0;
    m_dFrameRate = frameRate;
    m_dInitTime = (double)li.QuadPart;
  }

  void frameRate::StartTime()
  {
    m_dPrevTime = m_dCurTime;
    m_dDt = 0.0;
  }

  void frameRate::Update()
  {
    LARGE_INTEGER li;

    while(m_dDt < 1/m_dFrameRate)
    {
      QueryPerformanceCounter(&li);
      m_dCurTime = (li.QuadPart - m_dInitTime)/ m_dFrequency;
        //delta time = time elapsed since the frame begin to end
      m_dDt = m_dCurTime - m_dPrevTime;
    }
    m_dTimeElapsed = (li.QuadPart - m_dInitTime)/ m_dFrequency;
  }

}