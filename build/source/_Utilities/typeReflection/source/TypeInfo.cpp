/******************************************************************************/
/*!
 \file   TypeInfo.cpp
 \author Aji Suprana
 \par    Course: GAM250
 \par    All content ?2014 DigiPen (USA) Corporation, all rights reserved.
 \brief  implementation of TypeInfo.h
 */
/******************************************************************************/
#include <Precompiled.h>
#include "TypeInfo.h"


TypeInfo typeInfos[ MAX_TYPE_INFOS ];
int typeInfosCount;

/******************************************************************************/
/*!
 \class   GetTypeByString( const char* typeNameCharPointer )
 \brief   get a type info with a string id
 */
/******************************************************************************/
TypeInfo* GetTypeByString( const char* typeNameCharPointer )
{
  for ( int i = 0; i < typeInfosCount; ++i )
  {
    //comparing typeNameCharPointer with all type infos
    if ( !strcmp( typeNameCharPointer, typeInfos[ i ].name ) )
    {
      //return type info if it's the same with current typeInfo
      return typeInfos + i;
    }
  }
 
  //Error check if there is nothing being found
  ErrorIf(true, "TypeInfo \" %s \" is not defined, add void DefineMeta() in %s data/Component" ,typeNameCharPointer,typeNameCharPointer);
 
  return NULL;
}

/******************************************************************************/
/*!
 \class   std::string Tokenize(const char* name)
 \brief   substract a string from a name
 */
/******************************************************************************/
std::string Tokenize(const char* name)
{
  std::string Name(name);  //turn name const char* into a string
  std::string temp;        //temporary holder holding reversed string, example "float" as "taolf"
  std::string returnThis;  //reverse it back to "float"
  int bracketCount = 0;


  //take the word before ':' sign or space.(remove namespaces or c++ keywords)
  for(int i = Name.size()-1; i >= 0; i--)
  {
    if(Name.at(i) == '>')
    {
      bracketCount++;
      continue;
    }

    if(Name.at(i) == '<')
    {
      bracketCount--;
      continue;
    }

    //break if it's a : or space
    if(bracketCount == 0)
    {
      if(Name.at(i) == ':' || Name.at(i) == ' ' || Name.at(i) == '_')
        break;
    }
    else
    {
      continue;
    }

    //only get the name, if < or > is not existing
    if(bracketCount == 0)
      temp.push_back(Name.at(i));
    else
      temp.clear();
  }

  //reverse temp
  for(int i = temp.size()-1; i >= 0; i--)
   returnThis.push_back(temp.at(i));
  return returnThis;
}