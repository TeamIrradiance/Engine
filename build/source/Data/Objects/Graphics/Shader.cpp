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
  Shader::Shader ()
  {
  }

  /******************************************************************************/
  /*!
  \fn   ~Shader()
  \brief   destructor
  */
  /******************************************************************************/
  Shader::~Shader ()
  {
  }

  /******************************************************************************/
  /*!
  \fn   DefineMeta()
  \brief   define meta here
  */
  /******************************************************************************/
  void Shader::DefineMeta ()
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
  // Method:    UseShader
  // FullName:  Component::Shader::UseShader
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Use This Shader
  /*************************************************************************/
  void Shader::UseShader ()
  {
    glUseProgram (m_program);
  }

  /*************************************************************************/
  // Method:    DisableShader
  // FullName:  Component::Shader::DisableShader
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Disable All Shaders
  /*************************************************************************/
  void Shader::DisableShader ()
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
  // FullName:  Framework::Shader::enableVertexAttribArray
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLint attr
  // Brief:
  /*************************************************************************/
  void Shader::enableVertexAttribArray (const char* attrName)
  {
    glEnableVertexAttribArray (attribLocation (attrName));
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
  void Shader::vertexAttribPtr (const char* attribName, GLint size, GLint stride, GLint offset, GLenum type /* = GL_FLOAT*/, GLboolean normalized /* = GL_FALSE*/)
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
  void Shader::vertexAttribPtr (GLint index, GLint size, GLint stride, GLint offset, GLenum type /* = GL_FLOAT*/, GLboolean normalized /* = GL_FALSE*/)
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
  // Method:    uni1i
  // FullName:  Framework::Shader::uni1i
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: int uniValue
  // Brief:
  /*************************************************************************/
  void Shader::uni1i (const char* uniName, int uniValue)
  {
    GLuint loc = checkUniform (uniName);
    uni1i (loc, uniValue);
  }

  /*************************************************************************/
  // Method:    uni1i
  // FullName:  Framework::Shader::uni1i
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: int uniValue
  // Brief:
  /*************************************************************************/
  void Shader::uni1i (GLuint uniLoc, int uniValue)
  {
    glUniform1i (uniLoc, uniValue);
  }

  /*************************************************************************/
  // Method:    uni2i
  // FullName:  Framework::Shader::uni2i
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: int uniValue1
  // Parameter: int uniValue2
  // Brief:
  /*************************************************************************/
  void Shader::uni2i (const char* uniName, int uniValue1, int uniValue2)
  {
    GLuint loc = checkUniform (uniName);
    uni2i (loc, uniValue1, uniValue2);
  }

  /*************************************************************************/
  // Method:    uni2i
  // FullName:  Framework::Shader::uni2i
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: int uniValue1
  // Parameter: int uniValue2
  // Brief:
  /*************************************************************************/
  void Shader::uni2i (GLuint uniLoc, int uniValue1, int uniValue2)
  {
    glUniform2i (uniLoc, uniValue1, uniValue2);
  }

  /*************************************************************************/
  // Method:    uni3i
  // FullName:  Framework::Shader::uni3i
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: int uniValue1
  // Parameter: int uniValue2
  // Parameter: int uniValue3
  // Brief:
  /*************************************************************************/
  void Shader::uni3i (const char* uniName, int uniValue1, int uniValue2, int uniValue3)
  {
    GLuint loc = checkUniform (uniName);
    uni3i (loc, uniValue1, uniValue2, uniValue3);
  }

  /*************************************************************************/
  // Method:    uni3i
  // FullName:  Framework::Shader::uni3i
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: int uniValue1
  // Parameter: int uniValue2
  // Parameter: int uniValue3
  // Brief:
  /*************************************************************************/
  void Shader::uni3i (GLuint uniLoc, int uniValue1, int uniValue2, int uniValue3)
  {
    glUniform3i (uniLoc, uniValue1, uniValue2, uniValue3);
  }

  /*************************************************************************/
  // Method:    uni4i
  // FullName:  Framework::Shader::uni4i
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: int uniValue1
  // Parameter: int uniValue2
  // Parameter: int uniValue3
  // Parameter: int uniValue4
  // Brief:
  /*************************************************************************/
  void Shader::uni4i (const char* uniName, int uniValue1, int uniValue2, int uniValue3, int uniValue4)
  {
    GLuint loc = checkUniform (uniName);
    uni4i (loc, uniValue1, uniValue2, uniValue3, uniValue4);
  }

  /*************************************************************************/
  // Method:    uni4i
  // FullName:  Framework::Shader::uni4i
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: int uniValue1
  // Parameter: int uniValue2
  // Parameter: int uniValue3
  // Parameter: int uniValue4
  // Brief:
  /*************************************************************************/
  void Shader::uni4i (GLuint uniLoc, int uniValue1, int uniValue2, int uniValue3, int uniValue4)
  {
    glUniform4i (uniLoc, uniValue1, uniValue2, uniValue3, uniValue4);
  }

  /*************************************************************************/
  // Method:    uni1iv
  // FullName:  Framework::Shader::uni1iv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: const int * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uni1iv (const char* uniName, const int* uniValue, int _count /* = 1*/)
  {
    GLuint loc = checkUniform (uniName);
    uni1iv (loc, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uni1iv
  // FullName:  Framework::Shader::uni1iv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: const int * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uni1iv (GLuint uniLoc, const int* uniValue, int _count /* = 1*/)
  {
    glUniform1iv (uniLoc, _count, uniValue);
  }

  /*************************************************************************/
  // Method:    uni2iv
  // FullName:  Framework::Shader::uni2iv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: const int * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uni2iv (const char* uniName, const int* uniValue, int _count /* = 1*/)
  {
    GLuint loc = checkUniform (uniName);
    uni2iv (loc, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uni2iv
  // FullName:  Framework::Shader::uni2iv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: const int * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uni2iv (GLuint uniLoc, const int* uniValue, int _count /* = 1*/)
  {
    glUniform2iv (uniLoc, _count, uniValue);
  }

  /*************************************************************************/
  // Method:    uni3iv
  // FullName:  Framework::Shader::uni3iv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: const int * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uni3iv (const char* uniName, const int* uniValue, int _count /* = 1*/)
  {
    GLuint loc = checkUniform (uniName);
    uni3iv (loc, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uni3iv
  // FullName:  Framework::Shader::uni3iv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: const int * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uni3iv (GLuint uniLoc, const int* uniValue, int _count /* = 1*/)
  {
    glUniform3iv (uniLoc, _count, uniValue);
  }

  /*************************************************************************/
  // Method:    uni4iv
  // FullName:  Framework::Shader::uni4iv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: const int * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uni4iv (const char* uniName, const int* uniValue, int _count /* = 1*/)
  {
    GLuint loc = checkUniform (uniName);
    uni4iv (loc, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uni4iv
  // FullName:  Framework::Shader::uni4iv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: const int * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uni4iv (GLuint uniLoc, const int* uniValue, int _count /* = 1*/)
  {
    glUniform4iv (uniLoc, _count, uniValue);
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

  /*************************************************************************/
  // Method:    uniMat2
  // FullName:  Framework::Shader::uniMat2
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: const float * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uniMat2 (GLuint uniLoc, const float* uniValue, int _count /* = 1*/)
  {
    glUniformMatrix2fv (uniLoc, _count, GL_FALSE, uniValue);
  }

  /*************************************************************************/
  // Method:    uniMat3
  // FullName:  Framework::Shader::uniMat3
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: const float * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uniMat3 (GLuint uniLoc, const float* uniValue, int _count /* = 1*/)
  {
    glUniformMatrix3fv (uniLoc, _count, GL_FALSE, uniValue);
  }

  /*************************************************************************/
  // Method:    uniMat2
  // FullName:  Framework::Shader::uniMat2
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: const float * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uniMat2 (const char* uniName, const float* uniValue, int _count /* = 1*/)
  {
    GLuint uni = checkUniform (uniName);
    uniMat2 (uni, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uniMat3
  // FullName:  Framework::Shader::uniMat3
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: const float * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uniMat3 (const char* uniName, const float* uniValue, int _count /* = 1*/)
  {
    GLuint uni = checkUniform (uniName);
    uniMat3 (uni, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uniMat4
  // FullName:  Framework::Shader::uniMat4
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: const char * uniName
  // Parameter: const float * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uniMat4 (const char* uniName, const float* uniValue, int _count /* = 1*/)
  {
    GLuint uni = checkUniform (uniName);
    uniMat4 (uni, uniValue, _count);
  }

  /*************************************************************************/
  // Method:    uniMat4
  // FullName:  Framework::Shader::uniMat4
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: GLuint uniLoc
  // Parameter: const float * uniValue
  // Parameter: int _count
  // Brief:
  /*************************************************************************/
  void Shader::uniMat4 (GLuint uniLoc, const float* uniValue, int _count /* = 1*/)
  {
    glUniformMatrix4fv (uniLoc, _count, GL_FALSE, uniValue);
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
    UseShader ();
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
    std::cout << "Shader Program\n" << sName << "\nLink Status...\n" << log << "\n--------------" << std::endl;

    m_program = program;

    glDeleteShader (vShader);
    glDeleteShader (fShader);
    if (gShader != 0)
    {
      glDeleteShader (gShader);
    }

    this->Name = sName;
    return program;
  }

}