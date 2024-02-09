workspace "TheShowMan"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "TheShowMan"
    location "TheShowMan"
    kind "SharedLib"
    language "C++"

    targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
    objdir ("Bin-Int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "%{prj.name}/Source/pch.cpp"

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/Source",
        "%{prj.name}/External/SpdLog/include",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "TSM_PLATFORM_WINDOWS",
            "TSM_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../Bin/" .. outputdir .. "/Window")
        }

        filter "configurations:Debug"
            defines "TSM_DEBUG"
            symbols "On"

        filter "configurations:Release"
            defines "TSM_RELEASE"
            symbols "On"

        filter "configurations:Dist"
            defines "TSM_DIST"
            symbols "On"

project "Window"
            location "Window"
            kind "ConsoleApp"

            language "C++"
        
            targetdir ("Bin/" .. outputdir .. "/%{prj.name}")
            objdir ("Bin-Int/" .. outputdir .. "/%{prj.name}")
    
            files
            {
                "%{prj.name}/Source/**.h",
                "%{prj.name}/Source/**.cpp",
                "%{prj.name}/Source/Window.rc"
            }
    
            includedirs
            {
                "TheShowMan/External/SpdLog/include",
                "TheShowMan/Source"
            }
    
            buildcommands {
                "$(RC) -fo$(outputdir)/resource.res %{prj.name}/Source/Window.rc"
            }

            linkoptions {
                "/RESOURCE:$(outputdir)/resource.res"
            }

            links
            {
                "TheShowMan"
            }
    
            filter "system:windows"
            cppdialect "C++17"
            staticruntime "On"
            systemversion "latest"
    
            defines
            {
                "TSM_PLATFORM_WINDOWS",
            }

            filter "configurations:Debug"
                defines "TSM_DEBUG"
                symbols "On"
                kind "ConsoleApp"
    
            filter "configurations:Release"
                defines "TSM_RELEASE"
                symbols "On"
                kind "WindowedApp"
    
            filter "configurations:Dist"
                defines "TSM_DIST"
                symbols "On"
    