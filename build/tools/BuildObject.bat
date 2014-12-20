@echo off

set /p objectName=Object Name:
set /p type= Object Type (Audio, Graphics, Physics):

copy /y templates\Object_Template.cpp ..\source\Data\Objects\%type%\%objectName%.cpp
copy /y templates\Object_Template.h ..\source\Data\Objects\%type%\%objectName%.h

cd ..\premake
.\premake5 vs2013
pause