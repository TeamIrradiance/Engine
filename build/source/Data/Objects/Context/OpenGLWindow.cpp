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


  OpenGLWindow::OpenGLWindow ()
  {

  }

  OpenGLWindow::~OpenGLWindow ()
  {
    glfwTerminate ();
  }

  void OpenGLWindow::Create_Context(int w, int h, const char* wName)
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
  }

  void OpenGLWindow::Viewport (int x, int y, int w, int h)
  {
    glViewport (x, y, w, h);
  }

  void OpenGLWindow::SwapBuffers ()
  {
    glfwSwapBuffers (m_window);
  }

  void OpenGLWindow::Resize (int w, int h)
  {
    glViewport (0, 0, w, h);
  }

  void OpenGLWindow::ResizeFrameBuffer (int w, int h)
  {
  }

  GLFWwindow* OpenGLWindow::GetWindow ()
  {
    return m_window;
  }

  int OpenGLWindow::GetWindowWidth ()
  {
    return m_width;
  }

  int OpenGLWindow::GetWindowHeight ()
  {
    return m_height;
  }

  Vector2 OpenGLWindow::GetMousePosition ()
  {
    return m_mousePosition;
  }

}