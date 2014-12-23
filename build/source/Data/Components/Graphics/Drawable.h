/******************************************************************************/
/*!
\file   Drawable.h
\author Manas Sudhir Kulkarni
\par    Course: GAM250
\par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
\brief
*/
/******************************************************************************/

#pragma once

namespace Framework
{
  class Drawable : public Component
  {

  public:
    virtual void DefineMeta () = 0;
    virtual void Initialize () = 0;

  protected:
    // TEMPORARY
    SpriteData* m_data;
    // std::string m_dataKey;

    void Register ();

  private:

  };
}