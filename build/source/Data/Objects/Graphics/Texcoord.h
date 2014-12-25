/******************************************************************************/
/*!
 \file   Texcoord.h
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/

#pragma once

namespace Framework
{


  /******************************************************************************/
  /*!
  \class   Texcoord
  \brief   Texcoord Object
  Notes:
  */
  /******************************************************************************/

  class Texcoord : public ::IData
  {
  public:
    Texcoord ();
    ~Texcoord ();
    void DefineMeta (){}

    Vector2 nw;
    Vector2 sw;
    Vector2 se;
    Vector2 ne;
  };
}