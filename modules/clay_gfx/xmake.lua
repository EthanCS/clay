target("clay_gfx")
    set_kind("static")
    add_files("src/**.cpp")
    add_includedirs("include/", {public = true})
    add_packages("vulkansdk")
    add_packages("vulkan-memory-allocator")
    add_packages("libsdl")
    add_packages("daScript")
    add_deps("proxy", "clay_core")
    set_toolchains("clang-cl")
    add_defines("CLAY_GFX_ENABLE", {public = true})
target_end()