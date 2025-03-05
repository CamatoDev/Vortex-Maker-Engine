include "./Scripts/lua/config.lua"

workspace "VortexMakerEngine"
    configurations { "Debug", "Release" }
    platforms { "x64" }
    
    group "Core"
        include "./Core/Core"
        include "./Core/Logger"
        include "./Core/Unitest"
    group ""

    group "Engine"
        include "./Engine/VmEditor"
        include "./Engine/VortexMakerEngine"
    group ""

    group "Tests"
        include "./Tests/TestUnitest"
    group ""
