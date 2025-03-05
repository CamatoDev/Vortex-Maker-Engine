project "TestUnitest"
    kind "ConsoleApp"
    LangageInformations()
    staticruntime "off"

    BuildsInfos("%{prj.name}")

    files {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp"
    }

    includedirs {
        "./src/",
        libs.core.include,
        libs.logger.include,
        libs.unitest.include,
    }

    links {
        "Unitest",
        "Logger",
        "Core"
    }

    DefineApiInfo()

    filter "system:windows"
        systemversion "latest"
		optimize "off"
        -- entrypoint "WinMainCRTStartup"

        -- PostBuilds("Core", "%{prj.name}")
        -- PostBuilds("Logger", "%{prj.name}")
        -- PostBuilds("VortexMakerEngine", "%{prj.name}")
        -- PostBuilds("Unitest", "%{prj.name}")
    
    filter "system:macosx"

    filter "system:linux"

    filter "configurations:Debug"
        defines { "_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH" }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

    filter {}
