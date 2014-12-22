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

  void Mesh::Load(ShapeData* data, Shader* shader)
  {
    vao = new VAO ();

    m_posVbo = new VBO ();
    m_posVbo->UploadData (data->GetVertexBufferSize(), data->GetVertexData());
    shader->enableVertexAttribArray ("position");
    shader->vertexAttribPtr ("position", 3, 3 * sizeof (GLfloat), 0);

    m_texVbo = new VBO ();
    m_texVbo->UploadData (data->GetTexcoordBufferSize (), data->GetTexcoords ());
    shader->enableVertexAttribArray ("texcoord");
    shader->vertexAttribPtr ("texcoord", 2, 2 * sizeof (GLfloat), 0);

    ebo = new EBO ();
    ebo->UploadData (data->GetIndexBufferSize (), data->GetIndexData());

    shader->uniMat4 ("mvp", glm::value_ptr (Matrix4x4 (1)));
    shader->uni4f ("overrideColor", 1.0f, 1.0f, 1.0f, 1.0f);

    //this->vao->Unbind ();
  }

  void Mesh::Draw (Shader* shader)
  {
    shader->UseShader ();
    vao->Bind ();
    glDrawElements (GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    vao->Unbind ();
    shader->DisableShader ();
  }

}