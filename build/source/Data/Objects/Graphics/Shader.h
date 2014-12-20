/******************************************************************************/
/*!
 \file   Shader.h
 \author Manas Sudhir Kulkarni
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/

#ifndef _SHADER_H
#define _SHADER_H

namespace Framework
{
/******************************************************************************/
/*!
 \class   sampleComponent
 \brief   sampleComponent Component
 Notes: 
 */
/******************************************************************************/
//@@ Only this 4 function is allowed in component class
  class Shader : public ::IData
  {
  public:
    // Constructor - Destructor
    Shader();
    ~Shader();

    // Methods
    void DefineMeta();

    inline GLuint Get_ID ();
    inline void Use ();
    inline void Disable ();

    GLuint attribLocation (const char* attribName);
    void bindAttribLocation (GLint location, const char* attribName);
    void enableVertexAttribArray (GLint attr);
    void vertexAttribPtr (const char* attribName, GLint size, GLenum type, GLboolean normalized, GLint stride, GLint offset);
    void vertexAttribPtr (GLint index, GLint size, GLenum type, GLboolean normalized, GLint stride, GLint offset);

    GLuint uniLocation (const char* uniName);

    void uni1f (const char* uniName, float uniValue);
    void uni2f (const char* uniName, float uniValue1, float uniValue2);
    void uni3f (const char* uniName, float uniValue1, float uniValue2, float uniValue3);
    void uni4f (const char* uniName, float uniValue1, float uniValue2, float uniValue3, float uniValue4);

    void uni1f (GLuint uniLoc, float uniValue);
    void uni2f (GLuint uniLoc, float uniValue1, float uniValue2);
    void uni3f (GLuint uniLoc, float uniValue1, float uniValue2, float uniValue3);
    void uni4f (GLuint uniLoc, float uniValue1, float uniValue2, float uniValue3, float uniValue4);

    void uni1fv (const char* uniName, const float* uniValue, int _count = 1);
    void uni2fv (const char* uniName, const float* uniValue, int _count = 1);
    void uni3fv (const char* uniName, const float* uniValue, int _count = 1);
    void uni4fv (const char* uniName, const float* uniValue, int _count = 1);

    void uni1fv (GLuint uniLoc, const float* uniValue, int _count = 1);
    void uni2fv (GLuint uniLoc, const float* uniValue, int _count = 1);
    void uni3fv (GLuint uniLoc, const float* uniValue, int _count = 1);
    void uni4fv (GLuint uniLoc, const float* uniValue, int _count = 1);

  private:
    //DATA
    GLuint m_program;

    GLint checkAttrib (const char* attribName);
    GLuint checkUniform (const char* uniName);

    std::string Read_Shader (const char* sFile);
    GLuint Compile_Shader (const char* filename, const char* sSource, GLenum type);
    GLuint Link_Program (const char* sName, GLuint vShader, GLuint fShader, GLuint gShader = 0);
  };
}

#endif // !_SHADER_H