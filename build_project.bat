@echo off
SETLOCAL

SET PREMAKE_PATH=premake\premake5.exe
SET VCPKG_PATH=path\to\vcpkg

echo Running Premake to setup the project...
"%PREMAKE_PATH%" vs2022

echo Build setup complete.
pause

ENDLOCAL
