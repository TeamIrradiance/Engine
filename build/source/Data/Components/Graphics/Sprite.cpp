//******************************************************************************/
//*!
// \file   Sprite.h
// \author Aji Suprana
// \par    Course: GAM250
// \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
// \brief
// */
//******************************************************************************/
#include <Precompiled.h>
#include "Sprite.h"
#include "BufferObjects.h"

//@TODO: test vector 2 glm::vec2 conversion using copy constructor and assignment operator
namespace Framework
{
////******************************************************************************/
////*!
// \fn  sampleComponent()
// \brief   Default constructor
// //*/
////******************************************************************************/
  Sprite::Sprite()
  {
    m_sName = Tokenize(typeid(Sprite).name());
    m_batched = false;
  }

//******************************************************************************/
//*!
// \fn   ~sampleComponent()
// \brief   Default constructor
// */
//******************************************************************************/
  Sprite::~Sprite()
  {
    Color = Vector4 (1.0f, 1.0f, 1.0f, 1.0f);
  }

/******************************************************************************/
/*!
\fn   DefineMeta()
\brief   define meta here
*/
/******************************************************************************/
  void Sprite::DefineMeta()
  {

  }

  /*************************************************************************/
  // Method:    Initialize
  // FullName:  Framework::Sprite::Initialize
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Initialize Sprite Component
  /*************************************************************************/
  void Sprite::Initialize ()
  {
    //gameObject->sprite = this;
    m_texture = static_cast<Texture*>(ResourceManager::LoadResource (SpriteSource, R_TEXTURE));
    SpriteBatcher::AddSprite (this, m_texture->AtlasName);
  }

  void Sprite::Draw(unsigned instanceID, VBO* posVbo, VBO* colVbo, VBO* texVbo)
  {
    Matrix4x4 m = glm::scale (glm::vec3 (0.1f));

    if (m_batched)
    {
      posVbo->UpdateMatrixData (m, instanceID, sizeof (Matrix4x4) / sizeof (GLfloat));
      colVbo->UpdateColorData (Color, instanceID, sizeof (GLfloat));
      texVbo->UpdateTexcoordData (m_texture->Texcoords, instanceID, sizeof (Texcoord) / sizeof (GLfloat));
    }
    else
    {
      m =
        glm::translate (glm::linearRand (glm::vec3 (-1.0f, -1.0f, 0.0f), glm::vec3 (1.0f, 1.0f, 0.0f))) *
        glm::rotate (glm::linearRand (-1.0f, 1.0f), glm::vec3 (0, 0, 1)) *
        glm::scale (glm::linearRand (glm::vec3 (0.04f), glm::vec3 (0.05f)));

      posVbo->AddData (glm::value_ptr (m), sizeof (Matrix4x4) / sizeof (GLfloat));

      colVbo->AddData (glm::value_ptr (glm::vec4 (Color)), sizeof (Vector4) / sizeof (GLfloat));

      texVbo->AddTexcoordData (m_texture->Texcoords);
    }

    m_batched = true;
  }

}

