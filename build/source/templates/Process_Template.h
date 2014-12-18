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
        - string name
        - set m_bKill = false
        - set m_bActive = true
        - set m_bInitialized = false
        - set m_bAttached = false
 */
/******************************************************************************/
namespace Process
{
  class TemplateProcess : public BaseEngine::CProcess
  {
  public:
    void VUpdate(const double dt);
    void VInit();
    TemplateProcess();
    ~TemplateProcess();
  };
}