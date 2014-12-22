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
  }

//******************************************************************************/
//*!
// \fn   ~sampleComponent()
// \brief   Default constructor
// */
//******************************************************************************/
  Sprite::~Sprite()
  {

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
    gameObject->sprite = this;
  }
}

