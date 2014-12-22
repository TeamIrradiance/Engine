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
void type_sample()
{



Framework::GameObject myObject;
Deserialize(&myObject,"test.arch");
Serialize(&myObject,"test1.arch");


int i = 0;
if(i == i)
  i = 0;

}