project "JCalCore"
   kind "StaticLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files 
   {
       "src/**.cpp",
       "src/**.h",
   }

   includedirs
   {
       "src",
       "include",
       "../vcpkg_installed/%{triplet}/include"
   }

   filter "system:windows"
      defines { "JUMI_WINDOWS", "GLFW_INCLUDE_NONE" }

   filter "configurations:Debug"
      symbols "On"
      targetname "JCalCore-debug"
      libdirs 
      {
          "../vcpkg_installed/%{triplet}/debug/lib",
      }
      links { "fmtd", "imguid", "glad", "glfw3" }

   filter "configurations:Release"
      optimize "On"
      targetname "JCalCore-release"
      libdirs 
      {
          "../vcpkg_installed/%{triplet}/lib" 
      }
      links { "fmt", "imgui", "glad", "glfw3" }
