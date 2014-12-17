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

struct Vec3
{
  float x;
  float y;
  float z;
};

struct dummySprite
{
  Vec3 position;
  Vec3 translation;
  float rotation;
};

static void sample()
{
  DEFINE_TYPE(float);
  DEFINE_TYPE(Vec3);
    
  ADDMEMBERS(Vec3,x);
  ADDMEMBERS(Vec3,y);
  ADDMEMBERS(Vec3,z);


  DEFINE_TYPE(dummySprite);
  ADDMEMBERS(dummySprite,position);
  ADDMEMBERS(dummySprite,translation);
  ADDMEMBERS(dummySprite,rotation);
}