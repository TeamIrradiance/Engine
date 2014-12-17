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
    "glew32d",
    "glew32sd",
  }
linkerR = { 
    "winmm",
    "glfw3dll",
    "glfw3",
    "glew32",
    "glew32s",
  }

solution "Irradiance"
  configurations { "Debug", "Release" }
  location "../"

project "Irradiance"
  targetname "Irradiance"
  location "../source/vcproj"
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
  }
  
  includedirs
  { 
	"../source/",
	"../source/**/",
	"../source/**/**/",
	"../source/**/**/**/",
	"../dependency/include/GL",
  "../dependency/include/glm",
  "../dependency/include/jsonlib"
  }
  
  libdirs
  { 
    "../wxWidgets-3.0.1/lib/vc_lib",
    "$(LibraryPath)",
    "$(DXSDK_DIR)/Lib/x86",
    "../dependency/lib",
  }
  
-- Debug Configuration 
  configuration "Debug"
  flags{ "Symbols" }
  buildoptions { "/MP" }
  defines { "_DEBUG", "_CRT_SECURE_NO_WARNINGS" ,"_CRTDBG_MAP_ALLOC"}
  links {linker}
  targetdir "../bin/debug"
  postbuildcommands
  { 
    "copy ..\\..\\dependency\\dll\\glew32.dll ..\\..\\bin\\debug\\",
    "copy ..\\..\\dependency\\dll\\glew32d.dll ..\\..\\bin\\debug\\",
    "copy ..\\..\\dependency\\dll\\glfw3.dll ..\\..\\bin\\debug\\",
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
    "copy ..\\..\\dependency\\dll\\glew32.dll ..\\..\\bin\\release\\",
    "copy ..\\..\\dependency\\dll\\glew32d.dll ..\\..\\bin\\release\\",
    "copy ..\\..\\dependency\\dll\\glfw3.dll ..\\..\\bin\\release\\",
  }
  
