/******************************************************************************/
/*!
\file   ShapeData.cpp
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#include <Precompiled.h>

namespace Framework
{

  ShapeData::ShapeData ()
  {
    m_numIndices = m_numVertices = 0;
    m_vertices.clear ();
    m_indices.clear ();
  }

}