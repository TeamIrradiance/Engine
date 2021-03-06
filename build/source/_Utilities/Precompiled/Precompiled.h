///******************************************************************************/
///*!
// \par    Course: GAM200
// \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
// \par    Written by Aji Suprana
// */
///******************************************************************************/

//////////////////////////////////////////////////////////////////////////
// C LIBRARIES
//////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <cstring>
#include <stddef.h>
#include <cstdio>

//////////////////////////////////////////////////////////////////////////
// STL
//////////////////////////////////////////////////////////////////////////

#include <string>
#include <list>
#include <vector>
#include <map>
#include <unordered_map>
#include <map>
#include <utility>
#include <hash_map>
#include <algorithm>

//////////////////////////////////////////////////////////////////////////
// I / O
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

//////////////////////////////////////////////////////////////////////////
// MEMORY
//////////////////////////////////////////////////////////////////////////

#include <memory>

//////////////////////////////////////////////////////////////////////////
// HELPERS
//////////////////////////////////////////////////////////////////////////

#include <locale>
#include <functional>
#include <sstream>

//////////////////////////////////////////////////////////////////////////
// WINDOWS
//////////////////////////////////////////////////////////////////////////

#ifdef _WIN32

#include <windows.h>
#include <windowsx.h>

#endif // _WIN32

//////////////////////////////////////////////////////////////////////////
// GRAPHICS API
//////////////////////////////////////////////////////////////////////////

#include <glew.h>
#include <glut.h>
#include <glfw3.h>
#include <SOIL.h>
#include "Math_Defines.h"

//////////////////////////////////////////////////////////////////////////
// WRAPPERS
//////////////////////////////////////////////////////////////////////////

#include "GLContext.h"

//////////////////////////////////////////////////////////////////////////
// DEBUGGING
//////////////////////////////////////////////////////////////////////////

#include "IDebugAssertion.h"

//////////////////////////////////////////////////////////////////////////
// BASE CLASSES
//////////////////////////////////////////////////////////////////////////

#include "IData.h"
#include "IBaseEngine.h"
#include "IEngineCore.h"
#include "ITypeReflection.h"

//////////////////////////////////////////////////////////////////////////
// Objects
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// DATA
//////////////////////////////////////////////////////////////////////////

#include "Texcoord.h"
#include "MathLib.h"
#include "Shader.h"
#include "Texture.h"

//////////////////////////////////////////////////////////////////////////
// HELPERS
//////////////////////////////////////////////////////////////////////////

#include "ShapeData.h"
#include "ShapeGenerator.h"

//////////////////////////////////////////////////////////////////////////
// Components
//////////////////////////////////////////////////////////////////////////

#include "Components.h"
#include "Drawable.h"
#include "Transform.h"
#include "Camera.h"

//////////////////////////////////////////////////////////////////////////
// Sub Systems
//////////////////////////////////////////////////////////////////////////

#include "SpriteBatcher.h"
#include "TransformPipeline.h"
#include "RenderPipeline.h"

//////////////////////////////////////////////////////////////////////////
// Main Systems
//////////////////////////////////////////////////////////////////////////

#include "PhysicsProcess.h"
#include "GraphicsProcess.h"
#include "WindowProcess.h"
#include "ResourceManager.h"

//////////////////////////////////////////////////////////////////////////
