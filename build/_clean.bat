@echo off

GOTO EndComment
/******************************************************************************/
/*!
 \file   _clean.bat
 \author Jack Chang
 \date   10/24/2014
 \par    All content 2014 DigiPen (USA) Corporation, all rights reserved.
 \brief
    Clear all unneeded files
 */
/******************************************************************************/
:EndComment

rm *.sdf
rm *.opensdf
rm *.sln
rm *.suo
rm *.vcxproj*
rmdir /S /Q source\vcproj
rmdir /S /Q obj
rmdir /S /Q bin
rmdir /S /Q ipch