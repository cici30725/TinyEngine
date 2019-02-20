workspace "SDL_1"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["glad"] = "SDL_1/vendor/glad/include"

include "SDL_1/vendor/glad"

project "SDL_1"
	location "SDL_1"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "SDL_1/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/stb_image.cpp",
		"%{prj.name}/vendor/stb_image/stb_image.h"
	}


	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor/glm/glm",
		"%{prj.name}/vendor/SDL2/include",
		"%{prj.name}/src",
		"%{IncludeDir.glad}",
		"%{prj.name}/vendor/stb_image"
	}

	libdirs
	{
		"%{prj.name}/vendor/SDL2/lib/x64"
	}

	links 
	{ 
		"glad",
		"SDL2.lib",
		"SDL2main.lib"
	}

	filter "files:stb_image.cpp"
		flags "NoPCH" 

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

	filter "configurations:Debug"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		buildoptions "/MD"
		optimize "On"
