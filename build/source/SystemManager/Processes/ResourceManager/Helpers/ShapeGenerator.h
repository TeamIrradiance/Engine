/******************************************************************************/
/*!
 \file   ShapeGenerator.h
 \author Manas Sudhir Kulkarni
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/

#pragma once

namespace Framework
{

/******************************************************************************/
/*!
 \class   ShapeGenerator
 \brief   ShapeGenerator
 Notes: 
 */
/******************************************************************************/

  class ShapeGenerator
  {
  public:
    ShapeGenerator();
    ~ShapeGenerator();

    static void Generate_Triangle (Mesh* mesh);
    static void Generate_Quad (Mesh* mesh);
    static void Generate_Circle (Mesh* mesh);
    static void Generate_Cube (Mesh* mesh);

  };
}