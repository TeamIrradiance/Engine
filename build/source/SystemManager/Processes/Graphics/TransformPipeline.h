/******************************************************************************/
/*!
\file   TransformPipeline.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief  Template for all proces classes
*/
/******************************************************************************/

#pragma once


namespace Framework
{

  enum MATRIX_MODE
  {
    MODEL = 0,
    VIEW,
    PROJECTION,
  };

  class TransformPipeline
  {
  public:
    TransformPipeline ();
    ~TransformPipeline ();

    void Update (double dt);

    void LoadIdentity ();
    void MatrixMode (int mode);
    void Translatef (float x, float y, float z);
    void Translatefv (float* v);
    void Scalef (float x, float y, float z);
    void Scalef (float s);
    void Scalefv (float* v);
    void Rotatef (float r, float x, float y, float z);
    void Rotatefv (float r, float* v);
    void Ortho (float left, float right, float bottom, float top, float near = 0.0f, float farPlane = 1.0f);
    void Perspective (float fov, float aspect, float nearPlane, float farPlane);
    void LookAt (glm::vec3 eye, glm::vec3 center, glm::vec3 up);
    void UpdateMatrices ();
    void UploadMatrices (Shader* shader);
    void PushMatrix ();
    void PopMatrix ();

    int GetMatrixMode ();
    Matrix4x4 GetModelMatrix ();
    Matrix4x4 GetViewMatrix ();
    Matrix4x4 GetProjectionMatrix ();
    Matrix4x4 GetModelViewMatrix ();
    Matrix4x4 GetModelViewProjectionMatrix ();


    // 16 BYTE ALIGNMENT TO AVOID ACCESS VIOLATION
    void* operator new (size_t i)
    {
      return _mm_malloc (i, 16);
    }

    void operator delete (void* p)
    {
      _mm_free (p);
    }

    static std::unordered_map <unsigned, std::list <Transform*>> transformVectorMap;

  private:
    std::vector <Matrix4x4> m_modelMatrix;
    std::vector <Matrix4x4> m_viewMatrix;
    std::vector <Matrix4x4> m_projectionMatrix;

    Matrix4x4 m_modelViewMatrix;
    Matrix4x4 m_viewProjectionMatrix;
    Matrix4x4 m_modelViewProjectionMatrix;

    int m_currentMatrix;
    bool m_matricesReady;

  };

  extern TransformPipeline* G_TRANSFORM;
}