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

    ShapeGenerator ();
    ~ShapeGenerator ();

    static ShapeData Generate_Quad ();
    static ShapeData Generate_Cube ();
    static ShapeData Generate_Normals (const ShapeData& shapeData);

  private:

  };
}