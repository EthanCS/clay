target("clay_image")
    set_kind("static")
    add_files("src/**.cpp")
    add_includedirs("include/", {public = true})
    add_deps("clay_core")
    set_toolchains("clang-cl")
    add_packages("daScript", "stb")
target_end()
