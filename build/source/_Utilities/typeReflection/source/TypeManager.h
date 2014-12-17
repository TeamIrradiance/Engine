/******************************************************************************/
/*!
 \file   IBaseEngine.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include <Precompiled.h>
#include "Variant.h"
#include "TypeData.h"

/******************************************************************************/
/*!
 \class   typeManager
 \brief   a class managing all defined types
 */
/******************************************************************************/
class typeManager
{
public:
  void AddType(Variant* addThis);
  std::map<std::string, Variant*> types;
};


extern typeManager typemanagers;