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
#include "IProcess.h"
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

  ////Create Managers
  //Json::Value root; 
  


  //Variant type_float ("float");
  //typeData<float> info_float = typeData<float>();
  //typemanagers.AddType(&type_float);
  //DEFINE_TYPE(Vec3);
  //{
  //std::string type;\
  //type = typeid( info_Vec3.data. x ).name();\
  //typemanagers.types["Vec3"] ->Addmember( "x" ,type.c_str());\
  //}
  //ADDMEMBERS(Vec3,y);
  //ADDMEMBERS(Vec3,z);
  //DEFINE_TYPE(Sprite);
  //ADDMEMBERS(Sprite,position);
  //ADDMEMBERS(Sprite,scale);
  //Sprite test;
  //Vec3 data;

  //prepareSerialize(test);

  //std::string type;
  //type = TokenizeType(typeid( info_Vec3.data.x).name(),&type);
  ///*ErrorIf( typemanagers.types.find(type) == typemanagers.types.end())*/ 
  //type_Vec3.Addmember( "x" ,&typemanagers.types[type]);

  
  ////Create Processes
  //
  //

  EngineCore Engine;
  Engine.settings.consoleActive = false;
  Engine.settings.fps_cap = 60;
  Engine.settings.windowsX = 500;
  Engine.settings.windowsY = 500;
  Engine.settings.application_name = "Irradiance";

  AddProcess(new Process::WindowProcess);

  Engine.Init();
  Engine.Update();



  return 0;
}