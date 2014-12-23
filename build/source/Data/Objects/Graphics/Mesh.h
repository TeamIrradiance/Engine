/******************************************************************************/
/*!
 \file   Mesh.h
 \author Manas Sudhir Kulkarni
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/

#pragma once

namespace Framework
{
  enum MESH_TYPE
  {
    MESH_TRIANGLE = 0,
    MESH_QUAD,
    MESH_CUBE,
    MESH_CIRCLE,

    MESH_INSTANCE_TRIANGLE,
    MESH_INSTANCE_QUAD,
    MESH_INSTANCE_CUBE,
    MESH_INSTANCE_CIRCLE,
  };


/******************************************************************************/
/*!
 \class   sampleComponent
 \brief   sampleComponent Component
 Notes: 
 */
/******************************************************************************/

  class Mesh: public IData
  {
  public:
    Mesh();
    virtual ~Mesh();

    void DefineMeta();
    void Load (ShapeData* data, Shader* shader);
    virtual void Draw (Shader* shader);
    virtual void DrawInstanced (Shader* shader, unsigned instCount);

  protected:
    //DATAS
    VAO* m_vao;
    VBO* m_posVbo;
    VBO* m_texVbo;
    EBO* m_indexBuffer;
  };


  class SpriteMesh : public Mesh
  {

  public:
    SpriteMesh ();
    ~SpriteMesh ();
    virtual void DrawInstanced (Shader* shader, unsigned instCount);

    VBO const* CreateSprite (Shader* shader);

  private:
    //DATAS
    VBO* m_matrixVbo;

  };
}