/******************************************************************************/
/*!
\file   BufferObjects.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#pragma once

namespace Framework
{
  //////////////////////////////////////////////////////////////////////////
  // VAO
  //////////////////////////////////////////////////////////////////////////

  class VertexArrayObject
  {
  public:
    VertexArrayObject ();
    ~VertexArrayObject ();

    void Bind ();
    void Unbind ();

    GLuint Get_Location ();

  private:
    GLuint m_vertexArrayLocation;
  };


  //////////////////////////////////////////////////////////////////////////
  // BASE BUFFER CLASS
  //////////////////////////////////////////////////////////////////////////

  template <typename T>
  class BufferObject
  {
  public:

    BufferObject ()
    {
      m_data.clear ();
    }

    ~BufferObject ()
    {
      glDeleteBuffers (1, &m_bufferLocation);
    }

    template <typename T = float>
    void Bind ()
    {
      glBindBuffer (m_bufferType, m_bufferLocation);
    }

    template <typename T = float>
    void Unbind ()
    {
      glBindBuffer (m_bufferType, 0);
    }

    template <typename T = float>
    void UploadData (GLenum usage = GL_STATIC_DRAW)
    {
      glBufferData (m_bufferType, 0, m_data.data (), usage);
      m_data.clear ();
    }

    template <typename T = float>
    void AddData (GLfloat* data, GLuint size)
    {
      m_data.insert (m_data.end (), data, data + size);
    }

    template <typename T = float>
    GLenum Get_Type ()
    {
      return m_bufferType;
    }

    template <typename T = float>
    GLuint Get_Location ()
    {
      return m_bufferLocation;
    }

  protected:
    std::vector <T> m_data;
    GLenum m_bufferType;
    GLuint m_bufferLocation;
  };


  //////////////////////////////////////////////////////////////////////////
  // DERIVED CLASSES
  //////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////
  // VBO
  //////////////////////////////////////////////////////////////////////////

  class VertexBufferObject : public BufferObject <float>
  {
  public:
    VertexBufferObject ();
    ~VertexBufferObject ();
  };

  //////////////////////////////////////////////////////////////////////////
  // EBO
  //////////////////////////////////////////////////////////////////////////

  class ElementBufferObject : public BufferObject <unsigned>
  {
  public:
    ElementBufferObject ();
    ~ElementBufferObject ();
  };

  //////////////////////////////////////////////////////////////////////////
  // FBO
  //////////////////////////////////////////////////////////////////////////

  class FrameBufferObject : public BufferObject <unsigned>
  {
  public:
    FrameBufferObject ();
    ~FrameBufferObject ();
  };

  //////////////////////////////////////////////////////////////////////////
  // SSBO
  //////////////////////////////////////////////////////////////////////////

  class ShaderStorageBufferObject : public BufferObject <unsigned>
  {
  public:
    ShaderStorageBufferObject ();
    ~ShaderStorageBufferObject ();
  };

  typedef VertexArrayObject VAO;
  typedef VertexBufferObject VBO;
  typedef ElementBufferObject EBO;
  typedef FrameBufferObject FBO;
  typedef ShaderStorageBufferObject SSBO;
}