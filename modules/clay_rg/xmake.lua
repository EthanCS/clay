target("clay_rg")
    set_kind("static")
    add_files("src/**.cpp")
    add_includedirs("include/", {public = true})
    add_deps("clay_gfx", "clay_core")
    set_toolchains("clang-cl")
target_end()