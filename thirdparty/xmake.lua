-- proxy -----------------------------------------------
target("proxy")
    set_kind("headeronly")
    add_headerfiles("proxy/proxy.h")
    add_includedirs("proxy/", {public = true})
    add_rules("utils.install.cmake_importfiles")
    add_rules("utils.install.pkgconfig_importfiles")
target_end()
--------------------------------------------------------

-- whereami --------------------------------------------
target("whereami")
    set_kind("static")
    add_headerfiles("whereami/src/*.h")
    add_files("whereami/src/*.c")
    add_includedirs("whereami/src/", {public = true})
target_end()
--------------------------------------------------------

-- ShaderConductor -------------------------------------
target("ShaderConductor-clay")
    set_kind("headeronly")
    add_includedirs("ShaderConductor-clay/include/", {public = true})
    add_linkdirs("ShaderConductor-clay/lib/x86_64/", {public = true})
    add_links("ShaderConductor", {public = true})
    add_packages("daScript")
target_end()
--------------------------------------------------------