/******************************************************************************/
/*!
\file   TransformPipeline.cpp
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief  Template for all proces classes
*/
/******************************************************************************/

#include <Precompiled.h>

namespace Framework
{
  TransformPipeline* G_TRANSFORM = nullptr;

  // STATIC VARIABLES
  std::unordered_map <unsigned, std::list <Transform*>> TransformPipeline::transformVectorMap;

  /*************************************************************************/
  // Method:    TransformPipeline
  // FullName:  Framework::TransformPipeline::TransformPipeline
  // Access:    public 
  // Returns:   
  // Qualifier:
  // Brief: This Replicates the Old OpenGL Transform Pipeline With New Functions
  /*************************************************************************/
  TransformPipeline::TransformPipeline ()
  {
    G_TRANSFORM = this;

    m_modelMatrix.push_back (glm::mat4 (1.0f));
    m_viewMatrix.push_back (glm::mat4 (1.0f));
    m_projectionMatrix.push_back (glm::mat4 (1.0f));

    m_modelViewMatrix = glm::mat4 (1.0f);
    m_modelViewProjectionMatrix = glm::mat4 (1.0f);
    m_matricesReady = true;
    m_currentMatrix = 0;

    transformVectorMap [0];
  }

  /*************************************************************************/
  // Method:    ~TransformPipeline
  // FullName:  Framework::TransformPipeline::~TransformPipeline
  // Access:    public 
  // Returns:   
  // Qualifier:
  // Brief:
  /*************************************************************************/
  TransformPipeline::~TransformPipeline ()
  {
    G_TRANSFORM = nullptr;
  }

  /*************************************************************************/
  // Method:    LoadIdentity
  // FullName:  Framework::TransformPipeline::LoadIdentity
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Load Identity Matrix To Current Matrix Mode Matrix
  /*************************************************************************/
  void TransformPipeline::LoadIdentity ()
  {
    if (m_currentMatrix == MODEL || m_currentMatrix == VIEW)
    {
      m_modelMatrix [m_modelMatrix.size () - 1] = glm::mat4 (1.0);
      m_viewMatrix [m_modelMatrix.size () - 1] = glm::mat4 (1.0);
    }
    else
    {
      m_projectionMatrix [m_viewMatrix.size () - 1] = glm::mat4 (1.0);
    }

    m_matricesReady = false;
  }

  /*************************************************************************/
  // Method:    MatrixMode
  // FullName:  Framework::TransformPipeline::MatrixMode
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: int mode
  // Brief: Change Current Matrix Mode To Input Mode
  /*************************************************************************/
  void TransformPipeline::MatrixMode (int mode)
  {
    if (mode == MODEL || mode == VIEW || mode == PROJECTION)
    {
      m_currentMatrix = mode;
    }
  }

  /*************************************************************************/
  // Method:    Translatef
  // FullName:  Framework::TransformPipeline::Translatef
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: float x
  // Parameter: float y
  // Parameter: float z
  // Brief: Translate Current Matrix By Input Values
  /*************************************************************************/
  void TransformPipeline::Translatef (float x, float y, float z)
  {
    if (m_currentMatrix == MODEL)
    {
      m_modelMatrix [m_modelMatrix.size () - 1] *= glm::translate (glm::vec3 (x, y, z));
    }
    else if (m_currentMatrix == VIEW)
    {
      m_viewMatrix [m_viewMatrix.size () - 1] *= glm::translate (glm::vec3 (-x, -y, -z));
    }

    m_matricesReady = false;
  }

  /*************************************************************************/
  // Method:    Translatefv
  // FullName:  Framework::TransformPipeline::Translatefv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: float * v
  // Brief: Translate Current Matrix By Input Vector
  /*************************************************************************/
  void TransformPipeline::Translatefv (const float* v)
  {
    if (m_currentMatrix == MODEL)
    {
      m_modelMatrix [m_modelMatrix.size () - 1] *= glm::translate (glm::vec3 (v [0], v [1], v [2]));
    }
    else if (m_currentMatrix == VIEW)
    {
      m_viewMatrix [m_viewMatrix.size () - 1] *= glm::translate (glm::vec3 (-v [0], -v [1], -v [2]));
    }

    m_matricesReady = false;
  }

  /*************************************************************************/
  // Method:    Scalef
  // FullName:  Framework::TransformPipeline::Scalef
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: float x
  // Parameter: float y
  // Parameter: float z
  // Brief: Scale Current Matrix By Input Values
  /*************************************************************************/
  void TransformPipeline::Scalef (float x, float y, float z)
  {
    if (m_currentMatrix == MODEL)
    {
      m_modelMatrix [m_modelMatrix.size () - 1] *= glm::scale (glm::vec3 (x, y, z));
    }
    else if (m_currentMatrix == VIEW)
    {
      m_viewMatrix [m_viewMatrix.size () - 1] *= glm::scale (glm::vec3 (x, y, z));
    }

    m_matricesReady = false;
  }

  /*************************************************************************/
  // Method:    Scalef
  // FullName:  Framework::TransformPipeline::Scalef
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: float s
  // Brief: Uniform Scale Current Matrix By Input Value
  /*************************************************************************/
  void TransformPipeline::Scalef (float s)
  {
    if (m_currentMatrix == MODEL)
    {
      m_modelMatrix [m_modelMatrix.size () - 1] *= glm::scale (glm::vec3 (s, s, s));
    }
    else if (m_currentMatrix == VIEW)
    {
      m_viewMatrix [m_viewMatrix.size () - 1] *= glm::scale (glm::vec3 (s, s, s));
    }

    m_matricesReady = false;
  }

  /*************************************************************************/
  // Method:    Scalefv
  // FullName:  Framework::TransformPipeline::Scalefv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: float * v
  // Brief: Scale Current Matrix By Input Vector
  /*************************************************************************/
  void TransformPipeline::Scalefv (const float* v)
  {
    if (m_currentMatrix == MODEL)
    {
      m_modelMatrix [m_modelMatrix.size () - 1] *= glm::scale (glm::vec3 (v [0], v [1], v [2]));
    }
    else if (m_currentMatrix == VIEW)
    {
      m_viewMatrix [m_viewMatrix.size () - 1] *= glm::scale (glm::vec3 (v [0], v [1], v [2]));
    }

    m_matricesReady = false;
  }

  /*************************************************************************/
  // Method:    Rotatef
  // FullName:  Framework::TransformPipeline::Rotatef
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: float r - Angle in Degrees
  // Parameter: float x - X Axis Of Rotation
  // Parameter: float y - Y Axis Of Rotation
  // Parameter: float z - Z Axis Of Rotation
  // Brief: Rotate Current Matrix By Input Values
  /*************************************************************************/
  void TransformPipeline::Rotatef (float r, float x, float y, float z)
  {
    if (m_currentMatrix == MODEL)
    {
      m_modelMatrix [m_modelMatrix.size () - 1] *= glm::rotate (r * M_PI / 180, glm::vec3 (x, y, z));
    }
    else if (m_currentMatrix == VIEW)
    {
      m_viewMatrix [m_viewMatrix.size () - 1] *= glm::rotate (r * M_PI / 180, glm::vec3 (x, y, z));
    }

    m_matricesReady = false;
  }

  /*************************************************************************/
  // Method:    Rotatefv
  // FullName:  Framework::TransformPipeline::Rotatefv
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: float r - Angle in Degrees
  // Parameter: float * v - Axis Of Rotation
  // Brief: Rotate Current Matrix By Input Values
  /*************************************************************************/
  void TransformPipeline::Rotatefv (float r, float* v)
  {
    if (m_currentMatrix == MODEL)
    {
      m_modelMatrix [m_modelMatrix.size () - 1] *= glm::rotate (r * M_PI / 180, glm::vec3 (v [0], v [1], v [2]));
    }
    else if (m_currentMatrix == VIEW)
    {
      m_viewMatrix [m_viewMatrix.size () - 1] *= glm::rotate (r * M_PI / 180, glm::vec3 (v [0], v [1], v [2]));
    }

    m_matricesReady = false;
  }

  /*************************************************************************/
  // Method:    Ortho
  // FullName:  Framework::TransformPipeline::Ortho
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: float left - Left Edge
  // Parameter: float right - Right Edge
  // Parameter: float bottom - Bottom Edge
  // Parameter: float top - Top Edge
  // Parameter: float nearPlane - Near Plane of Viewer
  // Parameter: float farPlane - Far Plane of Viewer
  // Brief: Orthographic Projection Matrix for Viewer
  /*************************************************************************/
  void TransformPipeline::Ortho (float left, float right, float bottom, float top, float nearPlane /*= 0.0f*/, float farPlane /*= 1.0f*/)
  {
    m_projectionMatrix [m_projectionMatrix.size () - 1] = glm::ortho (left, right, bottom, top, nearPlane, farPlane);
  }

  /*************************************************************************/
  // Method:    Perspective
  // FullName:  Framework::TransformPipeline::Perspective
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: float fov - Field Of View Of Viewer
  // Parameter: float aspect - Aspect Ratio of Viewport
  // Parameter: float nearPlane - Near Plane of Viewer
  // Parameter: float farPlane - Far Plane of Viewer
  // Brief: Perspective Projection Matrix for Viewer
  /*************************************************************************/
  void TransformPipeline::Perspective (float fov, float aspect, float nearPlane, float farPlane)
  {
    m_projectionMatrix [m_projectionMatrix.size() - 1] = glm::perspective (fov, aspect, nearPlane, farPlane);
  }

  /*************************************************************************/
  // Method:    LookAt
  // FullName:  Framework::TransformPipeline::LookAt
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: glm::vec3 eye - Eye of Viewer
  // Parameter: glm::vec3 center - Point of View
  // Parameter: glm::vec3 up - Up Vector of Viewer
  // Brief: View Matrix for Viewer
  /*************************************************************************/
  void TransformPipeline::LookAt (glm::vec3 eye, glm::vec3 center, glm::vec3 up)
  {
    m_viewMatrix [m_viewMatrix.size () - 1] = glm::lookAt (eye, center, up);
  }

  /*************************************************************************/
  // Method:    UpdateMatrices
  // FullName:  Framework::TransformPipeline::UpdateMatrices
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Update Current Matrix Stack
  /*************************************************************************/
  void TransformPipeline::UpdateMatrices ()
  {
    if (!m_matricesReady)
    {
      m_modelViewMatrix = m_viewMatrix [m_viewMatrix.size () - 1] * m_modelMatrix [m_modelMatrix.size () - 1];

      m_modelViewProjectionMatrix = 
        m_projectionMatrix [m_projectionMatrix.size () - 1] *
        m_viewMatrix [m_viewMatrix.size () - 1] *
        m_modelMatrix [m_modelMatrix.size () - 1];
    }
  }

  /*************************************************************************/
  // Method:    UploadMatrices
  // FullName:  Framework::TransformPipeline::UploadMatrices
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Parameter: Shader * shader
  // Brief: Upload Matrices to GPU
  /*************************************************************************/
  void TransformPipeline::UploadMatrices (Shader* shader)
  {
    // TODO
  }

  void TransformPipeline::AddTransform (Transform* transform)
    {
    transformVectorMap [transform->gameObject->m_layer].push_back (transform);
  }

  /*************************************************************************/
  // Method:    Update
  // FullName:  Framework::TransformPipeline::Update
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Update the OpenGL Transform Pipeline
  /*************************************************************************/
  void TransformPipeline::Update(double dt)
  {
    unsigned i = 0;
    for (auto& it : transformVectorMap)
    {
      Camera::allCameras [i]->UpdateCamera ();
      for (auto& t : it.second)
      {
        t->Update_Matrices (dt);
      }
      ++i;
    }
  }

  /*************************************************************************/
  // Method:    PushMatrix
  // FullName:  Framework::TransformPipeline::PushMatrix
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Push Identity Matrix to Current Matrix Stack
  /*************************************************************************/
  void TransformPipeline::PushMatrix ()
  {
    if (m_currentMatrix == MODEL)
    {
      m_modelMatrix.push_back (m_modelMatrix [m_modelMatrix.size () - 1]);
    }
    else if (m_currentMatrix == VIEW)
    {
      m_viewMatrix.push_back (m_modelMatrix [m_modelMatrix.size () - 1]);
    }
    else if (m_currentMatrix == PROJECTION)
    {
      m_projectionMatrix.push_back (m_viewMatrix [m_viewMatrix.size () - 1]);
    }

    m_matricesReady = false;
  }

  /*************************************************************************/
  // Method:    PopMatrix
  // FullName:  Framework::TransformPipeline::PopMatrix
  // Access:    public 
  // Returns:   void
  // Qualifier:
  // Brief: Pop Matrix from Current Matrix Stack
  /*************************************************************************/
  void TransformPipeline::PopMatrix ()
  {
    if (m_currentMatrix == MODEL)
    {
      if (m_modelMatrix.size () > 1)
      {
        m_modelMatrix.pop_back ();
      }
    }
    else if (m_currentMatrix == VIEW)
    {
      if (m_viewMatrix.size () > 1)
      {
        m_viewMatrix.pop_back ();
      }
    }
    else if (m_currentMatrix == PROJECTION)
    {
      if (m_projectionMatrix.size () > 1)
      {
        m_projectionMatrix.pop_back ();
      }
    }

    m_matricesReady = false;
  }


  //////////////////////////////////////////////////////////////////////////
  // GETTORS
  //////////////////////////////////////////////////////////////////////////

  /*************************************************************************/
  // Method:    GetMatrixMode
  // FullName:  Framework::TransformPipeline::GetMatrixMode
  // Access:    public 
  // Returns:   int
  // Qualifier:
  // Brief: Get Current Matrix Mode
  /*************************************************************************/
  int TransformPipeline::GetMatrixMode ()
  {
    return m_currentMatrix;
  }

  /*************************************************************************/
  // Method:    GetModelMatrix
  // FullName:  Framework::TransformPipeline::GetModelMatrix
  // Access:    public 
  // Returns:   Matrix4x4
  // Qualifier:
  // Brief: Get Current Model Matrix in the Stack
  /*************************************************************************/
  Matrix4x4 TransformPipeline::GetModelMatrix ()
  {
    return m_modelMatrix [m_modelMatrix.size () - 1];
  }

  /*************************************************************************/
  // Method:    GetViewMatrix
  // FullName:  Framework::TransformPipeline::GetViewMatrix
  // Access:    public 
  // Returns:   Matrix4x4
  // Qualifier:
  // Brief: Get Current View Matrix in the Stack
  /*************************************************************************/
  Matrix4x4 TransformPipeline::GetViewMatrix ()
  {
    return m_viewMatrix [m_viewMatrix.size () - 1];
  }

  /*************************************************************************/
  // Method:    GetProjectionMatrix
  // FullName:  Framework::TransformPipeline::GetProjectionMatrix
  // Access:    public 
  // Returns:   Matrix4x4
  // Qualifier:
  // Brief: Get Current Projection Matrix in the Stack
  /*************************************************************************/
  Matrix4x4 TransformPipeline::GetProjectionMatrix ()
  {
    return m_projectionMatrix [m_projectionMatrix.size () - 1];
  }

  /*************************************************************************/
  // Method:    GetModelViewMatrix
  // FullName:  Framework::TransformPipeline::GetModelViewMatrix
  // Access:    public 
  // Returns:   Matrix4x4
  // Qualifier:
  // Brief: Get Model View Matrix
  /*************************************************************************/
  Matrix4x4 TransformPipeline::GetModelViewMatrix ()
  {
    return m_modelViewMatrix;
  }

  /*************************************************************************/
  // Method:    GetModelViewProjectionMatrix
  // FullName:  Framework::TransformPipeline::GetModelViewProjectionMatrix
  // Access:    public 
  // Returns:   Matrix4x4
  // Qualifier:
  // Brief: Get Model View Projection Matrix
  /*************************************************************************/
  Matrix4x4 TransformPipeline::GetModelViewProjectionMatrix ()
  {
    return m_modelViewProjectionMatrix;
  }

}
