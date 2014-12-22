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
  enum RESOURCE_TYPE
  {
    R_TEXTURE,
    R_SHADER,
    R_AUDIO,
  };


  class ResourceManager : public CProcess
  {
  public:
    ResourceManager ();
    ~ResourceManager ();

    void VInit ();
    void VUpdate(const double dt);

    static std::string RESOURCE_DIRECTORY;

    static Resource* LoadResource (std::string resourceName, unsigned resourceType);

  private:
    void Load_Resources ();
    void Load_Shaders ();
    void Load_Textures ();

    static std::unordered_map <RESOURCE_TYPE, std::unordered_map <std::string, Resource*>> m_resourceMap;
    static std::string SHADER_DIRECTORY;
    static std::string TEXTURE_DIRECTORY;

  };

}

#endif // !_RESOURCE_MANAGER_H