/******************************************************************************/
/*!
 \file   Texture.h
 \author Manas Sudhir Kulkarni
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/

#include "IData.h"

#ifndef _TEXTURE_H
#define _TEXTURE_H

//@@ REMEMBER TO INCLUDE NEW COMPONENT TO "IComponents.h"
namespace Framework
{
/******************************************************************************/
/*!
 \class   Texture
 \brief   Texture Object
 Notes: 
 */
/******************************************************************************/

  class Texture : public ::IData
  {
  public:
    Texture();
    ~Texture();
    void DefineMeta();

  private:
    //DATA
    glm::vec2 m_size;
    GLuint m_texture;
  };
}

#endif // !_TEXTURE_H
