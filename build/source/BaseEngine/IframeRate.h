/******************************************************************************/
/*!
 \file   IframeRate.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
namespace BaseEngine
{
/******************************************************************************/
/*!
 \class   pFrameRate
 \brief   pFrameRate is a private class specified in cpp file
          purpose is to encapsulate private datas not to be accessed
 Notes: 
 */
/******************************************************************************/
  struct pFrameRate;

/******************************************************************************/
/*!
 \class   IframeRate
 \brief   IframeRate control Banana Engine frame rate per second
 Notes: 
 */
/******************************************************************************/
  class IframeRate
  {
    public:
      IframeRate(); //Interface constructor
      ~IframeRate(); //Interface destructor
      void Init(double frameRate); // Initialize mFrameRate;
      void StartTime(); // Start mFrameRate timer
      void Update(); // Update mFrameRate timer, get dt, process timeElapsed

      double m_dTimeElapsed; //game time elapsed
      double m_dDt; //length of 1 frame time

    private:
      pFrameRate* _private;
  };
}