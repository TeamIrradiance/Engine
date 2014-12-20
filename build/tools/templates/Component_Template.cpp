/******************************************************************************/
/*!
 \file   sampleComponent.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include "Component_Template.h"
//@@ REMEMBER TO INCLUDE NEW COMPONENT TO "IComponents.h"
namespace Component
{
/******************************************************************************/
/*!
\fn      sampleComponent()
\brief   Default constructor
*/
/******************************************************************************/
  sampleComponent::sampleComponent()
  {
    m_sName = Tokenize(typeid(sampleComponent).name());
  }

/******************************************************************************/
/*!
\fn   ~sampleComponent()
\brief   destructor
*/
/******************************************************************************/
  sampleComponent::~sampleComponent()
  {

  }

/******************************************************************************/
/*!
\fn   DefineMeta()
\brief   define meta here
*/
/******************************************************************************/
  void sampleComponent::DefineMeta()
  {

  }
}