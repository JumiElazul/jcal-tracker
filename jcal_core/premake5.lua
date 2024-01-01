project "jcal_core"
   kind "SharedLib"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files 
   {
       "src/core/app_timer.cpp", 
       "src/core/app_timer.h", 
       "src/core/engine_core.cpp",
       "src/core/glfw_callback_context.cpp",
       "src/core/glfw_callback_context.h",
       "src/input/input_handler.cpp",
       "src/logger/logger.cpp",
       "src/window/window_handler.cpp",

        "include/jcal_core/core.h",
        "include/jcal_core/engine_core.h",
        "include/jcal_core/input_handler.h",
        "include/jcal_core/logger.h",
        "include/jcal_core/window_handler.h",
   }

   includedirs
   {
       "src",
       "include",
       "../vcpkg_installed/%{triplet}/include"
   }

   libdirs
   {
       "../vcpkg_installed/%{triplet}/lib",
       "../vcpkg_installed/%{triplet}/debug/lib"
   }

   filter "system:windows"
      defines { "JUMI_WINDOWS", "JUMI_EXPORT_API" }

   filter "configurations:Debug"
      symbols "On"
      links { "fmtd", "glad", "glfw3", "imguid", "spdlogd" }

   filter "configurations:Release"
      optimize "On"
      links { "fmt", "glad", "glfw3", "imgui", "spdlog" }

