/******************************************************************************/
/*!
\file   Pipeline.cpp
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief  Template for all proces classes
*/
/******************************************************************************/

#include "Precompiled.h"

namespace Framework
{

  TransformPipeline::TransformPipeline ()
  {
    modelMatrix.push_back (glm::mat4 (1.0f));
    viewMatrix.push_back (glm::mat4 (1.0f));
    projectionMatrix.push_back (glm::mat4 (1.0f));

    modelViewMatrix = glm::mat4 (1.0f);
    modelViewProjectionMatrix = glm::mat4 (1.0f);
    matricesReady = true;
    currentMatrix = 0;
  }

  TransformPipeline::~TransformPipeline ()
  {
  }

  void TransformPipeline::LoadIdentity ()
  {
    if (currentMatrix == MODEL || currentMatrix == VIEW)
    {
      modelMatrix [modelMatrix.size () - 1] = glm::mat4 (1.0);
      viewMatrix [modelMatrix.size () - 1] = glm::mat4 (1.0);
    }
    else
    {
      projectionMatrix [viewMatrix.size () - 1] = glm::mat4 (1.0);
    }

    matricesReady = false;
  }

  void TransformPipeline::MatrixMode (int mode)
  {
    if (mode == MODEL || mode == VIEW || mode == PROJECTION)
    {
      currentMatrix = mode;
    }
  }

  void TransformPipeline::Translatef (float x, float y, float z)
  {
    if (currentMatrix == MODEL)
    {
      modelMatrix [modelMatrix.size () - 1] *= glm::translate (glm::vec3 (x, y, z));
    }
    else if (currentMatrix == VIEW)
    {
      viewMatrix [viewMatrix.size () - 1] *= glm::translate (glm::vec3 (-x, -y, -z));
    }

    matricesReady = false;
  }

  void TransformPipeline::Translatefv (float* v)
  {
    if (currentMatrix == MODEL)
    {
      modelMatrix [modelMatrix.size () - 1] *= glm::translate (glm::vec3 (v [0], v [1], v [2]));
    }
    else if (currentMatrix == VIEW)
    {
      viewMatrix [viewMatrix.size () - 1] *= glm::translate (glm::vec3 (-v [0], -v [1], -v [2]));
    }

    matricesReady = false;
  }

  void TransformPipeline::Scalef (float x, float y, float z)
  {
    if (currentMatrix == MODEL)
    {
      modelMatrix [modelMatrix.size () - 1] *= glm::scale (glm::vec3 (x, y, z));
    }
    else if (currentMatrix == VIEW)
    {
      viewMatrix [viewMatrix.size () - 1] *= glm::scale (glm::vec3 (x, y, z));
    }

    matricesReady = false;
  }

  void TransformPipeline::Scalef (float s)
  {
    if (currentMatrix == MODEL)
    {
      modelMatrix [modelMatrix.size () - 1] *= glm::scale (glm::vec3 (s, s, s));
    }
    else if (currentMatrix == VIEW)
    {
      viewMatrix [viewMatrix.size () - 1] *= glm::scale (glm::vec3 (s, s, s));
    }

    matricesReady = false;
  }

  void TransformPipeline::Scalefv (float* v)
  {
    if (currentMatrix == MODEL)
    {
      modelMatrix [modelMatrix.size () - 1] *= glm::scale (glm::vec3 (v [0], v [1], v [2]));
    }
    else if (currentMatrix == VIEW)
    {
      viewMatrix [viewMatrix.size () - 1] *= glm::scale (glm::vec3 (v [0], v [1], v [2]));
    }

    matricesReady = false;
  }

  void TransformPipeline::Rotatef (float r, float x, float y, float z)
  {
    if (currentMatrix == MODEL)
    {
      modelMatrix [modelMatrix.size () - 1] *= glm::rotate (r * M_PI / 180, glm::vec3 (x, y, z));
    }
    else if (currentMatrix == VIEW)
    {
      viewMatrix [viewMatrix.size () - 1] *= glm::rotate (r * M_PI / 180, glm::vec3 (x, y, z));
    }

    matricesReady = false;
  }

  void TransformPipeline::Rotatefv (float r, float* v)
  {

  }

  void TransformPipeline::Ortho (float left, float right, float bottom, float top, float nearPlane /*= 0.0f*/, float farPlane /*= 1.0f*/)
  {
    projectionMatrix [projectionMatrix.size () - 1] = glm::ortho (left, right, bottom, top, nearPlane, farPlane);
  }

  void TransformPipeline::Perspective (float fov, float aspect, float nearPlane, float farPlane)
  {
    projectionMatrix [projectionMatrix.size() - 1] = glm::perspective (fov, aspect, nearPlane, farPlane);
  }

  void TransformPipeline::LookAt (glm::vec3 eye, glm::vec3 center, glm::vec3 up)
  {
    viewMatrix [viewMatrix.size () - 1] = glm::lookAt (eye, center, up);
  }

  void TransformPipeline::UpdateMatrices ()
  {
    if (!matricesReady)
    {
      modelViewMatrix = viewMatrix [viewMatrix.size () - 1] * modelMatrix [modelMatrix.size () - 1];

      modelViewProjectionMatrix = 
        projectionMatrix [projectionMatrix.size () - 1] *
        viewMatrix [viewMatrix.size () - 1] *
        modelMatrix [modelMatrix.size () - 1];
    }
  }

  void TransformPipeline::UploadMatrices (Shader* shader)
  {
    // TODO
  }

  void TransformPipeline::Update ()
  {
    // TODO
  }

  void TransformPipeline::PushMatrix ()
  {
    if (currentMatrix == MODEL)
    {
      modelMatrix.push_back (modelMatrix [modelMatrix.size () - 1]);
    }
    else if (currentMatrix == VIEW)
    {
      viewMatrix.push_back (modelMatrix [modelMatrix.size () - 1]);
    }
    else if (currentMatrix == PROJECTION)
    {
      projectionMatrix.push_back (viewMatrix [viewMatrix.size () - 1]);
    }

    matricesReady = false;
  }

  void TransformPipeline::PopMatrix ()
  {
    if (currentMatrix == MODEL)
    {
      if (modelMatrix.size () > 1)
      {
        modelMatrix.pop_back ();
      }
    }
    else if (currentMatrix == VIEW)
    {
      if (viewMatrix.size () > 1)
      {
        viewMatrix.pop_back ();
      }
    }
    else if (currentMatrix == PROJECTION)
    {
      if (projectionMatrix.size () > 1)
      {
        projectionMatrix.pop_back ();
      }
    }

    matricesReady = false;
  }

  int TransformPipeline::GetMatrixMode ()
  {
    return currentMatrix;
  }


  //////////////////////////////////////////////////////////////////////////
  // GETTORS
  //////////////////////////////////////////////////////////////////////////

  Matrix4x4 TransformPipeline::GetModelMatrix ()
  {
    return modelMatrix [modelMatrix.size () - 1];
  }

  Matrix4x4 TransformPipeline::GetViewMatrix ()
  {
    return viewMatrix [viewMatrix.size () - 1];
  }

  Matrix4x4 TransformPipeline::GetProjectionMatrix ()
  {
    return projectionMatrix [projectionMatrix.size () - 1];
  }

  Matrix4x4 TransformPipeline::GetModelViewMatrix ()
  {
    return modelViewMatrix;
  }

  Matrix4x4 TransformPipeline::GetModelViewProjectionMatrix ()
  {
    return modelViewProjectionMatrix;
  }

}
