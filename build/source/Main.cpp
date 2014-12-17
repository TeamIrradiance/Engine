/******************************************************************************/
/*!
 \file   CProcess.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
#include <vld.h> // if it does give an error, Download visual leak detector
#include "IBaseEngine.h"
#include "ITypeReflection.h"
#include "TypeData.h"
#include "json.h"
#include "Serialization.h"



struct Vec3
{
  float x;
  float y;
  float z;
  void Serialize()
  {
    serializefn(x);
    serializefn(y);
    serializefn(z);
  }
};
struct Sprite
{
  Sprite(){};
  Vec3 position;
  Vec3 scale;
  void Serialize()
  {
    serializefn(position);
    serializefn(scale);
  }
};
#define CONNECT(Vec3,data)\

int main (void)
{
  EngineCore Engine;
  ////Create Managers
  Json::Value root; 
  BaseEngine::CProcessManager ProcessManager;


  Variant type_float ("float");
  typeData<float> info_float = typeData<float>();
  typemanagers.AddType(&type_float);
  DEFINE_TYPE(Vec3);
  {
  std::string type;\
  type = typeid( info_Vec3.data. x ).name();\
  typemanagers.types["Vec3"] ->Addmember( "x" ,type.c_str());\
  }
  ADDMEMBERS(Vec3,y);
  ADDMEMBERS(Vec3,z);
  DEFINE_TYPE(Sprite);
  ADDMEMBERS(Sprite,position);
  ADDMEMBERS(Sprite,scale);
  Sprite test;
  Vec3 data;

  prepareSerialize(test);
  //std::string type;
  //type = TokenizeType(typeid( info_Vec3.data.x).name(),&type);
  ///*ErrorIf( typemanagers.types.find(type) == typemanagers.types.end())*/ 
  //type_Vec3.Addmember( "x" ,&typemanagers.types[type]);

  
  ////Create Processes
  //AddProcess(new Process::TemplateProcess());
  //


  ////FILE *stream;
  ////AllocConsole();
  ////freopen_s( &stream,"CONOUT$", "w", stdout);
  ////std::cout << " WinMain Started" << std::endl;
  //  // Initialise GLFW
  //int success = glfwInit();
  //ErrorIf(!success, "Failed to initialize GLFW\n");
 
 
  //  // Open a window and create its OpenGL context 
  // // (In the accompanying source code, this variable is global) 
  //gEngineCore->g_glWindow = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL); 
  //ErrorIf(!gEngineCore->g_glWindow,"Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );

  //glfwMakeContextCurrent(gEngineCore->g_glWindow); // Initialize GLEW 
  //glewExperimental=true; // Needed in core profile 
  //success = glewInit();
  //ErrorIf(success != GLEW_OK, "Failed to initialize GLEW\n");

  //// Ensure we can capture the escape key being pressed below
  //glfwSetInputMode(gEngineCore->g_glWindow, GLFW_STICKY_KEYS, GL_TRUE);
 
  //Engine.Update();



  return 0;
}