/******************************************************************************/
/*!
 \file   Mesh.h
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
 \class   sampleComponent
 \brief   sampleComponent Component
 Notes: 
 */
/******************************************************************************/

  class Mesh: public IData
  {
  public:
    Mesh();
    ~Mesh();
    void DefineMeta();

    //DATAS
    VAO* vao;
    VBO* vbo;
    EBO* ebo;
  };
}