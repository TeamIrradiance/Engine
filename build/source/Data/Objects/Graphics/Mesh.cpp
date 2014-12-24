/******************************************************************************/
/*!
 \file   Mesh.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>

namespace Framework
{
/******************************************************************************/
/*!
\fn      Mesh()
\brief   Default constructor
*/
/******************************************************************************/
  Mesh::Mesh()
  {
  }

/******************************************************************************/
/*!
\fn   ~Mesh()
\brief   destructor
*/
/******************************************************************************/
  Mesh::~Mesh()
  {
    delete m_vao;
    delete m_posVbo;
    delete m_texVbo;
    delete m_indexBuffer;
  }

/******************************************************************************/
/*!s
\fn   DefineMeta()
\brief   define meta here
*/
/******************************************************************************/
  void Mesh::DefineMeta()
  {
  }

  /*************************************************************************/
  // Method:    Load
  // FullName:  Framework::Mesh::Load
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: ShapeData * data
  // Parameter: Shader * shader
  // Brief: Upload Input Shape To GPU
  /*************************************************************************/
  void Mesh::Load (ShapeData* data, Shader* shader)
  {
    m_vao = new VAO ();

    m_posVbo = new VBO ();
    m_posVbo->UploadData (data->GetVertexBufferSize(), data->GetVertexData());
    shader->enableVertexAttribArray ("position");
    shader->vertexAttribPtr ("position", 3, 3 * sizeof (GLfloat), 0);

    m_texVbo = new VBO ();
    m_texVbo->UploadData (data->GetTexcoordBufferSize (), data->GetTexcoords ());
    shader->enableVertexAttribArray ("texcoord");
    shader->vertexAttribPtr ("texcoord", 2, 2 * sizeof (GLfloat), 0);

    m_indexBuffer = new EBO ();
    m_indexBuffer->UploadData (data->GetIndexBufferSize (), data->GetIndexData());

    shader->uniMat4 ("mvp", glm::value_ptr (Matrix4x4 (1)));
    shader->uni4f ("overrideColor", 1.0f, 1.0f, 1.0f, 1.0f);

    m_vao->Unbind ();
  }

  /*************************************************************************/
  // Method:    Draw
  // FullName:  Framework::Mesh::Draw
  // Access:    virtual public 
  // Returns:   void
  // Qualifier:
  // Parameter: Shader * shader
  // Brief: Draw The Uploaded Primitive using Input Shader
  /*************************************************************************/
  void Mesh::Draw (Shader* shader)
  {
    shader->UseShader ();
    m_vao->Bind ();
    glDrawElements (GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    m_vao->Unbind ();
    shader->DisableShader ();
  }

  /*************************************************************************/
  // Method:    DrawInstanced
  // FullName:  Framework::Mesh::DrawInstanced
  // Access:    virtual public 
  // Returns:   void
  // Qualifier:
  // Parameter: Shader * shader
  // Parameter: unsigned instCount
  // Brief: Instance Render the Uploaded Primitive using given Shader
  /*************************************************************************/
  void Mesh::DrawInstanced (Shader* shader, unsigned instCount)
  {
    shader->UseShader ();
    m_vao->Bind ();
    glDrawElementsInstanced (GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, instCount);
    m_vao->Unbind ();
    shader->DisableShader ();
  }

  //////////////////////////////////////////////////////////////////////////
  // DERIVED MESH CLASSES
  //////////////////////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////////////////////
  // SPRITE
  //////////////////////////////////////////////////////////////////////////

  SpriteMesh::SpriteMesh ()
  {}

  SpriteMesh::~SpriteMesh ()
  {
    delete m_matrixVbo;
  }

  /*************************************************************************/
  // Method:    DrawInstanced
  // FullName:  Framework::SpriteMesh::DrawInstanced
  // Access:    virtual public 
  // Returns:   void
  // Qualifier:
  // Parameter: Shader * shader
  // Parameter: unsigned instCount
  // Brief: Instance Render Sprite using given Shader
  /*************************************************************************/
  void SpriteMesh::DrawInstanced (Shader* shader, unsigned instCount)
  {
    shader->UseShader ();
    m_vao->Bind ();

    m_matrixVbo->UploadData <float> (GL_DYNAMIC_DRAW);
    glDrawElementsInstanced (GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, instCount);

    m_vao->Unbind ();
    shader->DisableShader ();
  }

  /*************************************************************************/
  // Method:    CreateSprite
  // FullName:  Framework::SpriteMesh::CreateSprite
  // Access:    public 
  // Returns:   VBO const*
  // Qualifier:
  // Parameter: Shader * shader
  // Brief: Create a Sprite Primitive. Generate Matrix and Texcoord Buffer
  /*************************************************************************/
  VBO const* SpriteMesh::CreateSprite (Shader* shader)
  {
    m_vao = new VAO ();
    ShapeData data = ShapeGenerator::Generate_Quad ();
    Load (&data, shader);

    m_vao->Bind ();
    m_matrixVbo = new VBO ();

    GLuint location = shader->attribLocation ("modelMatrix");
    GLint components = 4;
    GLenum type = GL_FLOAT;
    GLboolean normalized = GL_FALSE;
    GLsizei datasize = sizeof(Matrix4x4);
    char* pointer = 0;
    GLuint divisor = 1;

    /**
    Matrix:
    float mat[16] =
    {
    1, 0, 0, 0, //first column:  location at 0 + 0 * sizeof( vec4 ) bytes into the matrix
    0, 1, 0, 0, //second column: location at 0 + 1 * sizeof( vec4 ) bytes into the matrix
    0, 0, 1, 0, //third column:  location at 0 + 2 * sizeof( vec4 ) bytes into the matrix
    0, 0, 0, 1  //fourth column  location at 0 + 3 * sizeof( vec4 ) bytes into the matrix
    };
    /**/

    for (int c = 0; c < 4; ++c)
    {
      glEnableVertexAttribArray (location + c); //location of each column
      glVertexAttribPointer (location + c, components, type, normalized, datasize, pointer + c * sizeof(Vector4)); //tell other data
      glVertexAttribDivisor (location + c, divisor); //is it instanced?
    }

    shader->uniMat4 ("mvp", glm::value_ptr (Matrix4x4 (1)));
    shader->uni4f ("overrideColor", 1.0f, 1.0f, 1.0f, 1.0f);

    return m_matrixVbo;
  }

}