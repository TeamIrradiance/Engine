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
      glGenBuffers (1, &m_bufferLocation);
      glBindBuffer (m_bufferType, m_bufferLocation);
      m_data.clear ();
    }

    virtual ~BufferObject ()
    {
      glDeleteBuffers (1, &m_bufferLocation);
    }

    template <typename T>
    void Bind ()
    {
      glBindBuffer (m_bufferType, m_bufferLocation);
    }

    template <typename T>
    void Unbind ()
    {
      glBindBuffer (m_bufferType, 0);
    }

    template <typename T>
    void UploadData (GLenum usage = GL_STATIC_DRAW)
    {
      Bind <T>();
      glBufferData (m_bufferType, m_data.size() * sizeof T, m_data.data (), usage);
      //m_data.clear ();
    }

    template <typename T>
    void UploadData (GLuint bufferSize, T* bufferData, GLenum mode = GL_STATIC_DRAW)
    {
      glBufferData (m_bufferType, bufferSize, bufferData, mode);
    }

    template <typename T>
    void AddData (T* data, GLuint size)
    {
      m_data.insert (m_data.end (), data, data + size);
    }

    template <typename T>
    void UpdateData (T* data, GLuint index, GLuint size = 1)
    {
      for (unsigned i = index * size; i < (index * size + size); ++i)
      {
        m_data.at (i) = data [i];
      }
    }

    void UpdateMatrixData (Matrix4x4& data, GLuint index, GLuint size = 1)
    {
      m_data [index * size]       = data [0][0];
      m_data [index * size + 1]   = data [0][1];
      m_data [index * size + 2]   = data [0][2];
      m_data [index * size + 3]   = data [0][3];

      m_data [index * size + 4]   = data [1][0];
      m_data [index * size + 5]   = data [1][1];
      m_data [index * size + 6]   = data [1][2];
      m_data [index * size + 7]   = data [1][3];

      m_data [index * size + 8]   = data [2][0];
      m_data [index * size + 9]   = data [2][1];
      m_data [index * size + 10]  = data [2][2];
      m_data [index * size + 11]  = data [2][3];

      m_data [index * size + 12]  = data [3][0];
      m_data [index * size + 13]  = data [3][1];
      m_data [index * size + 14]  = data [3][2];
      m_data [index * size + 15]  = data [3][3];
    }

    template <typename T>
    GLenum Get_Type ()
    {
      return m_bufferType;
    }

    template <typename T>
    GLuint Get_Location ()
    {
      return m_bufferLocation;
    }

    std::vector <T>& Get_Data ()
    {
      return m_data;
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
  };

  //////////////////////////////////////////////////////////////////////////
  // EBO
  //////////////////////////////////////////////////////////////////////////

  class ElementBufferObject : public BufferObject <unsigned>
  {
  public:
    ElementBufferObject ();
  };

  //////////////////////////////////////////////////////////////////////////
  // FBO
  //////////////////////////////////////////////////////////////////////////

  class FrameBufferObject : public BufferObject <unsigned>
  {
  public:
    FrameBufferObject ();
  };

  //////////////////////////////////////////////////////////////////////////
  // SSBO
  //////////////////////////////////////////////////////////////////////////

  class ShaderStorageBufferObject : public BufferObject <unsigned>
  {
  public:
    ShaderStorageBufferObject ();
  };

  typedef VertexArrayObject VAO;
  typedef VertexBufferObject VBO;
  typedef ElementBufferObject EBO;
  typedef FrameBufferObject FBO;
  typedef ShaderStorageBufferObject SSBO;
}