package("graaf")
    set_kind("library", {headeronly = true})
    set_homepage("https://bobluppes.github.io/graaf/")
    set_description("A general-purpose lightweight C++ graph library")
    set_license("MIT")

    add_urls("https://github.com/bobluppes/graaf/archive/refs/tags/$(version).tar.gz",
             "https://github.com/bobluppes/graaf.git")

    add_versions("v1.1.1", "2829e160c44463763faed593bb5b62e9bdfa26554c1fe949f564f2ca622381ff")

    on_install(function (package)
        os.cp("include", package:installdir())
    end)

    on_test(function (package)
        assert(package:has_cxxtypes("graaf::directed_graph<int, float>", {configs = {languages = "c++20"}, includes = {"algorithm", "graaflib/graph.h"}}))
    end)