set_languages("c99", "cxx20")
add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", { outputdir = ".vscode" })

add_repositories("clay-xrepo xrepo", {rootdir = os.scriptdir()})

add_requires("vulkansdk", "mimalloc", "spdlog", "libsdl 2.30.3")
add_requires("quickjs-clay 1.0.0")

includes("thirdparty")
includes("modules")

target("test")
    set_kind("binary")
    add_files("main.cpp")
    add_deps("clay_core", "clay_app", "clay_gfx", "clay_js")
    set_toolchains("clang-cl")
    add_packages("quickjs-clay")
target_end()
