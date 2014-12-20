/******************************************************************************/
/*!
 \file   TypeReflection_SampleCode.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include "Precompiled.h"
#include "ITypeReflection.h"
#include "Serialize.h"
#include "MathLib.h"
#include "Transform.h"
#include "Components.h"
#include "Deserialize.h"
void type_sample()
{
  Component::Transform trans;
  
  trans.translation.x = 5.0f;
  trans.translation.y = 9.55f;
  trans.translation.z = 8.0f;

  trans.scale.x = 5.0f;
  trans.scale.y = 9.55f;
  trans.scale.z = 8.0f;

  trans.rotation = 5.f;

  Vector3 test;
  test.x = 123;
  test.y =123123;
  test.z = 8098989;
Json::Value root;

SerializeData(&trans,&root);

BaseEngine::GameObject myObject;
myObject.Add<Component::Transform>();
myObject.Add<Component::Sprite>();
Serialize(&myObject,"test.arch");

}