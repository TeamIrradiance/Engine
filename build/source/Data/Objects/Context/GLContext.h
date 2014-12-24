/******************************************************************************/
/*!
\file   EngineWindow.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#pragma once

#include "MathLib.h"

namespace Framework
{
  class GLContext
  {
  public:
    GLContext ();
    ~GLContext ();

    void Create_Context (int w, int h, const char* wName);
    void Viewport (int x, int y, int w, int h);
    void SwapBuffers ();
    void Resize (int w, int h);
    void ResizeFrameBuffer (int w, int h);
    void RenameWindow (const char* wName);

    GLFWwindow* GetWindow ();
    int GetWindowWidth ();
    int GetWindowHeight ();
    Vector2 GetMousePosition ();

  private:
    static void GLFrameBufferResizeCallback (GLFWwindow* wnd, const int w, const int h);
    static void GLWindowResizeCallBack (GLFWwindow* wnd, const int w, const int h);
    static void GLMouseCursorPosCallBack (GLFWwindow* wnd, double x, double y);

    GLFWwindow* m_window;
    int m_width;
    int m_height;

    Vector2 m_mousePosition;
  };
}