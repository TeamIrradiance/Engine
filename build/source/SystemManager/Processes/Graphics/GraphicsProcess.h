/******************************************************************************/
/*!
 \file   GraphicsProcess.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include "IBaseEngine.h"
#include "Precompiled.h"
/******************************************************************************/
/*!
 \class   GraphicsProcess
 \brief   Process graphics datas
 */
/******************************************************************************/
namespace Process
{
  class GraphicsProcess : public BaseEngine::CProcess
  {
  public:
    void VUpdate(const double dt);
    void VInit();
    GraphicsProcess();
    ~GraphicsProcess();
  };
}