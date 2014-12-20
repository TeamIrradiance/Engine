@echo off

GOTO EndComment
/******************************************************************************/
/*!
 \file   _build_vs2013.bat
 \author Jack Chang
 \date   09/08/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Generate Visual Studio 2012 Project
 */
/******************************************************************************/
:EndComment

cd premake
.\premake5 vs2012
pause
