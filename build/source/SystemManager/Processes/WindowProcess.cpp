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
namespace Process
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
      std::cout << " WinMain Started" << std::endl;
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
    ConsoleAllocation(gEngineCore->settings.consoleActive);

    // Initialise GLFW
    int success = glfwInit();
    ErrorIf(!success, "Failed to initialize GLFW\n");
 
 
    // Open a window and create its OpenGL context 
    // (In the accompanying source code, this variable is global) 
    gEngineCore->g_glWindow = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL); 
    ErrorIf(!gEngineCore->g_glWindow,"Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );

    glfwMakeContextCurrent(gEngineCore->g_glWindow); // Initialize GLEW 
    glewExperimental=true; // Needed in core profile 
    success = glewInit();
    ErrorIf(success != GLEW_OK, "Failed to initialize GLEW\n");

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(gEngineCore->g_glWindow, GLFW_STICKY_KEYS, GL_TRUE);
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
    if(glfwWindowShouldClose(gEngineCore->g_glWindow))
      gEngineCore->g_bGameIsActive = false;

    // Swap buffers
    glfwSwapBuffers(gEngineCore->g_glWindow);
    glfwPollEvents();

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
}