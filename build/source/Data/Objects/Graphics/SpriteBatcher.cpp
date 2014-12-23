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

namespace Framework
{

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
    m_matrixBuffer = const_cast<VBO*> (m_mesh->CreateSprite (m_shader));

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
  void SpriteBatcher::AddSprite (Sprite* sprite)
  {
    m_spriteList.push_back (sprite);
    m_dataReady = false;
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
    for (auto& i : m_spriteList)
    {
      i->Draw (id, m_matrixBuffer, m_texBuffer);
      ++id;
    }

    m_mesh->DrawInstanced (m_shader, m_spriteList.size());
  }

}