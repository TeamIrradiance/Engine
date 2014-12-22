/******************************************************************************/
/*!
\file   ShapeData.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#pragma once

namespace Framework
{

  struct ShapeData
  {
  public:
    ShapeData ();

    void Vertex2f (float x, float y)
    {
      m_vertices.push_back (x);
      m_vertices.push_back (y);
      m_vertices.push_back (0);

      ++m_numVertices;
    }

    void Vertex2fv (const float* v)
    {
      m_vertices.push_back (v [0]);
      m_vertices.push_back (v [1]);
      m_vertices.push_back (0);

      ++m_numVertices;
    }

    void Vertex3f (float x, float y, float z)
    {
      m_vertices.push_back (x);
      m_vertices.push_back (y);
      m_vertices.push_back (z);

      ++m_numVertices;
    }

    void Vertex3fv (const float* v)
    {
      m_vertices.push_back (v [0]);
      m_vertices.push_back (v [1]);
      m_vertices.push_back (v [2]);

      ++m_numVertices;
    }

    void Texcoord1f (float s)
    {
      m_texcoords.push_back (s);
      m_texcoords.push_back (0);
    }

    void Texcoord2f (float s, float t)
    {
      m_texcoords.push_back (s);
      m_texcoords.push_back (t);
    }

    void Color4f (float r, float g, float b, float a);
    void Normal2f (float x, float y, float z);

    void Index3f (unsigned i1, unsigned i2, unsigned i3)
    {
      m_indices.push_back (i1);
      m_indices.push_back (i2);
      m_indices.push_back (i3);

      ++m_numIndices;
    }

    void Clean ()
    {
      m_vertices.clear ();
      m_indices.clear ();
    }

    GLuint GetVertexBufferSize ()
    {
      return m_numVertices * sizeof (Vector3);
    }

    GLuint GetTexcoordBufferSize ()
    {
      return m_numVertices * sizeof (Vector2);
    }

    GLuint GetIndexBufferSize ()
    {
      return m_numIndices * sizeof (Vector3);
    }

    float* GetVertexData ()
    {
      return m_vertices.data ();
    }

    float* GetTexcoords ()
    {
      return m_texcoords.data();
    }

    unsigned* GetIndexData ()
    {
      return m_indices.data ();
    }

  private:
    std::vector <float> m_vertices;
    std::vector <unsigned> m_indices;
    std::vector <float> m_texcoords;

    unsigned m_numVertices;
    unsigned m_numIndices;
  };

}