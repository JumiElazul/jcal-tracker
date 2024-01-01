workspace "jcal-tracker"
   configurations { "Debug", "Release" }
   architecture "x64"
   platforms "x64"
   cppdialect "C++20"
   flags { "MultiProcessorCompile" }
   staticruntime "On"

   include "jcal_core/premake5.lua"
   include "jcal_client/premake5.lua"
