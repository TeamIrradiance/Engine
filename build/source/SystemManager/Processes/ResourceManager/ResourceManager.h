/******************************************************************************/
/*!
 \file   ResourceManager.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/

#include "IBaseEngine.h"

#ifndef _RESOURCE_MANAGER_H
#define _RESOURCE_MANAGER_H


/******************************************************************************/
/*!
 \class   ResourceManager
 \brief   Template to write other child processes
 Notes: Derived class ust have  Constructor with param:
        - string name
        - set m_bKill = false
        - set m_bActive = true
        - set m_bInitialized = false
        - set m_bAttached = false
 */
/******************************************************************************/
namespace Framework
{

  class ResourceManager : public CProcess
  {
  public:
    void VUpdate(const double dt);
    void VInit();
    ResourceManager();
    ~ResourceManager();

    Texture* Get_Texture (std::string texName);
    Shader* Get_Shader (std::string shaderName);

    static std::string ROOT_DIRECTORY;

  private:
    std::unordered_map <std::string, Texture*> m_textureMap;
    std::unordered_map <std::string, Shader*> m_shaderMap;

    void Load_Resources ();
    void Load_Shaders ();
    void Load_Textures ();
    void Load_Audio ();
  };
}

#endif // !_RESOURCE_MANAGER_H