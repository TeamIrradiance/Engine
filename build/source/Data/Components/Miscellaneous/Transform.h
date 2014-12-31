/******************************************************************************/
/*!
 \file   Transform.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include <Precompiled.h>
#include "Components.h"
#include "MathLib.h"

namespace Framework
{
/******************************************************************************/
/*!
 \class   Transform
 \brief   Transform Component
 Notes: 
 */
/******************************************************************************/
//@@ Only this 4 function is allowed in component class
  class Transform: public Component
  {
  public:
    Transform();
    ~Transform();

    void DefineMeta ();
    void Initialize ();

    Matrix4x4 GetModelMatrix ();
    Matrix4x4 GetModelViewProjectionMatrix ();

    void Translate (float x, float y, float z);
    void Translate (Vector3& vec);
    void Scale (float x, float y, float z);
    void Scale (float s);
    void Scale (Vector3& vec);
    void Rotate (float r, float x, float y, float z);
    void Rotate (float r, Vector3& vec);
    void Rotate (float r);

    //DATA
    Vector3 position;
    Vector3 scale;
    //Vector3 axis;
    float rotation;

    // 16 BYTE ALIGNMENT TO AVOID ACCESS VIOLATION
    void* operator new (size_t i)
    {
      return _mm_malloc (i, 16);
    }

    void operator delete (void* p)
    {
      _mm_free (p);
    }

    friend class TransformPipeline;

  private:
    Matrix4x4 m_modelMatrix;
    Matrix4x4 m_modelViewProjectionMatrix;

    void Update_Matrices (double dt);
  };
}