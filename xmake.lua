add_rules("mode.debug", "mode.release")

includes("modules")

target("test")
    set_kind("binary")
    add_files("main.cpp")
    add_deps("clay_gfx")
target_end()