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
    ConsoleAllocation(EngineSettings.consoleActive);

    // Initialise GLFW
    int success = glfwInit();
    ErrorIf(!success, "Failed to initialize GLFW\n");
 
 
    // Open a window and create its OpenGL context 
    g_csEngineCore->g_glWindow = glfwCreateWindow( EngineSettings.windowsX, 
                                                   EngineSettings.windowsY,
                                                   EngineSettings.application_name.c_str() ,
                                                   NULL,
                                                   NULL); 
    ErrorIf(!g_csEngineCore->g_glWindow,"Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );

    //Initialize GLEW
    glfwMakeContextCurrent(g_csEngineCore->g_glWindow); // Initialize GLEW 
    glewExperimental=true; //@Note: No idea what this is
    success = glewInit();
    ErrorIf( success == GLEW_ERROR_GLX_VERSION_11_ONLY,  "GLEW_ERROR_GLX_VERSION_11_ONLY\n");
    ErrorIf( success == GLEW_ERROR_GL_VERSION_10_ONLY, "GLEW_ERROR_GL_VERSION_10_ONLY\n");
    ErrorIf( success == GLEW_ERROR_NO_GL_VERSION,  "GLEW_ERROR_NO_GL_VERSION\n");
    ErrorIf( success != GLEW_OK, "Failed to initialize GLEW\n");

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(g_csEngineCore->g_glWindow, GLFW_STICKY_KEYS, GL_TRUE);
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
    if(glfwWindowShouldClose(g_csEngineCore->g_glWindow))
      g_csEngineCore->g_bGameIsActive = false;

    // Swap buffers
    glfwSwapBuffers(g_csEngineCore->g_glWindow);
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