set_languages("c99", "cxx20")
add_rules("mode.debug", "mode.release")

add_requires("flecs 3.2.11")
add_requires("vulkansdk", "mimalloc", "spdlog")

includes("modules")

target("test")
    set_kind("binary")
    add_files("main.cpp")
    add_deps("clay_core", "clay_gfx")
target_end()