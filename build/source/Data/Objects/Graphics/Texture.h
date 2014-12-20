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
    // Constructor - Destructor
    Texture();
    ~Texture();

    // Methods
    void DefineMeta();

    void Bind ();
    void Unbind ();
    void Load_Texture (const char* texFile);
    void Image2D (GLenum mode, unsigned char* pixels = nullptr);
    void TexParameteri (GLenum target, GLenum pname, GLenum param);
    void TexEnvf (GLenum target, GLenum pname, GLenum param);

    GLuint Get_ID ();
    float Get_Aspect ();
    glm::ivec2 Get_Size ();

    // Functions

  private:
    //DATA
    glm::ivec2 m_size;
    float m_aspect;
    GLuint m_texture;

    GLuint Generate_Texture (int w, int h);
    unsigned char* Load_Pixels (const char* filename, int* w, int *h, int* channels, GLenum forceChannels);
    void Free_Pixels (unsigned char* pixels);
  };
}

#endif // !_TEXTURE_H
