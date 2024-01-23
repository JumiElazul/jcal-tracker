workspace "JCalTracker"
   configurations { "Debug", "Release" }
   architecture "x64"
   platforms "x64"
   cppdialect "C++20"
   flags { "MultiProcessorCompile" }
   staticruntime "On"
   startproject "JCalClient"

   local function determine_triplet()
       if os.host() == "windows" then
           return "x64-windows-static"
       elseif os.host() == "linux" then
           return "x64-linux"
       else
           return "unsupported"
       end
   end
   triplet = determine_triplet()

   include "JCalCore/premake5.lua"
   include "JCalClient/premake5.lua"
