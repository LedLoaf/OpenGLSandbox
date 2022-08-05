--------------------------------------
----------Disable VCPKG---------------
--------------------------------------
require('vstudio')

local vs = premake.vstudio.vc2010

local function premakeVersionComment(prj)
    premake.w('<!-- Generated by Premake ' .. _PREMAKE_VERSION .. ' -->')
end

local function vcpkg(prj)
    premake.w('<VcpkgTriplet>x64-windows-static</VcpkgTriplet>')
    premake.w('<VcpkgEnabled>false</VcpkgEnabled>')
end

premake.override(premake.vstudio.vc2010.elements, "project", function(base, prj)
    local calls = base(prj)
    table.insertafter(calls, vs.xmlDeclaration, premakeVersionComment)
    return calls
end)

premake.override(premake.vstudio.vc2010.elements, "globals", function(base, prj)
    local calls = base(prj)
    table.insertafter(calls, vs.globals, vcpkg)
    return calls
end)

--------------------------------------
----------  MAIN ENTRY ---------------
--------------------------------------

-- OpenGL-Sandbox
workspace "OpenGL-Sandbox"
	architecture "x64"
	startproject "OpenGL-Sandbox"

	configurations
	{
		"Debug",
		"Release"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to OpenGL-Core
IncludeDir = {}
IncludeDir["GLFW"] = "vendor/GLFW/include"
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["ImGui"] = "vendor/imgui"
IncludeDir["glm"] = "vendor/glm"
IncludeDir["stb_image"] = "vendor/stb_image"

-- Projects
group "Dependencies"
	include "OpenGL-Core/vendor/GLFW"
	include "OpenGL-Core/vendor/Glad"
	include "OpenGL-Core/vendor/imgui"
group ""

include "OpenGL-Core"
include "OpenGL-Sandbox"

-- OpenGL-Examples
workspace "OpenGL-Examples"
    startproject "OpenGL-Examples"
    architecture "x64"
    startproject "OpenGL-Examples"

    configurations
    {
        "Debug",
        "Release"
    }

    flags
    {
        "MultiProcessorCompile"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to OpenGL-Core
IncludeDir = {}
IncludeDir["GLFW"] = "vendor/GLFW/include"
IncludeDir["Glad"] = "vendor/Glad/include"
IncludeDir["ImGui"] = "vendor/imgui"
IncludeDir["glm"] = "vendor/glm"
IncludeDir["stb_image"] = "vendor/stb_image"

-- Projects
group "Dependencies"
    includeexternal "OpenGL-Core/vendor/GLFW"
    includeexternal "OpenGL-Core/vendor/Glad"
    includeexternal "OpenGL-Core/vendor/imgui"
group ""

includeexternal "OpenGL-Core"
include "OpenGL-Examples"
