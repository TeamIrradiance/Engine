/******************************************************************************/
/*!
 \file   TemplateProcess.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
//////////////////////////////////////////////////////////////////////////////
// DO NOT WRITE TEMPELATE FILES FOR ACTUAL CODE
//////////////////////////////////////////////////////////////////////////////
#include "IBaseEngine.h"
#include "Precompiled.h"
/******************************************************************************/
/*!
 \class   TemplateProcess
 \brief   Template to write other child processes
 Notes: Derived class ust have  Constructor with param:
 */
/******************************************************************************/
namespace Process
{
  class WindowProcess : public BaseEngine::CProcess
  {
  public:
    void VUpdate(const double dt);
    void VInit();
    WindowProcess();
    ~WindowProcess();
  };
}