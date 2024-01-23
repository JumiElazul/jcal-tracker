project "JCalClient"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"
   dependson "JCalCore"

   files 
   {
       "src/**.cpp",
       "src/**.h",
   }

   includedirs 
   {
       "src",
       "../vcpkg_installed/%{triplet}/include",
       "../JCalCore/include",
   }

   prebuildcommands { }

   filter "system:windows"
      defines { "JUMI_WINDOWS" }

      filter "configurations:Debug"
      symbols "On"
      libdirs 
      {
          "../JCalCore/bin/Debug",
          "../vcpkg_installed/%{triplet}/debug/lib",
      }
      links { "JCalCore-debug" }

      filter "configurations:Release"
      optimize "On"
      libdirs 
      {
          "../JCalCore/bin/Release",
          "../vcpkg_installed/%{triplet}/lib",
      }
      links { "JCalCore-release" }
