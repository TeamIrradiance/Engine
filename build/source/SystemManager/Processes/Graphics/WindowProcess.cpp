/******************************************************************************/
/*!
 \file   WindowProcess.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include "WindowProcess.h"
namespace Framework
{
/******************************************************************************/
/*!
 \fn   ConsoleAllocation
 \brief   helper function, pack console allocation checking in a function,
          just to make it clean
 */
/******************************************************************************/
  void ConsoleAllocation(bool b)
  {
    if(b)
    {
      FILE *stream;

      AllocConsole();
      freopen_s( &stream,"CONOUT$", "w", stdout);
      std::cout << "WinMain Started" << std::endl;
    }
  }

/******************************************************************************/
/*!
 \class   WindowProcess::VInit()
 \brief   Virtual function of init. It will be called together with other 
          existing processes that inherit from CProcess class
 */
/******************************************************************************/
  void WindowProcess::VInit()
  {
  }

  
/******************************************************************************/
/*!
 \class   WindowProcess::VUpdate(double)
 \brief   Virtual function of init. It will be called together with other 
          existing processes that inherit from CProcess class
 */
/******************************************************************************/
  void WindowProcess::VUpdate(double dt)
  {
    //glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS
    if(glfwWindowShouldClose(g_csEngineCore->g_glWindow.GetWindow()))
      g_csEngineCore->g_bGameIsActive = false;

    // Swap buffers
    glfwPollEvents ();
  }

/******************************************************************************/
/*!
 \class   WindowProcess::WindowProcess()
 \brief   Default constructor of window process;

 */
/******************************************************************************/
  WindowProcess::WindowProcess()
  {
    std::hash<std::string> id;
    mName = std::string("window");
    mProcessID = id(mName); //faster access with hash instead of string
    m_bActive = true; // skip when process is deactivated
    m_bInitialized = false; //debugging purposes if initialized
    m_bAttached = false; // check if process is attached to manager

    ConsoleAllocation (EngineSettings.consoleActive);
    Create_Context ();
    Init_Glew ();
  }

/******************************************************************************/
/*!
 \class   WindowProcess::~WindowProcess()
 \brief   Destructor;
 */
/******************************************************************************/
  WindowProcess::~WindowProcess()
  {

  }

  bool WindowProcess::Create_Context ()
  {
    g_csEngineCore->g_glWindow.Create_Context
      (
      EngineSettings.windowsX,
      EngineSettings.windowsY,
      EngineSettings.application_name.c_str ()
      );

    return true;
  }

  bool WindowProcess::Init_Glew ()
  {
    // Expose All Extensions
    glewExperimental = true;

    int success = glewInit ();
    ErrorIf (success == GLEW_ERROR_GLX_VERSION_11_ONLY, "GLEW_ERROR_GLX_VERSION_11_ONLY\n");
    ErrorIf (success == GLEW_ERROR_GL_VERSION_10_ONLY, "GLEW_ERROR_GL_VERSION_10_ONLY\n");
    ErrorIf (success == GLEW_ERROR_NO_GL_VERSION, "GLEW_ERROR_NO_GL_VERSION\n");
    ErrorIf (success != GLEW_OK, "Failed to initialize GLEW\n");

    std::cout << "OpenGL Version " << glGetString (GL_VERSION) << std::endl;
    std::cout << "OpenGL Vendor "  << glGetString (GL_VENDOR)  << std::endl;

    return true;
  }

}