set_languages("c99", "cxx20")
add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", { outputdir = ".vscode" })

add_repositories("clay-xrepo xrepo", {rootdir = os.scriptdir()})

add_requires("vulkansdk", "mimalloc", "spdlog", "libsdl 2.30.3", "stb", "rtm v2.3.1")
add_requires("vulkan-memory-allocator v3.1.0")
add_requires("glm", "tinyobjloader")

add_requires("daScript 0.4.10")
add_defines("DAS_FUSION=2", "DAS_DEBUGGER=0", "DAS_SMART_PTR_TRACKER=0", "DAS_SMART_PTR_MAGIC=0", "DAS_FREE_LIST=1")

includes("thirdparty")
includes("modules")
includes("tools")

target("clay")
    set_kind("binary")
    add_files("main.cpp")
    add_deps("whereami", "ShaderConductor-clay")
    add_deps("clay_core", "clay_app", "clay_gfx", "clay_image")
    add_packages("daScript")
    set_toolchains("msvc")

    after_build(function (target)
        os.cp("daslib", target:targetdir())
        os.cp("thirdparty/ShaderConductor-clay/bin/x86_64/ShaderConductor.dll", target:targetdir())
    end)
target_end()
