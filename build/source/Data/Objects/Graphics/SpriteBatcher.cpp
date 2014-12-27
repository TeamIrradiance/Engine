/******************************************************************************/
/*!
\file   SpriteBatcher.cpp
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#include <Precompiled.h>
#include "Mesh.h"
#include "BufferObjects.h"
#include "Sprite.h"

namespace Framework
{
  std::unordered_map <std::string, std::list <Sprite*>> SpriteBatcher::m_spriteList;

  /*************************************************************************/
  // Method:    SpriteBatcher
  // FullName:  Framework::SpriteBatcher::SpriteBatcher
  // Access:    public 
  // Returns:   
  // Qualifier:
  // Brief: Constructor
  /*************************************************************************/
  SpriteBatcher::SpriteBatcher ()
  {
    m_spriteList.clear ();
    m_dataReady = true;
  }

  /*************************************************************************/
  // Method:    ~SpriteBatcher
  // FullName:  Framework::SpriteBatcher::~SpriteBatcher
  // Access:    public 
  // Returns:   
  // Qualifier:
  // Brief: Destructor Free Memory
  /*************************************************************************/
  SpriteBatcher::~SpriteBatcher ()
  {
    m_spriteList.clear ();

    delete m_mesh;
  }

  /*************************************************************************/
  // Method:    Initialize
  // FullName:  Framework::SpriteBatcher::Initialize
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Initialize Sprite Batcher. Create Sprite VAO, VBO, EBO, ...
  /*************************************************************************/
  void SpriteBatcher::Initialize ()
  {
    m_shader = static_cast<Shader*>(ResourceManager::LoadResource ("Sprite", R_SHADER));
    m_mesh = new SpriteMesh ();
    m_mesh->CreateSprite (m_shader);
    m_matrixBuffer = m_mesh->m_matrixVbo;
    m_texBuffer = m_mesh->m_texVbo;
    m_colBuffer = m_mesh->m_colVbo;

    m_vao->Unbind ();
    m_shader->DisableShader ();
  }

  /*************************************************************************/
  // Method:    AddSprite
  // FullName:  Framework::SpriteBatcher::AddSprite
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: Sprite * sprite
  // Brief: Add Sprite To This Batcher
  /*************************************************************************/
  void SpriteBatcher::AddSprite(Sprite* sprite, std::string& textureName)
{
    m_spriteList [textureName].push_back (sprite);
    //m_dataReady = false;
  }

  /*************************************************************************/
  // Method:    Batch
  // FullName:  Framework::SpriteBatcher::Batch
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Instance Render the Sprite List
  /*************************************************************************/
  void SpriteBatcher::Batch ()
  {
    unsigned id = 0;
    std::string textureName;
    for (auto& i : m_spriteList)
    {
      textureName = i.first;
      for (auto& j : m_spriteList [textureName])
      {
        j->Draw (id, m_matrixBuffer, m_colBuffer, m_texBuffer);
        ++id;
      }

      m_mesh->DrawInstanced (m_shader, m_spriteList [textureName].size ());
    }
  }

}