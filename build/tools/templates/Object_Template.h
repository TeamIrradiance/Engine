/******************************************************************************/
/*!
 \file   sampleObject.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#include "Components.h"
//@@ REMEMBER TO INCLUDE NEW COMPONENT TO "IComponents.h"
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
  class sampleObject: public ::IData
  {
  public:
    sampleObject();
    ~sampleObject();
    void DefineMeta();

    //DATAS
  };
}