/******************************************************************************/
/*!
\file   EngineWindow.cpp
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#include <Precompiled.h>

namespace Framework
{

  GLContext::GLContext ()
  {

  }

  GLContext::~GLContext ()
  {
    glfwTerminate ();
  }

  void GLContext::Create_Context(int w, int h, const char* wName)
  {
    // Initialise GLFW
    int success = glfwInit ();
    ErrorIf (!success, "Failed to initialize GLFW\n");


    // Open a window and create its OpenGL context 
    GLFWmonitor* monitor = glfwGetPrimaryMonitor ();
    m_window = glfwCreateWindow (w, h, wName, nullptr, nullptr);
    ErrorIf (!m_window, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");

    //Initialize GLFW
    glfwMakeContextCurrent (m_window); // Initialize GLFW 

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode (m_window, GLFW_STICKY_KEYS, GL_TRUE);

    glfwSetWindowSizeCallback (m_window, (GLContext::GLWindowResizeCallBack));
    glfwSetFramebufferSizeCallback (m_window, (GLContext::GLFrameBufferResizeCallback));
    glfwSetCursorPosCallback (m_window, (GLContext::GLMouseCursorPosCallBack));

  }

  void GLContext::Viewport (int x, int y, int w, int h)
  {
    glViewport (x, y, w, h);
  }

  void GLContext::SwapBuffers ()
  {
    glfwSwapBuffers (m_window);
  }

  void GLContext::Resize (int w, int h)
  {
    glViewport (0, 0, w, h);
  }

  void GLContext::ResizeFrameBuffer (int w, int h)
  {
  }

  GLFWwindow* GLContext::GetWindow ()
  {
    return m_window;
  }

  int GLContext::GetWindowWidth ()
  {
    return m_width;
  }

  int GLContext::GetWindowHeight ()
  {
    return m_height;
  }

  Vector2 GLContext::GetMousePosition ()
  {
    return m_mousePosition;
  }

  void GLContext::GLWindowResizeCallBack (GLFWwindow* wnd, const int w, const int h)
  {
    glViewport (0, 0, w, h);
  }

  void GLContext::GLFrameBufferResizeCallback (GLFWwindow* wnd, const int w, const int h)
  {

  }

  void GLContext::GLMouseCursorPosCallBack (GLFWwindow* wnd, double x, double y)
  {
    g_csEngineCore->g_glWindow.m_mousePosition = Vector2 (x, y);
  }

}