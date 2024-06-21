set_languages("c99", "cxx20")
add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", { outputdir = ".vscode" })

add_repositories("clay-xrepo xrepo", {rootdir = os.scriptdir()})

add_requires("vulkansdk", "mimalloc", "spdlog", "libsdl 2.30.3")
add_requires("daScript")

includes("thirdparty")
includes("modules")

target("test")
    set_kind("binary")
    add_files("main.cpp")
    add_deps("clay_core", "clay_app", "clay_gfx")
    set_toolchains("clang-cl")
target_end()

target("test_das")
    set_kind("binary")
    add_packages("daScript")
    add_files("test-das.cpp")
    set_toolchains("clang-cl")
target_end()