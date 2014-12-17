/******************************************************************************/
/*!
 \file   CProcess.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include <Precompiled.h>
//#include "IEngineCore.h"
#pragma once
//forward declaration
struct EngineCore;

namespace BaseEngine
{
/******************************************************************************/
/*!
 \macros   AddProcess
 \brief   Add a process into the process manager
 Notes: 
 */
/******************************************************************************/
  #define AddProcess(a)\
  g_csEngineCore->g_csProcessManager->AddProcessf(a);

/******************************************************************************/
/*!
 \class   CProcess
 \brief   A base class for all processes
 Notes: Derived class ust have  Constructor with param:
        - string name
        - set m_bKill = false
        - set m_bActive = true
        - set m_bInitialized = false
        - set m_bAttached = false
 */
/******************************************************************************/
  class CProcess
  {
    friend class CProcessManager;

  public:
    virtual void VUpdate(const double dt) = 0;
    virtual void VInit() = 0;

  protected:
    std::string mName;  // for debugging purposes
    unsigned mProcessID; //faster access with hash instead of string
    bool m_bActive; // skip when process is deactivated
    bool m_bInitialized; //debugging purposes if initialized
    bool m_bAttached; // check if process is attached to manager

  public:
    //CProcess(std::string name,unsigned int order = 0){};
    virtual ~CProcess(){};

  public:
    std::string GetType(void) const {return mName;}
    bool IsActive(void){return m_bActive;}
    bool SetActive(bool b){ m_bActive = b;}
    bool IsAttached(void) {return m_bAttached;}
    bool IsInitialized(void) {return m_bAttached;}
  };

/******************************************************************************/
/*!
 \class   CProcessManager
 \brief   Managing all classes derived from CProcess
 */
/******************************************************************************/

  class CProcessManager
  {
  public:
    friend struct ::EngineCore;
    CProcessManager();
    ~CProcessManager();

  protected:
    typedef std::list<CProcess*> ProcessList;
    ProcessList mProcessList;

  public:
    void AddProcessf(CProcess* pProcess);
    CProcess* getProcess(std::string);
  private:
    void InitProcesses();
    void UpdateProcesses(double dt);
    void RemoveProcess(CProcess* process);
    int test;
  };
}