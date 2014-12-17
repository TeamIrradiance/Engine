/******************************************************************************/
/*!
 \file   FrameRate.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once

/******************************************************************************/
/*!
 \class   frameRate
 \brief   frame rate manager managing game fps

 */
/******************************************************************************/
namespace BaseEngine
{
  class frameRate
  {
    friend class IframeRate;
    public:
      void Init(double frameRate);
      void StartTime();
      void Update();

  private:
      // current frame elpased time
    double m_dCurTime;
      // previous frame end time
    double m_dPrevTime;
      // the intended frame rate
    double m_dFrameRate;
      // Value specific to each machine, get value using a system call QueryPerformanceFrequency().
    double m_dFrequency;
      // time stemp when program is started
    double m_dInitTime;
        //game time elapsed
    double m_dTimeElapsed;
      //length of 1 frame time
    double m_dDt;
  };

}

