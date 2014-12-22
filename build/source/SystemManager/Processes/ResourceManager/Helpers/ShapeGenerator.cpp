/******************************************************************************/
/*!
 \file   ShapeGenerator.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/

#include <Precompiled.h>
#include "Shader.h"

namespace Framework
{
/******************************************************************************/
/*!
\fn      ShapeGenerator()
\brief   Default constructor
*/
/******************************************************************************/
  ShapeGenerator::ShapeGenerator()
  {
  }

/******************************************************************************/
/*!
\fn   ~ShapeGenerator()
\brief   destructor
*/
/******************************************************************************/
  ShapeGenerator::~ShapeGenerator()
  {
  }

  void ShapeGenerator::Generate_Triangle (Mesh* mesh)
  {
    std::vector <float> vertices;

    vertices.push_back (0);
    vertices.push_back (1);
    vertices.push_back (0);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);

    vertices.push_back (-1);
    vertices.push_back (-1);
    vertices.push_back (0);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);

    vertices.push_back (1);
    vertices.push_back (-1);
    vertices.push_back (0);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);

    mesh->vbo->AddData (vertices.data (), vertices.size ());
    mesh->vbo->UploadData ();
  }

  void ShapeGenerator::Generate_Quad(Mesh* mesh)
  {
    std::vector <float> vertices;
    std::vector <unsigned> indices;

    // VERTEX
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (0);
    // COLOR
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    // TEXCOORD
    vertices.push_back (1);
    vertices.push_back (0);
    // VERTEX
    vertices.push_back (-1);
    vertices.push_back (1);
    vertices.push_back (0);
    // COLOR
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    // TEXCOORD
    vertices.push_back (0);
    vertices.push_back (0);
    // VERTEX
    vertices.push_back (-1);
    vertices.push_back (-1);
    vertices.push_back (0);
    // COLOR
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    // TEXCOORD
    vertices.push_back (0);
    vertices.push_back (1);
    // VERTEX
    vertices.push_back (1);
    vertices.push_back (-1);
    vertices.push_back (0);
    // COLOR
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    vertices.push_back (1);
    // TEXCOORD
    vertices.push_back (1);
    vertices.push_back (1);

    indices.push_back (0);
    indices.push_back (1);
    indices.push_back (2);

    indices.push_back (2);
    indices.push_back (3);
    indices.push_back (0);

    mesh->vbo->AddData (vertices.data (), vertices.size ());
    mesh->ebo->AddData ((GLfloat*)(indices.data ()), indices.size ());
    mesh->vbo->UploadData ();
    mesh->ebo->UploadData ();

    //Shader* shader = reinterpret_cast<ResourceManager*> (g_csEngineCore->g_csProcessManager->getProcess ("resources"))->Get_Shader ("Default");
    ////shader->Use ();

    //shader->enableVertexAttribArray (shader->attribLocation ("position"));
    //shader->vertexAttribPtr ("position", 3, GL_FLOAT, GL_FALSE, 9 * sizeof (GLfloat), 0);

    //shader->enableVertexAttribArray (shader->attribLocation ("color"));
    //shader->vertexAttribPtr ("color", 4, GL_FLOAT, GL_FALSE, 9 * sizeof (GLfloat), 3 * sizeof (GLfloat));

    //shader->enableVertexAttribArray (shader->attribLocation ("texcoord"));
    //shader->vertexAttribPtr ("texcoord", 2, GL_FLOAT, GL_FALSE, 9 * sizeof (GLfloat), 7 * sizeof (GLfloat));

    ////shader->Disable ();
    //mesh->vao->Unbind ();
  }

  void ShapeGenerator::Generate_Circle(Mesh* mesh)
  {

  }

  void ShapeGenerator::Generate_Cube(Mesh* mesh)
  {

  }

}