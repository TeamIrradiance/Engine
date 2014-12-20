@echo off

set /p objectName=Process Name (Audio, Graphics, Physics):

copy /y templates\Process_Template.cpp ..\source\SystemManager\Processes\%objectName%\%objectName%.cpp
copy /y templates\Process_Template.h ..\source\SystemManager\Processes\%objectName%\%objectName%.h

cd ..\premake
.\premake5 vs2013
pause