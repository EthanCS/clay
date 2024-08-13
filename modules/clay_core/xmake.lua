target("clay_core")
    set_kind("static")
    add_files("src/**.cpp")
    add_includedirs("include/", {public = true})
    add_packages("spdlog", "mimalloc", {public = true})
    add_packages("graaf")
    set_toolchains("clang-cl")
target_end()
