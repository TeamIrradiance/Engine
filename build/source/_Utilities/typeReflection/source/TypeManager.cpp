/******************************************************************************/
/*!
 \file   TypeManager.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include "TypeManager.h"
typeManager typemanagers;
/******************************************************************************/
/*!
 \fn     void typeManager::AddType(Variant* addThis)
 \par    addThis : add created variant to typemanager
 \brief
 */
/******************************************************************************/
void typeManager::AddType(Variant* addThis)
{
  std::string name = addThis->name;
  types[name] = addThis;
}