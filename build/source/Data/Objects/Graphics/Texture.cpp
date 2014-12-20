/******************************************************************************/
/*!
 \file   Texture.cpp
 \author Manas Sudhir Kulkarni
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>


namespace Framework
{
/******************************************************************************/
/*!
\fn      Texture()
\brief   Default constructor
*/
/******************************************************************************/
  Texture::Texture()
  {
  }

/******************************************************************************/
/*!
\fn   ~Texture()
\brief   destructor
*/
/******************************************************************************/
  Texture::~Texture()
  {
  }

/******************************************************************************/
/*!
\fn   DefineMeta()
\brief   define meta here
*/
/******************************************************************************/
  void Texture::DefineMeta()
  {
  }

  void Texture::Bind ()
  {
    glBindTexture (GL_TEXTURE_2D, m_texture);
  }

  void Texture::Unbind ()
  {
    glBindTexture (GL_TEXTURE_2D, 0);
  }

  void Texture::Load_Texture (const char* filename)
  {
    std::string file = filename;

    bool hasAlpha = false;
    unsigned pos = file.find_last_of ('.');
    std::string format = file.substr (pos + 1, file.size () - 1);
    if (format == "png")
    {
      hasAlpha = true;
    }

    int w, h;
    unsigned char* image = Load_Pixels (filename, &w, &h, 0, SOIL_LOAD_AUTO);

    if (image != nullptr)
    {
      Generate_Texture (w, h);
      Image2D (hasAlpha ? GL_RGBA : GL_RGB, image);
      Free_Pixels (image);

      if (hasAlpha)
      {
        TexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
      }
      if (format == "bmp")
      {
        TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glGenerateMipmap (GL_TEXTURE_2D);
      }
      else
      {
        TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
      }
    }
  }


  GLuint Texture::Generate_Texture (int w, int h)
  {
    // Load textures
    GLuint texture;
    glGenTextures (1, &texture);
    glBindTexture (GL_TEXTURE_2D, texture);

    m_size = { w, h };
    m_aspect = float (w) / h;
    m_texture = texture;

    return texture;
  }

  void Texture::Image2D (GLenum mode, unsigned char* pixels /* = nullptr*/)
  {
    glTexImage2D (GL_TEXTURE_2D, 0, mode, m_size.x, m_size.y, 0, mode, GL_UNSIGNED_BYTE, pixels);
  }

  void Texture::TexParameteri (GLenum target, GLenum pname, GLenum param)
  {
    glTexParameteri (target, pname, param);
  }

  void Texture::TexEnvf (GLenum target, GLenum pname, GLenum param)
  {
    glTexEnvf (target, pname, (GLfloat)param);
  }

  //////////////////////////////////////////////////////////////////////////
  // GETTORS
  //////////////////////////////////////////////////////////////////////////

  GLuint Texture::Get_ID ()
  {
    return m_texture;
  }

  float Texture::Get_Aspect ()
  {
    return m_aspect;
  }

  glm::ivec2 Texture::Get_Size ()
  {
    return m_size;
  }

  //////////////////////////////////////////////////////////////////////////
  // PRIVATE METHODS
  //////////////////////////////////////////////////////////////////////////

  unsigned char* Texture::Load_Pixels (const char* filename, int* w, int *h, int* channels, GLenum forceChannels)
  {
    return SOIL_load_image (filename, w, h, channels, forceChannels);
  }

  void Texture::Free_Pixels (unsigned char* pixels)
  {
    SOIL_free_image_data (pixels);
  }

}
