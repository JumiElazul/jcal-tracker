@echo off
SETLOCAL

echo Running command vcpkg install --triplet x64-windows-static
vcpkg install --triplet x64-windows-static
pause

ENDLOCAL
