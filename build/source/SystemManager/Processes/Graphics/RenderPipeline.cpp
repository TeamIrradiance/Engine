/******************************************************************************/
/*!
\file   Pipeline.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief  Template for all proces classes
*/
/******************************************************************************/

#include <Precompiled.h>

namespace Framework
{
  RenderPipeline* G_RENDER;
  Mesh* mesh = new Mesh ();
  Shader* shader;

  RenderPipeline::RenderPipeline ()
  {
    G_RENDER = this;
    glClearColor (m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);

    ShapeData data = ShapeGenerator::Generate_Quad ();
    shader = static_cast <Shader*> (ResourceManager::LoadResource ("Sprite", R_SHADER));
    mesh->Load (&data, shader);
  }

  RenderPipeline::~RenderPipeline ()
  {
    G_RENDER = nullptr;
  }

  void RenderPipeline::Draw ()
  {
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    mesh->Draw (shader);
  }

}