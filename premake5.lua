workspace "HikaruEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "HikaruEngine/Thirdparty/glfw/include"

include "HikaruEngine/Thirdparty/glfw"

project "HikaruEngine"
	location "HikaruEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "hkpch.hpp"
	pchsource "HikaruEngine/Source/hkpch.cpp"

	files
	{
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/Source",
		"%{prj.name}/Thirdparty",
		"%{IncludeDir.GLFW}",		
		"%{prj.name}/Thirdparty/imgui/include"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}
	
	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HK_PLATFORM_WINDOWS",
			"HK_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.hpp",
		"%{prj.name}/Source/**.cpp"
	}

	includedirs
	{
		"HikaruEngine/Thirdparty/glfw/include",
		"HikaruEngine/Thirdparty", 
		"HikaruEngine/Thirdparty/imgui/include",
		"HikaruEngine/Source"
	}

	links
	{
		"HikaruEngine"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"HK_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "HK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "HK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "HK_DIST"
		optimize "On"