--[[
/******************************************************************************/
/*!
 \file   premake5.lua
 \author Aji Suprana
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
]]
linker = { 
    "winmm",
    "glfw3dll",
    "glfw3",
    "glew32",
    "SOIL",
    "opengl32",
  }
linkerR = { 
    "winmm",
    "glfw3dll",
    "glfw3",
    "glew32",
    "SOIL",
    "opengl32",
  }

solution "Irradiance"
  configurations { "Debug", "Release" }
  location "../"

project "Irradiance"
  targetname "Irradiance"
  location "."
  language "C++"
  objdir "../obj"
  kind "WindowedApp"
  pchheader "Precompiled.h"
  pchsource "../source/_Utilities/Precompiled/Precompiled.cpp"
  
  -- source files
  files
  {
    "../source/**.h",
    "../source/**.cpp",
    "**.c",
  }
  
  includedirs
  { 
	"../source**",
	"../dependency/include/GL**",
  "../dependency/include/jsonlib"
  }
  
  libdirs
  { 
    "../dependency/lib/GL",
  }
  
-- Debug Configuration 
  configuration "Debug"
  flags{ "Symbols" }
  defines { "_DEBUG", "_CRT_SECURE_NO_WARNINGS" ,"_CRTDBG_MAP_ALLOC"}
  links {linker}
  targetdir "../bin/debug"
  postbuildcommands
  {
    "copy ..\\dependency\\lib\\GL\\glfw3.dll ..\\bin\\debug\\",
    "copy ..\\dependency\\lib\\GL\\glew32.dll ..\\bin\\debug\\",
  }


-- Release Configuration 
  configuration "Release"
    flags{ "Symbols" }
    buildoptions { "/MDd" }
    --optimize "Full"
    defines { "NDEBUG"  , "_CRT_SECURE_NO_WARNINGS" ,"_CRTDBG_MAP_ALLOC"} 
    links{linkerR}
    targetdir "../bin/release"
    postbuildcommands
    {
      "copy ..\\dependency\\lib\\GL\\glfw3.dll ..\\bin\\debug\\",
      "copy ..\\dependency\\lib\\GL\\glew32.dll ..\\bin\\debug\\",
      "copy ..\\dependency\\lib\\GL\\freetype6.dll ..\\bin\\debug\\",
      "copy ..\\dependency\\lib\\GL\\glut32.dll ..\\bin\\debug\\",
    }
  
