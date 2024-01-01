project "jcal_client"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files 
   {
       "src/application/main.cpp"
   }

   includedirs 
   {
       "../jcal_core/include",
       "src"
   }

   links { "jcal_core" }

   filter "system:windows"
      defines { "JUMI_WINDOWS" }

      filter "configurations:Debug"
      symbols "On"
      prebuildcommands
      {
          "{ECHO} Copying jcal-core.dll from %{wks.location}jcal_core/bin/%{cfg.buildcfg}/jcal_core.dll to %{cfg.targetdir}",
          "{COPY} %{wks.location}jcal_core/bin/%{cfg.buildcfg}/jcal_core.dll %{cfg.targetdir}"
      }

      filter "configurations:Release"
      optimize "On"
      prebuildcommands
      {
          "{ECHO} Copying jcal-core.dll from %{wks.location}jcal_core/bin/%{cfg.buildcfg}/jcal_core.dll to %{cfg.targetdir}",
          "{COPY} %{wks.location}jcal_core/bin/%{cfg.buildcfg}/jcal_core.dll %{cfg.targetdir}"
      }
