@echo off

set /p objectName=Helper Class Name:
set /p type= Class Type (Audio, Graphics, Physics, Resource):

copy /y templates\Object_Template.cpp ..\source\SystemManager\Processes\%type%\Helpers\%objectName%.cpp
copy /y templates\Object_Template.h ..\source\SystemManager\Processes\%type%\Helpers\%objectName%.h

cd ..\premake
.\premake5 vs2013
pause