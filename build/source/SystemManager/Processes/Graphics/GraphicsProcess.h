/******************************************************************************/
/*!
 \file   GraphicsProcess.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once


/******************************************************************************/
/*!
 \class   GraphicsProcess
 \brief   Process graphics datas
 */
/******************************************************************************/
namespace Framework
{
  class GraphicsProcess : public Framework::CProcess
  {
  public:
    void VUpdate(const double dt);
    void VInit();
    GraphicsProcess();
    ~GraphicsProcess();
  };
}