set_languages("c99", "cxx20")
add_rules("mode.debug", "mode.release")

add_requires("vulkansdk", "mimalloc", "spdlog", "libsdl 2.30.3")

add_rules("plugin.compile_commands.autoupdate", { outputdir = ".vscode" })

includes("modules")

target("test")
    set_kind("binary")
    add_files("main.cpp")
    add_deps("clay_core", "clay_app", "clay_gfx")
target_end()