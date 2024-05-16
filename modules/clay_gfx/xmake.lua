target("clay_gfx")
    set_kind("shared")
    add_files("src/*.cpp")
    add_includedirs("include/", {public = true})