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
    // Print Abhishek 10 times
    for (int i = 0; i < 10; ++i)
    {
      std::cout << "ABHISHEK " << i << std::endl;
    }
  }

  /*************************************************************************/
  // Method:    Bind
  // FullName:  Framework::Texture::Bind
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Bind Current Texture
  /*************************************************************************/
  void Texture::Bind ()
  {
    glBindTexture (GL_TEXTURE_2D, m_texture);
  }

  /*************************************************************************/
  // Method:    Unbind
  // FullName:  Framework::Texture::Unbind
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Unbind Current Texture
  /*************************************************************************/
  void Texture::Unbind ()
  {
    glBindTexture (GL_TEXTURE_2D, 0);
  }

  /*************************************************************************/
  // Method:    Load_Texture
  // FullName:  Framework::Texture::Load_Texture
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * filename
  // Brief: Load a 2D OpenGL Texture from Input File 
  /*************************************************************************/
  void Texture::Load_Texture (const char* name, const char* filename)
  {
    int w, h;
    std::string format;
    bool hasAlpha = Is_Alpha(filename, format.c_str());
    unsigned char* image = Load_Pixels (filename, &w, &h, 0, SOIL_LOAD_AUTO);

    if (image != nullptr)
    {
      this->Name = name;
      Generate_Texture (w, h);
      Image2D (hasAlpha ? GL_RGBA : GL_RGB, image);
      Free_Pixels (image);

      if (hasAlpha)
      {
        TexEnvf (GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
      }
      if (format == "bmp")
      {
        Specify_BMP_Paramaters ();
      }
      else
      {
        Specify_Alpha_Parameters ();
      }
    }
  }


  /*************************************************************************/
  // Method:    Generate_Texture
  // FullName:  Framework::Texture::Generate_Texture
  // Access:    private 
  // Returns:   GLuint
  // Qualifier:
  // Parameter: int w
  // Parameter: int h
  // Brief: Generate a 2D OpenGL Texture with Input Dimensions
  /*************************************************************************/
  GLuint Texture::Generate_Texture (int w, int h)
  {
    // Load textures
    GLuint texture;
    glGenTextures (1, &texture);
    glBindTexture (GL_TEXTURE_2D, texture);

    m_size = glm::ivec2 (w, h);
    m_aspect = float (w) / h;
    m_texture = texture;

    return texture;
  }

  /*************************************************************************/
  // Method:    Image2D
  // FullName:  Framework::Texture::Image2D
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLenum mode
  // Parameter: unsigned char * pixels
  // Brief: Specify a 2D Texture Image
  /*************************************************************************/
  void Texture::Image2D (GLenum mode, unsigned char* pixels /* = nullptr*/)
  {
    glTexImage2D (GL_TEXTURE_2D, 0, mode, m_size.x, m_size.y, 0, mode, GL_UNSIGNED_BYTE, pixels);
  }

  /*************************************************************************/
  // Method:    TexParameteri
  // FullName:  Framework::Texture::TexParameteri
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLenum target
  // Parameter: GLenum pname
  // Parameter: GLenum param
  // Brief: Sets Texture Parameters
  /*************************************************************************/
  void Texture::TexParameteri (GLenum target, GLenum pname, GLenum param)
  {
    glTexParameteri (target, pname, param);
  }

  /*************************************************************************/
  // Method:    TexEnvf
  // FullName:  Framework::Texture::TexEnvf
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLenum target
  // Parameter: GLenum pname
  // Parameter: GLenum param
  // Brief: Modulation
  /*************************************************************************/
  void Texture::TexEnvf (GLenum target, GLenum pname, GLenum param)
  {
    glTexEnvf (target, pname, (GLfloat)param);
  }

  void Texture::Set (Texture* atlas)
  {
    m_size.x = (int)(atlas->m_size.x * (Texcoords.ne.x - Texcoords.nw.x));
    m_size.y = (int)(atlas->m_size.y * (Texcoords.ne.y - Texcoords.se.y));
    m_aspect = (float) m_size.x / m_size.y;
  }

  //////////////////////////////////////////////////////////////////////////
  // GETTORS
  //////////////////////////////////////////////////////////////////////////

  /*************************************************************************/
  // Method:    Get_ID
  // FullName:  Framework::Texture::Get_ID
  // Access:    public 
  // Returns:   GLuint
  // Qualifier:
  // Brief: Get Texture ID
  /*************************************************************************/
  GLuint Texture::GetID ()
  {
    return m_texture;
  }

  /*************************************************************************/
  // Method:    Get_Aspect
  // FullName:  Framework::Texture::Get_Aspect
  // Access:    public 
  // Returns:   float
  // Qualifier:
  // Brief: Get ASpect Ratio of Texture
  /*************************************************************************/
  float Texture::GetAspect ()
  {
    return m_aspect;
  }

  /*************************************************************************/
  // Method:    Get_Size
  // FullName:  Framework::Texture::Get_Size
  // Access:    public 
  // Returns:   glm::ivec2
  // Qualifier:
  // Brief: Get Dimensions of Texture
  /*************************************************************************/
  glm::ivec2 Texture::GetSize ()
  {
    return m_size;
  }

  //////////////////////////////////////////////////////////////////////////
  // PRIVATE METHODS
  //////////////////////////////////////////////////////////////////////////

  /*************************************************************************/
  // Method:    Load_Pixels
  // FullName:  Framework::Texture::Load_Pixels
  // Access:    private 
  // Returns:   unsigned char*
  // Qualifier:
  // Parameter: const char * filename
  // Parameter: int * w
  // Parameter: int * h
  // Parameter: int * channels
  // Parameter: GLenum forceChannels
  // Brief: Load Pixels from Input File
  /*************************************************************************/
  unsigned char* Texture::Load_Pixels (const char* filename, int* w, int *h, int* channels, GLenum forceChannels)
  {
    return SOIL_load_image (filename, w, h, channels, forceChannels);
  }

  /*************************************************************************/
  // Method:    Free_Pixels
  // FullName:  Framework::Texture::Free_Pixels
  // Access:    private 
  // Returns:   void
  // Qualifier:
  // Parameter: unsigned char * pixels
  // Brief: Free Loaded Pixels
  /*************************************************************************/
  void Texture::Free_Pixels (unsigned char* pixels)
  {
    SOIL_free_image_data (pixels);
  }

  void Texture::Specify_BMP_Paramaters ()
  {
    TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap (GL_TEXTURE_2D);
  }

  void Texture::Specify_Alpha_Parameters ()
  {
    TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    TexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  }

  /*************************************************************************/
  // Method:    Is_Alpha
  // FullName:  Framework::Texture::Is_Alpha
  // Access:    private 
  // Returns:   bool
  // Qualifier:
  // Parameter: const char * filename
  // Parameter: const char * _format
  // Brief: Helper Function To Find If File Is Png, Bmp, Jpeg...
  /*************************************************************************/
  bool Texture::Is_Alpha (const char* filename, const char* _format)
  {
    std::string file = filename;
    bool hasAlpha = false;
    unsigned pos = file.find_last_of ('.');
    std::string format = file.substr (pos + 1, file.size () - 1);
    if (format == "png")
    {
      hasAlpha = true;
    }

    _format = format.c_str ();
    return hasAlpha;
  }

}
