workspace "jcal-tracker"
   configurations { "Debug", "Release" }
   architecture "x64"
   platforms "x64"
   cppdialect "C++20"
   flags { "MultiProcessorCompile" }
   staticruntime "On"

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

   include "jcal_core/premake5.lua"
   include "jcal_client/premake5.lua"
