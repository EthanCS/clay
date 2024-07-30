target("model_viewer")
    set_kind("binary")
    add_files("src/**.cpp")
    add_deps("ShaderConductor-clay")
    add_deps("clay_core", "clay_app", "clay_gfx", "clay_image")
    add_packages("rtm")

    after_build(function (target)
        os.cp("thirdparty/ShaderConductor-clay/bin/x86_64/ShaderConductor.dll", target:targetdir())
    end)
target_end()
