target("clay_gfx")
    set_kind("static")
    add_files("src/*.cpp")
    add_includedirs("include/", {public = true})