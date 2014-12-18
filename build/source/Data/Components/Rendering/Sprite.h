//******************************************************************************/
//*!
// \file   Sprite.h
// \author Aji Suprana
// \par    Course: GAM250
// \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
// \brief
// */
//******************************************************************************/
#include "Components.h"
#include "MathLib.h"
namespace Component
{
//******************************************************************************/
//*!
// \macros   Sprite
// \brief   Sprite Component
// Notes: 
// */
//******************************************************************************/
  class Sprite: public BaseEngine::Component
  {
    void ToolInit();
    void Serialize();
    Sprite();
    ~Sprite();

    //DATA
    Vector2 size;
  };
}