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
  class Resource : public ::IData
  {
    void DefineMeta ();
    std::string m_name;
  };


  class ResourceManager : public CProcess
  {
  public:
    ResourceManager ();
    ~ResourceManager ();

    void VInit ();
    void VUpdate(const double dt);

    static std::string ROOT_DIRECTORY;

    template <typename T>
    T* LoadResource ();

  private:
    std::unordered_map <std::string, Resource*> m_resourceMap;

  };

  template <typename T>
  T* Framework::ResourceManager::LoadResource ()
  {

  }

}

#endif // !_RESOURCE_MANAGER_H