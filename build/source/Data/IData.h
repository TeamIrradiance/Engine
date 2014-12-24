/******************************************************************************/
/*!
 \file   IframeRate.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
 */
/******************************************************************************/
#pragma once
#include "json.h"


class IData
{
  virtual void DefineMeta() = 0;
};

namespace Framework
{

  class Resource : public ::IData
  {
    void DefineMeta (){}
    std::string m_name;
  };

}

