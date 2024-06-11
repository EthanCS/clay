package("quickjs-clay")
    set_homepage("https://bellard.org/quickjs/")
    set_description("QuickJS is a small and embeddable Javascript engine")

    add_urls("https://github.com/EthanCS/quickjs.git")
    add_versions("1.0.0", "c37574e43fdb3cb867cd5a9bf7ece815d4fa5b13")

    if is_plat("windows") then
        add_configs("shared", {description = "Build shared library.", default = true, type = "boolean", readonly = true})
    end

    if is_plat("linux", "macosx", "iphoneos", "cross") then
        add_syslinks("pthread", "dl", "m")
    elseif is_plat("android") then
        add_syslinks("dl", "m")
    end

    on_load("windows", function (package)
        if package:is_arch("x64") then
            package:add("deps", "mingw-w64")
        else
            package:add("deps", "llvm-mingw")
        end
    end)

    on_install("linux", "macosx", "iphoneos", "android", "mingw", "cross", function (package)
        io.writefile("xmake.lua", ([[
            add_rules("mode.debug", "mode.release")
            target("quickjs")
                set_kind("$(kind)")
                add_files("quickjs*.c", "cutils.c", "lib*.c")
                add_headerfiles("quickjs-libc.h")
                add_headerfiles("quickjs.h")
                add_installfiles("*.js", {prefixdir = "share"})
                set_languages("c99")
                add_defines("CONFIG_VERSION=\"%s\"", "_GNU_SOURCE")
                add_defines("CONFIG_BIGNUM")
                if is_plat("mingw") then
                    add_defines("__USE_MINGW_ANSI_STDIO")
                end
        ]]):format(package:version_str()))
        local configs = {}
        if package:is_plat("cross") then
            io.replace("quickjs.c", "#define CONFIG_PRINTF_RNDN", "")
        end
        import("package.tools.xmake").install(package, configs)
    end)

    on_install("windows", function (package)
        io.writefile("xmake.lua", ([[
            add_rules("mode.debug", "mode.release")
            target("quickjs")
                set_kind("$(kind)")
                add_files("quickjs*.c", "cutils.c", "lib*.c")
                add_headerfiles("quickjs-libc.h")
                add_headerfiles("quickjs.h")
                add_installfiles("*.js", {prefixdir = "share"})
                set_languages("c99")
                add_defines("CONFIG_VERSION=\"%s\"", "_GNU_SOURCE")
                add_defines("CONFIG_BIGNUM","__USE_MINGW_ANSI_STDIO", "__MINGW__COMPILE__")
                set_prefixname("")
                if is_kind("shared") then
                    add_shflags("-Wl,--output-def,quickjs.def")
                    add_shflags("-static-libgcc", "-static-libstdc++")
                    add_shflags("-Wl,-Bstatic -lpthread -Wl,-Bdynamic")
                else
                    set_extension(".lib")
                    add_syslinks("pthread")
                end
        ]]):format(package:version_str()))

        local arch_prev = package:arch()
        local plat_prev = package:plat()
        package:plat_set("mingw")
        package:arch_set(os.arch())

        import("package.tools.xmake").install(package)

        package:plat_set(plat_prev)
        package:arch_set(arch_prev)

        if package:config("shared") then
            import("utils.platform.gnu2mslib")

            gnu2mslib("quickjs.lib", "quickjs.def", {plat = package:plat(), arch = package:arch()})
            os.vcp("quickjs.lib", package:installdir("lib"))
            os.rm(package:installdir("lib", "quickjs.dll.a"))
        else
            local mingw = import("detect.sdks.find_mingw")()
            local bindir = mingw.bindir
            if mingw and bindir then
                os.vcp(path.join(bindir, "libgcc_s_seh-1.dll"), package:installdir("bin"))
                os.vcp(path.join(bindir, "libwinpthread-1.dll"), package:installdir("bin"))
                os.vcp(path.join(bindir, "libstdc++-6.dll"), package:installdir("bin"))
            end

            -- TODO: export .def and generate .lib
        end
    end)

    on_test(function (package)
        assert(package:has_cfuncs("JS_NewRuntime", {includes = "quickjs.h"}))
    end)
