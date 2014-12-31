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
  static Vector2 m_mouseOffset;

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
    m_width = w;
    m_height = h;
    Viewport (0, 0, w, h);
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
    if (m_width != w)
    {
      int aspectHeight = (int) (w / (16.0f / 9.0f));
      m_width = w;
      m_height = aspectHeight;
      Viewport (0, 0, w, aspectHeight);
      //WINDOWSYSTEM->Set_W_H (w, aspectHeight);
      if (h < aspectHeight)
      {
        m_mouseOffset.y = float (aspectHeight - h);
      }
      else
      {
        m_mouseOffset.y = 0.0f;
      }
    }
    else if (m_height != h)
    {
      int aspectWidth = (int) (h * (16.0f / 9.0f));
      m_width = aspectWidth;
      m_height = h;
      Viewport (0, 0, aspectWidth, h);
      //WINDOWSYSTEM->Set_W_H (aspectWidth, h);
      if (w < aspectWidth)
      {
        m_mouseOffset.x = float (aspectWidth - w);
      }
      else
      {
        m_mouseOffset.x = 0.0f;
      }
    }
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
    G_CORE->G_CONTEXT.Resize (w, h);
  }

  void GLContext::GLFrameBufferResizeCallback (GLFWwindow* wnd, const int w, const int h)
  {

  }

  void GLContext::GLMouseCursorPosCallBack (GLFWwindow* wnd, double x, double y)
  {
    G_CORE->G_CONTEXT.m_mousePosition = Vector2 (x + m_mouseOffset.x, y + m_mouseOffset.y);
  }

}