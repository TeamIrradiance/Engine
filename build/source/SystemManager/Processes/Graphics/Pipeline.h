/******************************************************************************/
/*!
\file   Pipeline.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief  Template for all proces classes
*/
/******************************************************************************/

#pragma once


namespace Framework
{
  //typedef glm::mat2 Matrix2x2;
  //typedef glm::mat3 Matrix3x3;
  //typedef glm::mat4 Matrix4x4;

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
    void Update ();
    void Draw ();
    void ResetBlendMode ();
    void PushMatrix ();
    void PopMatrix ();
    bool IsDebugDrawEnabled () const;
    void ToggleDebugDraw ();

    void ResizeBuffer (const int w, const int h);
    //void OnApplicationPause (UpdateEvent* pause);

    int GetMatrixMode ();
    Matrix4x4 GetModelMatrix ();
    Matrix4x4 GetViewMatrix ();
    Matrix4x4 GetProjectionMatrix ();
    Matrix4x4 GetModelViewMatrix ();
    Matrix4x4 GetModelViewProjectionMatrix ();

  private:
    std::vector <glm::mat4> modelMatrix;
    std::vector <glm::mat4> viewMatrix;
    std::vector <glm::mat4> projectionMatrix;

    Matrix4x4 modelViewMatrix;
    Matrix4x4 viewProjectionMatrix;
    Matrix4x4 modelViewProjectionMatrix;

    GLenum sFactor;
    GLenum dFactor;
    int currentMatrix;
    bool matricesReady;

    bool useDebugDraw;
  };

  extern TransformPipeline* OPENGL;
}