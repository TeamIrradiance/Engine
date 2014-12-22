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
#pragma once


/******************************************************************************/
/*!
 \class   TemplateProcess
 \brief   Template to write other child processes
 Notes: Derived class ust have  Constructor with param:
 */
/******************************************************************************/
namespace Framework
{
  class WindowProcess : public Framework::CProcess
  {
  public:
    void VUpdate(const double dt);
    void VInit();
    WindowProcess();
    ~WindowProcess();

  private:
    bool Create_Context ();
    bool Init_Glew ();

  };
}