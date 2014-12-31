/******************************************************************************/
/*!
\file   Math_Defines.h
\author Aji Suprana
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#define  GLM_FORCE_RADIANS
#include <glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/random.hpp>
#include <glm/gtc/noise.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#pragma once

#ifndef M_PI
#define M_PI 3.1415f
#endif // !M_PI

#ifndef M_PI_2
#define M_PI_2 M_PI * 2
#endif // !M_PI_2

#ifndef M_PI_4
#define M_PI_4 M_PI_2 * 2
#endif // !M_PI_4

#ifndef EPSILON
#define EPSILON 0.0001f
#endif // !EPSILON

typedef glm::mat2 Matrix2x2;
typedef glm::mat3 Matrix3x3;
typedef glm::mat4 Matrix4x4;
