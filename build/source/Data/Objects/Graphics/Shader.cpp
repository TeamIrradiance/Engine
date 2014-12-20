/******************************************************************************/
/*!
 \file   Shader.cpp
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
\fn      Shader()
\brief   Default constructor
*/
/******************************************************************************/
  Shader::Shader()
  {
  }

/******************************************************************************/
/*!
\fn   ~Shader()
\brief   destructor
*/
/******************************************************************************/
  Shader::~Shader()
  {
  }

/******************************************************************************/
/*!
\fn   DefineMeta()
\brief   define meta here
*/
/******************************************************************************/
  void Shader::DefineMeta()
  {
  }

  /*************************************************************************/
  // Method:    Get_ID
  // FullName:  Component::Shader::Get_ID
  // Access:    public 
  // Returns:   GLuint
  // Qualifier:
  // Brief: Get Program ID of Shader Program
  /*************************************************************************/
  GLuint Shader::Get_ID ()
  {
    return m_program;
  }

  /*************************************************************************/
  // Method:    Use
  // FullName:  Component::Shader::Use
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Use This Shader
  /*************************************************************************/
  void Shader::Use ()
  {
    glUseProgram (m_program);
  }

  /*************************************************************************/
  // Method:    Disable
  // FullName:  Component::Shader::Disable
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Disable All Shaders
  /*************************************************************************/
  void Shader::Disable ()
  {
    glUseProgram (0);
  }

  /*************************************************************************/
  // Method:    attribLocation
  // FullName:  Component::Shader::attribLocation
  // Access:    public 
  // Returns:   GLuint
  // Qualifier:
  // Parameter: const char * attribName
  // Brief: Get Location of Input Attribute in Shader
  /*************************************************************************/
  GLuint Shader::attribLocation (const char* attribName)
  {
    GLint attr = checkAttrib (attribName);
    return attr;
  }

  /*************************************************************************/
  // Method:    bindAttribLocation
  // FullName:  Component::Shader::bindAttribLocation
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLint location
  // Parameter: const char * attribName
  // Brief: Bind Input Attribute at Input Location
  /*************************************************************************/
  void Shader::bindAttribLocation (GLint location, const char* attribName)
  {
    glBindAttribLocation (m_program, location, attribName);
  }

  /*************************************************************************/
  // Method:    enableVertexAttribArray
  // FullName:  Component::Shader::enableVertexAttribArray
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLint attr
  // Brief: Enable the Input Attribute in the VAO
  /*************************************************************************/
  void Shader::enableVertexAttribArray (GLint attr)
  {
    glEnableVertexAttribArray (attr);
  }

  /*************************************************************************/
  // Method:    vertexAttribPtr
  // FullName:  Component::Shader::vertexAttribPtr
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * attribName
  // Parameter: GLint size
  // Parameter: GLenum type
  // Parameter: GLboolean normalized
  // Parameter: GLint stride
  // Parameter: GLint offset
  // Brief:
  /*************************************************************************/
  void Shader::vertexAttribPtr (const char* attribName, GLint size, GLenum type, GLboolean normalized, GLint stride, GLint offset)
  {
    glVertexAttribPointer (attribLocation (attribName), size, type, normalized, stride, (const void*) (offset));
  }

  /*************************************************************************/
  // Method:    vertexAttribPtr
  // FullName:  Component::Shader::vertexAttribPtr
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLint index
  // Parameter: GLint size
  // Parameter: GLenum type
  // Parameter: GLboolean normalized
  // Parameter: GLint stride
  // Parameter: GLint offset
  // Brief:
  /*************************************************************************/
  void Shader::vertexAttribPtr (GLint index, GLint size, GLenum type, GLboolean normalized, GLint stride, GLint offset)
  {
    glVertexAttribPointer (index, size, type, normalized, stride, (const void*) (offset));
  }

  /*************************************************************************/
  // Method:    uniLocation
  // FullName:  Component::Shader::uniLocation
  // Access:    public 
  // Returns:   GLuint
  // Qualifier:
  // Parameter: const char * uniName
  // Brief: Get Location of Input Uniform in Shader
  /*************************************************************************/
  GLuint Shader::uniLocation (const char* uniName)
  {
    return glGetUniformLocation (m_program, uniName);
  }

  /*************************************************************************/
  // Method:    uni1f
  // FullName:  Component::Shader::uni1f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue
  // Brief: Get Location of Input Uniform in Shader
  /*************************************************************************/
  void Shader::uni1f (const char* uniName, float uniValue)
  {
    GLuint uni = checkUniform (uniName);
    uni1f (uni, uniValue);
  }

  /*************************************************************************/
  // Method:    uni1f
  // FullName:  Component::Shader::uni1f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: float uniValue
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni1f (GLuint uniLoc, float uniValue)
  {
    glUniform1f (uniLoc, uniValue);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni2f (const char* uniName, float uniValue1, float uniValue2)
  {
    GLuint uni = checkUniform (uniName);
    uni2f (uni, uniValue1, uniValue2);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni2f (GLuint uniLoc, float uniValue1, float uniValue2)
  {
    glUniform2f (uniLoc, uniValue1, uniValue2);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni3f (const char* uniName, float uniValue1, float uniValue2, float uniValue3)
  {
    GLuint uni = checkUniform (uniName);
    uni3f (uni, uniValue1, uniValue2, uniValue3);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni3f (GLuint uniLoc, float uniValue1, float uniValue2, float uniValue3)
  {
    glUniform3f (uniLoc, uniValue1, uniValue2, uniValue3);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni4f (const char* uniName, float uniValue1, float uniValue2, float uniValue3, float uniValue4)
  {
    GLuint uni = checkUniform (uniName);
    uni4f (uni, uniValue1, uniValue2, uniValue3, uniValue4);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni4f (GLuint uniLoc, float uniValue1, float uniValue2, float uniValue3, float uniValue4)
  {
    glUniform4f (uniLoc, uniValue1, uniValue2, uniValue3, uniValue4);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni1fv (const char* uniName, const float* uniValue, int _count /* = 1*/)
  {
    GLuint uni = checkUniform (uniName);
    uni1fv (uni, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni1fv (GLuint uniLoc, const float* uniValue, int _count /* = 1*/)
  {
    glUniform1fv (uniLoc, _count, uniValue);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni2fv (const char* uniName, const float* uniValue, int _count /* = 1*/)
  {
    GLuint uni = checkUniform (uniName);
    uni2fv (uni, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni2fv (GLuint uniLoc, const float* uniValue, int _count /* = 1*/)
  {
    glUniform2fv (uniLoc, _count, uniValue);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni3fv (const char* uniName, const float* uniValue, int _count /* = 1*/)
  {
    GLuint uni = checkUniform (uniName);
    uni3fv (uni, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni3fv (GLuint uniLoc, const float* uniValue, int _count /* = 1*/)
  {
    glUniform3fv (uniLoc, _count, uniValue);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni4fv (const char* uniName, const float* uniValue, int _count /* = 1*/)
  {
    GLuint uni = checkUniform (uniName);
    uni4fv (uni, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Pass The Input Data To Uniform In Shader
  /*************************************************************************/
  void Shader::uni4fv (GLuint uniLoc, const float* uniValue, int _count /* = 1*/)
  {
    glUniform4fv (uniLoc, _count, uniValue);
  }

  //////////////////////////////////////////////////////////////////////////
  // PRIVATE FUNCTIONS
  //////////////////////////////////////////////////////////////////////////

  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Helper Function To Check for Invalid Attrib Names
  /*************************************************************************/
  GLint Shader::checkAttrib(const char* attribName)
  {
    int i = glGetAttribLocation (m_program, attribName);
    // log msg only in the DEBUG version
#ifdef _DEBUG
    if (i == -1)
    {
      std::cout << "ATTRIBUTE " + std::string (attribName) + " DOES NOT EXIST!\n";
    }
#endif

    return i;
  }


  /*************************************************************************/
  // Method:    uni2f
  // FullName:  Component::Shader::uni2f
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: float uniValue1
  // Parameter: float uniValue2
  // Brief: Helper Function To Check for Invalid Uniform Names
  /*************************************************************************/
  GLuint Shader::checkUniform(const char* uniName)
  {
    // log msg only in the DEBUG version
    int i = glGetUniformLocation (m_program, uniName);
#ifdef _DEBUG
    if (i == -1)
    {
      std::cout << "UNIFORM " + std::string(uniName) + " DOES NOT EXIST!\n";
    }
#endif

    return i;
  }

  /*************************************************************************/
  // Method:    Read_Shader
  // FullName:  Component::Shader::Read_Shader
  // Access:    private 
  // Returns:   std::string
  // Qualifier:
  // Parameter: const char * sFile
  // Brief: Reads The .glsl Shader File to a Std::String
  /*************************************************************************/
  std::string Shader::Read_Shader(const char* sFile)
  {
    std::ifstream shaderFile (sFile);

    if (!shaderFile.good ())
    {
      std::cout << "File cannot be loaded...  " << sFile;
      return NULL;
    }

    return std::string (std::istreambuf_iterator<char> (shaderFile),
      std::istreambuf_iterator<char> ());
  }

  /*************************************************************************/
  // Method:    Compile_Shader
  // FullName:  Component::Shader::Compile_Shader
  // Access:    private 
  // Returns:   GLuint
  // Qualifier:
  // Parameter: const char * filename
  // Parameter: const char * sSource
  // Parameter: GLenum shaderType
  // Brief: Compiles the Input Shader Source
  /*************************************************************************/
  GLuint Shader::Compile_Shader (const char* filename, const char* sSource, GLenum shaderType)
{
    GLuint shader = glCreateShader (shaderType);
    glShaderSource (shader, 1, &sSource, NULL);
    glCompileShader (shader);
    char log [1000];
    glGetShaderInfoLog (shader, 1000, NULL, log);

    std::cout << filename << "\nCompile Status...\n" << log << "\n--------------" << std::endl;

    return shader;
  }

  /*************************************************************************/
  // Method:    Link_Program
  // FullName:  Component::Shader::Link_Program
  // Access:    private 
  // Returns:   GLuint
  // Qualifier:
  // Parameter: const char * sName
  // Parameter: GLuint vShader
  // Parameter: GLuint fShader
  // Parameter: GLuint gShader
  // Brief: Links the shaders to create Shader Program
  /*************************************************************************/
  GLuint Shader::Link_Program (const char* sName, GLuint vShader, GLuint fShader, GLuint gShader /*= 0*/)
{
    GLuint program = glCreateProgram ();
    glAttachShader (program, vShader);
    glAttachShader (program, fShader);
    if (gShader != 0)
    {
      glAttachShader (program, gShader);
    }

    glLinkProgram (program);
    char log [1000];
    glGetProgramInfoLog (program, 1000, NULL, log);
    std::cout << "\n" << sName << "\nLink Status...\n" << log << "\n--------------" << std::endl;

    m_program = program;

    glDeleteShader (vShader);
    glDeleteShader (fShader);
    if (gShader != 0)
    {
      glDeleteShader (gShader);
    }

    return program;
  }

}