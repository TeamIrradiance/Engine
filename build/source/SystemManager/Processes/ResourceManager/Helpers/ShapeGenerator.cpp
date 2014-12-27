/******************************************************************************/
/*!
 \file   ShapeGenerator.cpp
 \author Manas Sudhir Kulkarni
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/

#include <Precompiled.h>

#define ARRAY_SIZE(a) sizeof (a) / sizeof (*a)

namespace Framework
{

  ShapeData ShapeGenerator::Generate_Quad ()
  {
    ShapeData data;

    data.Vertex2f (-1.0f, 1.0f);
    data.Texcoord2f (0.0f, 1.0f);

    data.Vertex2f (-1.0f, -1.0f);
    data.Texcoord2f (0.0f, 0.0f);

    data.Vertex2f (1.0f, -1.0f);
    data.Texcoord2f (1.0f, 0.0f);

    data.Vertex2f (1.0f, 1.0f);
    data.Texcoord2f (1.0f, 1.0f);

    data.Index3f (0, 1, 2);
    data.Index3f (2, 3, 0);

    return data;
  }

  ShapeData ShapeGenerator::Generate_Cube ()
  {
    ShapeData data;
    return data;
  }

  ShapeData ShapeGenerator::Generate_Normals (const ShapeData& z)
  {
    ShapeData data;
    return data;
  }

}