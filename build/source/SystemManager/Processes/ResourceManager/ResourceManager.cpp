/******************************************************************************/
/*!
 \file   ResourceManager.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief  Template for all proces classes
 */
/******************************************************************************/
#include <Precompiled.h>

namespace Framework
{
  //////////////////////////////////////////////////////////////////////////
  // STATIC VARIABLES
  //////////////////////////////////////////////////////////////////////////
  std::string ResourceManager::ROOT_DIRECTORY;



  void ResourceManager::VUpdate(const double dt)
  {

  }

  void ResourceManager::VInit()
  {
    ROOT_DIRECTORY = "Resources/";
    //Load_Resources ();
  }
  
  ResourceManager::ResourceManager()
  {
    std::hash<std::string> id;
    mName = std::string("resources");
    mProcessID = id(mName); //faster access with hash instead of string
    m_bActive = true; // skip when process is deactivated
    m_bInitialized = false; //debugging purposes if initialized
    m_bAttached = false; // check if process is attached to manager
    
  }

  ResourceManager:: ~ResourceManager()
  {

  }


  //Texture* ResourceManager::Get_Texture (std::string texName)
  //{
  //  for (auto& i : m_textureMap)
  //  {
  //    if (i.first == texName)
  //    {
  //      return i.second;
  //    }
  //  }

  //  std::cout << "NO TEXTURE WITH NAME " + texName + " FOUND. USING DEFAULT TEXTURE\n";
  //  return m_textureMap ["DEFAULT"];
  //}

  //Shader* ResourceManager::Get_Shader (std::string shaderName)
  //{
  //  for (auto& i : m_shaderMap)
  //  {
  //    if (i.first == shaderName)
  //    {
  //      return i.second;
  //    }
  //  }

  //  std::cout << "NO SHADER WITH NAME " + shaderName + " FOUND. USING DEFAULT SHADER\n";
  //  return m_shaderMap ["DEFAULT"];
  //}

  //void ResourceManager::Load_Shaders ()
  //{

  //}

  //void ResourceManager::Load_Textures ()
  //{

  //}

  //void ResourceManager::Load_Audio ()
  //{

  //}

}