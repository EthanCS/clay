require fio
require math
require clay_app
require clay_gfx
require ShaderConductor

let MAX_FRAMES_IN_FLIGHT = 3
let title = "Hello Constant Buffer"

struct Vertex
    position: float2
    color: float3

struct MyBuffer
    model: float4x4
    view: float4x4
    proj: float4x4

let vertices = [[auto   [[Vertex position = float2(-0.5f, -0.5f),   color = float3(1.0f, 0.0f, 0.0f)]];
                        [[Vertex position = float2(0.5f, -0.5f),    color = float3(0.0f, 1.0f, 0.0f)]];
                        [[Vertex position = float2(0.5f, 0.5f),     color = float3(0.0f, 0.0f, 1.0f)]];
                        [[Vertex position = float2(-0.5f, 0.5f),    color = float3(1.0f, 1.0f, 1.0f)]]
                ]]

let indices = [[auto uint16(0); uint16(1); uint16(2); uint16(2); uint16(3); uint16(0)]]

var window = [[Window]]

var swapchain = [[HSwapchain]]
var swapchain_width = 1280u
var swapchain_height = 720u

var hello_vs = [[HShader]]
var hello_fs = [[HShader]]

var render_pass_layout = [[RenderPassLayout]]
var pipeline = [[HGraphicsPipeline]]
var pipeline_layout = [[HPipelineLayout]]
var descriptor_set_layout = [[HDescriptorSetLayout]]

var command_pool = [[HCommandPool]]

var index_buffer = [[HBuffer]]
var vertex_buffer = [[HBuffer]]

/////////////////////////////////////////////////////////////////
// Per frame data
var current_frame = 0u

var command_buffers : array<HCommandBuffer>

var uniform_buffers : array<HBuffer>
var descriptor_sets : array<HDescriptorSet>

var in_flight_fences : array<HFence>
var image_available_semaphores : array<HSemaphore>
var render_finished_semaphores : array<HSemaphore>

var swapchain_framebuffers : array<HFramebuffer>

[export]
def main
    init(window, [[WindowConfig title = title, width = 1280u, height = 720u]])
    var backend = [[InitBackendOptions backend_type = BackendType Vulkan, window = window.platform_handle, app_name = title, debug = true]]
    let init = init(backend)
    on_init()
    while !window.requested_exit
        handle_events(window)
        on_update()
    on_destroy()

def on_init()
    // Load shaders
    fopen("test/gfx/hello_world_cb/vert.hlsl", "rb") <| $ ( f )
        if f != null
            fseek(f, int64(0), seek_end)
            let size = ftell(f)
            let data = fread(f)       
            var source_desc = [[CompilerSourceDesc source = data, fileName = "vert.hlsl", entryPoint = "main", stage = ShaderConductor::ShaderStage VertexShader]]
            var target_desc = [[CompilerTargetDesc language = ShadingLanguage SpirV]]
            var option = MakeCompilerOptions()
            let result = Compile(source_desc, option, target_desc)
            hello_vs = create_shader([[CreateShaderOptions code = result.target.Data, code_size = result.target.Size]])
            fclose(f)
    fopen("test/gfx/hello_world_cb/frag.hlsl", "rb") <| $ ( f )
        if f != null
            fseek(f, int64(0), seek_end)
            let size = ftell(f)
            let data = fread(f)    
            var source_desc = [[CompilerSourceDesc source = data, fileName = "frag.hlsl", entryPoint = "main", stage = ShaderConductor::ShaderStage PixelShader]]
            var target_desc = [[CompilerTargetDesc language = ShadingLanguage SpirV]]
            var option = MakeCompilerOptions()
            let result = Compile(source_desc, option, target_desc)
            hello_fs = create_shader([[CreateShaderOptions code = result.target.Data, code_size = result.target.Size]])
            fclose(f)

    // Render pass layout
    render_pass_layout.colors[0] = [[ColorAttachmentDesc 
        format = Format B8G8R8A8_UNORM, 
        layout = ImageLayout PresentSrc, 
        load_op = LoadAction Clear]]
    
    // Create descriptor set layout
    var descriptor_set_layout_options = [[CreateDescriptorSetLayoutOptions]]
    add_binding(descriptor_set_layout_options, DescriptorType UniformBuffer, 0u, 1u, "MyBuffer")
    descriptor_set_layout = create_descriptor_set_layout(descriptor_set_layout_options)

    // Create pipeline
    var pipeline_layout_options = [[CreatePipelineLayoutOptions]]
    add_descriptor_set_layout(pipeline_layout_options, descriptor_set_layout)
    pipeline_layout = create_pipeline_layout(pipeline_layout_options)

    var pipeline_options = [[CreateGraphicsPipelineOptions name = "triangle", layout = pipeline_layout]]
    pipeline_options.vertex_shader = [[ShaderInfo compiled_shader = hello_vs, entry_func = "main"]]
    pipeline_options.pixel_shader = [[ShaderInfo compiled_shader = hello_fs, entry_func = "main"]]

    reset(pipeline_options.graphics_state)
    set_vertex_buffer_binding(pipeline_options.graphics_state, uint8(0), uint16(typeinfo(sizeof type<Vertex>)))
    set_vertex_buffer_attribute(pipeline_options.graphics_state, uint8(0), uint8(0), uint16(typeinfo(offsetof<position> type<Vertex>)), Format R32G32_SFLOAT)
    set_vertex_buffer_attribute(pipeline_options.graphics_state, uint8(0), uint8(1), uint16(typeinfo(offsetof<color> type<Vertex>)), Format R32G32B32_SFLOAT)
    pipeline_options.graphics_state.depth_test_enabled = false
    pipeline_options.graphics_state.render_pass_layout = render_pass_layout
    pipeline = create_graphics_pipeline(pipeline_options)

    // Command
    command_pool = create_command_pool(QueueType Graphics)
    resize(command_buffers, MAX_FRAMES_IN_FLIGHT)
    for i in range(0, MAX_FRAMES_IN_FLIGHT)
        command_buffers[i] = allocate_command_buffer(command_pool)
    
    // Sync objects
    resize(in_flight_fences, MAX_FRAMES_IN_FLIGHT)
    resize(image_available_semaphores, MAX_FRAMES_IN_FLIGHT)
    resize(render_finished_semaphores, MAX_FRAMES_IN_FLIGHT)
    for i in range(0, MAX_FRAMES_IN_FLIGHT)
        in_flight_fences[i] = create_fence(true)
        image_available_semaphores[i] = create_semaphore()
        render_finished_semaphores[i] = create_semaphore()
    
    // Swapchain
    create_swapchain(window.width, window.height)
    
    let uniform_buffer_size = typeinfo(sizeof type<MyBuffer>)
    resize(uniform_buffers, MAX_FRAMES_IN_FLIGHT)
    for i in range(0, MAX_FRAMES_IN_FLIGHT)
        uniform_buffers[i] = create_buffer([[CreateBufferOptions 
            size = uint64(uniform_buffer_size), 
            usage = BufferUsage UniformBuffer, 
            memory_usage = MemoryUsage CpuToGpu,
            exclusive = true]])

    // Descriptor set
    resize(descriptor_sets, MAX_FRAMES_IN_FLIGHT)
    for i in range(0, MAX_FRAMES_IN_FLIGHT)
        descriptor_sets[i] = create_descriptor_set([[CreateDescriptorSetOptions layout = descriptor_set_layout]])
        var update_info = [[UpdateDescriptorSetOptions]]
        bind_buffer(update_info, 0u, uniform_buffers[i])
        update_descriptor_set(descriptor_sets[i], update_info)

    // Buffers
    create_index_buffer()
    create_vertex_buffer()

def on_update()
    draw_frame()

def on_destroy()
    device_wait_idle()
    shutdown()
    shutdown(window)

def draw_frame()
    unsafe 
        wait_for_fence(in_flight_fences[current_frame], true, uint64(-1))

        let acquire_swapchain = acquire_next_image(swapchain, [[AcquireNextImageOptions time_out = uint64(-1), semaphore = image_available_semaphores[current_frame]]])

        if acquire_swapchain.status == SwapchainStatus OutOfDate
            recreate_swapchain()
            return

        update_uniform_buffer(current_frame)

        reset_fences(addr(in_flight_fences[current_frame]), 1)

        reset_command_buffer(command_buffers[current_frame], false)
        record_commands(command_buffers[current_frame], uint(acquire_swapchain.image_index))

        var submit_options = [[QueueSubmitOptions]]
        submit_options.command_buffers = addr(command_buffers[current_frame])
        submit_options.num_command_buffers = 1u
        submit_options.wait_semaphores = addr(image_available_semaphores[current_frame])
        submit_options.num_wait_semaphores = 1u
        submit_options.signal_semaphores = addr(render_finished_semaphores[current_frame])
        submit_options.num_signal_semaphores = 1u
        submit_options.wait_dst_stage = PipelineStage ColorAttachmentOutput
        submit_options.fence = in_flight_fences[current_frame]
        queue_submit(QueueType Graphics, submit_options)

        var present_options = [[QueuePresentOptions]]
        present_options.swapchain = swapchain
        present_options.image_index = uint(acquire_swapchain.image_index)
        present_options.wait_semaphores = addr(render_finished_semaphores[current_frame])
        present_options.num_wait_semaphores = 1u
        let present_status = queue_present(present_options)

        if present_status == SwapchainStatus OutOfDate || present_status == SwapchainStatus Suboptimal || window.resized
            window.resized = false
            recreate_swapchain()
        elif present_status != SwapchainStatus Success
            print("failed to present\n")
            
        current_frame = (current_frame + 1u) % uint(MAX_FRAMES_IN_FLIGHT)

def update_uniform_buffer(image_index: uint)
    var data = map_buffer(uniform_buffers[image_index])
    let aspect = float(swapchain_width) / float(swapchain_height)
    unsafe
        var my_buffer = [[MyBuffer]]
        my_buffer.model = identity4x4()
        my_buffer.view = look_at(float3(2.0f, 2.0f, 2.0f), float3(0.0f, 0.0f, 0.0f), float3(0.0f, 0.0f, 1.0f))
        my_buffer.proj = persp_forward(45.0f * PI / 180.0f, aspect, 0.1f, 10.0f)
        memcpy(data, addr(my_buffer), typeinfo(sizeof type<MyBuffer>))
    unmap_buffer(uniform_buffers[image_index])

def record_commands(cb: HCommandBuffer; image_index: uint)
    cmd_begin(cb, false)
    var render_pass = [[CmdBeginRenderPassOptions]]
    render_pass.framebuffer = swapchain_framebuffers[image_index]
    render_pass.render_pass_layout = render_pass_layout
    render_pass.extent = [[uint[2] swapchain_width; swapchain_height]]
    render_pass.clear = true
    render_pass.clear_values[0].color =  [[float[] 1.0; 1.0; 1.0; 1.0]]
    cmd_begin_render_pass(cb, render_pass)
    cmd_bind_graphics_pipeline(cb, pipeline)
    cmd_set_viewport(cb, [[CmdSetViewportOptions x = 0.0, y = 0.0, width = float(swapchain_width), height = float(swapchain_height), min_depth = 0.0, max_depth = 1.0]])
    cmd_set_scissor(cb, [[CmdSetScissorOptions offset = [[int[2] 0; 0]], extent = [[uint[2] swapchain_width; swapchain_height]]]])
    cmd_bind_vertex_buffer(cb, [[CmdBindVertexBufferOptions binding = 0u, buffer = vertex_buffer, offset = 0u]])
    cmd_bind_index_buffer(cb, [[CmdBindIndexBufferOptions buffer = index_buffer, offset = 0u, index_type = IndexType Uint16]])
    unsafe
        cmd_bind_descriptor_sets(cb, [[CmdBindDescriptorSetsOptions layout = pipeline_layout, bind_point = PipelineBindPoint Graphics, first_set = 0u, sets = addr(descriptor_sets[image_index]), num_sets = 1u]])
    cmd_draw_indexed(cb, [[CmdDrawIndexedOptions index_count = uint(length(indices)), instance_count = 1u, first_index = 0u, vertex_offset = 0, first_instance = 0u]])
    cmd_end_render_pass(cb)
    cmd_end(cb)

def recreate_swapchain()
    device_wait_idle()
    for fb in swapchain_framebuffers
        destroy_framebuffer(fb)
    destroy_swapchain(swapchain)
    create_swapchain(window.width, window.height)

def create_swapchain(width: uint; height: uint)
    swapchain = create_swapchain([[CreateSwapchainOptions width = width, height = height, vsync = true, format = Format B8G8R8A8_UNORM]])
    let num_images = int(get_swapchain_image_count(swapchain))
    resize(swapchain_framebuffers, num_images)
    for i in range(0, num_images)
        var option = [[CreateFramebufferOptions]]
        option.width = width
        option.height = height
        option.color_attachments[0] = [[TextureViewDesc 
            texture = get_swapchain_back_buffer(swapchain, uint(i)), 
            view_type = TextureViewType Texture2D,
            aspect_flags = TextureAspect Color,
            format = Format Undefined,
            base_mip_level = uint8(0),
            level_count = uint8(1),
            base_array_layer = uint8(0),
            layer_count = uint8(1),
            component_r = TextureComponentSwizzle Identity,
            component_g = TextureComponentSwizzle Identity,
            component_b = TextureComponentSwizzle Identity,
            component_a = TextureComponentSwizzle Identity]]
        option.render_pass_layout = render_pass_layout
        swapchain_framebuffers[i] = create_framebuffer(option)
    swapchain_width = width
    swapchain_height = height

def copy_buffer(src_buffer: HBuffer; dst_buffer: HBuffer; size: uint64)
    var cb = allocate_command_buffer(command_pool)
    cmd_begin(cb, true)
    cmd_copy_buffer(cb, [[CmdCopyBufferOptions 
        src_buffer = src_buffer, src_offset = uint64(0), 
        dst_buffer = dst_buffer, dst_offset = uint64(0), 
        size = size]])
    cmd_end(cb)

    var submit_options = [[QueueSubmitOptions]]
    unsafe
        submit_options.command_buffers = addr(cb)
    submit_options.num_command_buffers = 1u
    queue_submit(QueueType Graphics, submit_options)
    queue_wait_idle(QueueType Graphics)
    free_command_buffer(cb)

def create_vertex_buffer
    let buffer_size = length(vertices) * typeinfo(sizeof type<Vertex>)
    
    var staging_buffer = create_buffer([[CreateBufferOptions 
        size = uint64(buffer_size), 
        usage = BufferUsage TransferSrc, 
        memory_usage = MemoryUsage CpuToGpu,
        exclusive = true]])
    var data = map_buffer(staging_buffer)
    unsafe 
        memcpy(data, addr(vertices), buffer_size)
    unmap_buffer(staging_buffer)

    vertex_buffer = create_buffer([[CreateBufferOptions 
        size = uint64(buffer_size), 
        usage = BufferUsage VertexBuffer | BufferUsage TransferDst,
        memory_usage = MemoryUsage CpuToGpu, 
        exclusive = true]])

    copy_buffer(staging_buffer, vertex_buffer, uint64(buffer_size))
    destroy_buffer(staging_buffer)

def create_index_buffer
    let buffer_size = length(indices) * typeinfo(sizeof type<uint16>)
    
    var staging_buffer = create_buffer([[CreateBufferOptions 
        size = uint64(buffer_size), 
        usage = BufferUsage TransferSrc, 
        memory_usage = MemoryUsage CpuToGpu, 
        exclusive = true]])
    var data = map_buffer(staging_buffer)
    unsafe 
        memcpy(data, addr(indices), buffer_size)
    unmap_buffer(staging_buffer)

    index_buffer = create_buffer([[CreateBufferOptions 
        size = uint64(buffer_size), 
        usage = BufferUsage IndexBuffer | BufferUsage TransferDst,
        memory_usage = MemoryUsage CpuToGpu,
        exclusive = true]])

    copy_buffer(staging_buffer, index_buffer, uint64(buffer_size))
    destroy_buffer(staging_buffer)