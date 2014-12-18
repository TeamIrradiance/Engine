/******************************************************************************/
/*!
 \file   sampleComponent.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include "Components.h"

namespace Component
{
/******************************************************************************/
/*!
 \class   sampleComponent
 \brief   sampleComponent Component
 Notes: 
 */
/******************************************************************************/
//@@ Only this 4 function is allowed in component class
  class sampleComponent: public BaseEngine::Component
  {
  public:
    void ToolInit();
    void Serialize();
    sampleComponent();
    ~sampleComponent();

    //DATAS
  };
}