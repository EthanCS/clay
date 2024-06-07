-- Proxy -----------------------------------------------
target("proxy")
    set_kind("headeronly")
    add_headerfiles("proxy/proxy.h")
    add_includedirs("proxy/", {public = true})
    add_rules("utils.install.cmake_importfiles")
    add_rules("utils.install.pkgconfig_importfiles")
target_end()
--------------------------------------------------------