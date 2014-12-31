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
#include "IBaseEngine.h"

namespace Framework
{
/******************************************************************************/
/*!
 \class   CProcessManager()
 \brief   Default constructor
 */
/******************************************************************************/
  CProcessManager::CProcessManager()
  {
    //Assert if user try to initialize ProcessManager twice or recreate it
    ErrorIf(G_CORE->g_csProcessManager != NULL, "Processmanager has been created!");
    G_CORE->g_csProcessManager = this;
  }

/******************************************************************************/
/*!
 \class   ~CProcessManager()
 \brief   Default destructor
 */
/******************************************************************************/
  CProcessManager::~CProcessManager()
  {
    for(auto it : mProcessList)
    {
      delete it;
    }
  }

/******************************************************************************/
/*!
 \class   AddProcessf
 \brief   Add a process to process manager
 \param   pProcess* pointer to a Child Process
 */
/******************************************************************************/
  void CProcessManager::AddProcessf( CProcess* pProcess)
  {
    ErrorIf(pProcess == NULL, "%s process does not exist", pProcess->mName);
    mProcessList.push_back(pProcess);
  }

/******************************************************************************/
/*!
 \class   getProcess
 \brief   get a process from process manager
 \param   name
          std::string name of a process
 */
/******************************************************************************/
  CProcess* CProcessManager::getProcess(std::string name)
  {
    for(auto& it : mProcessList)
    {
      if(it->mName == name)
        return it;
    }
    return NULL;
  }

/******************************************************************************/
/*!
 \class   InitProcesses
 \brief   Init all process
 */
/******************************************************************************/
  void CProcessManager::InitProcesses()
  {
    for(auto& it : mProcessList)
    {
      it->VInit();
    }
  }

/******************************************************************************/
/*!
 \class   UpdateProcesses
 \brief   updating all existing processes
 \param   dt
          delta time per frame
 */
/******************************************************************************/
  void CProcessManager::UpdateProcesses(double dt)
  {
    for(auto& it : mProcessList)
    {
      it->VUpdate(dt);
    }
  }

/******************************************************************************/
/*!
 \class   RemoveProcess
 \brief   removing process from manager
 \param   process
          -process to delete
 */
/******************************************************************************/
  void CProcessManager::RemoveProcess(CProcess* process)
  {
    delete process;
    mProcessList.remove(process);
  }
}