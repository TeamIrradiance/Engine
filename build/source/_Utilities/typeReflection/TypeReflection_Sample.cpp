/******************************************************************************/
/*!
 \file   TypeReflection_SampleCode.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include "ITypeReflection.h"
#include "Serialize.h"
#include "MathLib.h"
#include "Transform.h"
#include "Components.h"
#include "Deserialize.h"
#include "ResourceManager.h"
#include <string>

void type_sample()
{



Framework::GameObject myObject;
Deserialize(&myObject,(Framework::ResourceManager::RESOURCE_DIRECTORY + "Archetypes\\test.arch").c_str ());
Serialize (&myObject, (Framework::ResourceManager::RESOURCE_DIRECTORY + "Archetypes\\test1.arch").c_str ());


int i = 0;
if(i == i)
  i = 0;

}