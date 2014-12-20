/******************************************************************************/
/*!
\file   RenderPipeline.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief  Template for all proces classes
*/
/******************************************************************************/

#pragma once

namespace Framework
{
  class RenderPipeline
  {
  public:
    RenderPipeline ();
    ~RenderPipeline ();

    void Draw ();


    // 16 BYTE ALIGNMENT TO AVOID ACCESS VIOLATION
    void* operator new (size_t i)
    {
      return _mm_malloc (i, 16);
    }

    void operator delete (void* p)
    {
      _mm_free (p);
    }

  private:
    Vector4 m_clearColor;
  };

  extern RenderPipeline* G_RENDER;
}