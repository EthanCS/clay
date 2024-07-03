target("clay_app")
    set_kind("static")
    add_files("src/**.cpp")
    add_includedirs("include/", {public = true})
    add_packages("libsdl")
    add_deps("clay_core")
    set_toolchains("clang-cl")
    add_packages("daScript")
target_end()
