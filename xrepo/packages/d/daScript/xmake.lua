package("daScript")
    set_homepage("https://dascript.org/")
    set_description("daScript - high-performance statically strong typed scripting language")
    set_license("BSD-3-Clause")

    add_urls("https://github.com/GaijinEntertainment/daScript.git")
    add_versions("0.4.9", "2ded4ac42970171b14aff6b28ffb974fc10a18f0")

    add_deps("cmake")
    
    on_install(function (package)
        local configs = {
            -- "-DDAS_AOT_EXAMPLES_DISABLED=ON",
            -- "-DDAS_PROFILE_DISABLED=ON",
            -- "-DDAS_TUTORIAL_DISABLED=ON",
            -- "-DDAS_TESTS_DISABLED=ON",
        }
        table.insert(configs, "-DCMAKE_BUILD_TYPE=" .. (package:debug() and "Debug" or "Release"))

        import("package.tools.cmake").build(package, configs, {buildir = "build"})

        if package:is_plat("windows") then
                os.trycp("build/**.dll", package:installdir("bin"))
                os.trycp("build/**.lib", package:installdir("lib"))
        elseif package:is_plat("mingw") then
                os.trycp("build/**.dll", package:installdir("bin"))
                os.trycp("build/**.a", package:installdir("lib"))
        else
                os.trycp("build/*.so", package:installdir("bin"))
                os.trycp("build/*.so", package:installdir("lib"))
                os.trycp("build/*.a", package:installdir("lib"))
        end
        
        os.cp("include", package:installdir())
    end)

    on_test(function (package)
        assert(package:check_cxxsnippets({test = [[
            #include "daScript/daScriptC.h"
        ]]}, {configs = {languages = "c++17"}}))
    end)
package_end()