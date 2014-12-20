@echo off

set /p objectName=Component Name:
set /p type= Component Type (Audio, Graphics, Physics):

copy /y templates\Component_Template.cpp ..\source\Data\Components\%type%\%objectName%.cpp
copy /y templates\Component_Template.h ..\source\Data\Components\%type%\%objectName%.h

cd ..\premake
.\premake5 vs2013
pause