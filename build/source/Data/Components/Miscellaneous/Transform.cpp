/******************************************************************************/
/*!
 \file   Transform.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include "Precompiled.h"
#include "ITypeReflection.h"
#include "IComponents.h"

namespace Component
{
/******************************************************************************/
/*!
\fn   Transform()
\brief   Constructor
*/
/******************************************************************************/
  Transform::Transform()
  {
    m_sName = Tokenize(typeid(Transform).name());
  }

/******************************************************************************/
/*!
\fn   ~Transform()
\brief   Destructor
*/
/******************************************************************************/
  Transform::~Transform()
  {

  }

/******************************************************************************/
/*!
\fn   DefineMeta()
\brief   define meta here
*/
/******************************************************************************/
  void Transform::DefineMeta()
  {

  }
}