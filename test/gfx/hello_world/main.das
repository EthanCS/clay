require fio
require clay_app
require clay_gfx

let MAX_FRAMES_IN_FLIGHT = 2

var window = [[Window]]

var hello_vs = [[HShader]]
var hello_fs = [[HShader]]

var swapchain_width = 1280u
var swapchain_height = 720u

var render_pass_layout = [[RenderPassLayout]]
var pipeline = [[HGraphicsPipeline]]

var command_pool = [[HCommandPool]]
var command_buffers : array<HCommandBuffer>

var in_flight_fences : array<HFence>
var image_available_semaphores : array<HSemaphore>
var render_finished_semaphores : array<HSemaphore>

var swapchain = [[HSwapchain]]
var swapchain_framebuffers : array<HFramebuffer>

var current_frame = 0u

struct Vertex
    position: float2
    color: float3

let vertices = [[auto   [[Vertex position = float2(-0.5f, -0.5f),   color = float3(1.0f, 0.0f, 0.0f)]];
                        [[Vertex position = float2(0.5f, -0.5f),    color = float3(0.0f, 1.0f, 0.0f)]];
                        [[Vertex position = float2(0.5f, 0.5f),     color = float3(0.0f, 0.0f, 1.0f)]];
                        [[Vertex position = float2(-0.5f, 0.5f),    color = float3(1.0f, 1.0f, 1.0f)]]
                ]]

let indices = [[auto uint16(0); uint16(1); uint16(2); uint16(2); uint16(3); uint16(0)]]

var index_buffer = [[HBuffer]]
var vertex_buffer = [[HBuffer]]

[export]
def main
    init(window, [[WindowConfig title = "Hello Triangle", width = 1280u, height = 720u]])
    var backend = [[InitBackendOptions backend_type = BackendType Vulkan, window = window.platform_handle, app_name = "Hello Triangle", debug = true]]
    let gfx_init = gfx_init(backend)
    on_init()
    while !window.requested_exit
        handle_events(window)
        on_update()
    on_destroy()

def on_init()

    // Load shaders
    fopen("test/gfx/hello_world/vert.glsl", "rb") <| $ ( f )
        if f != null
            fseek(f, int64(0), seek_end)
            let size = ftell(f)
            let data = fread(f)
            hello_vs = gfx_create_shader([[CreateShaderOptions code = data, code_size = uint(size), is_compiled = false]])
            fclose(f)
    fopen("test/gfx/hello_world/frag.glsl", "rb") <| $ ( f )
        if f != null
            fseek(f, int64(0), seek_end)
            let size = ftell(f)
            let data = fread(f)
            hello_fs = gfx_create_shader([[CreateShaderOptions code = data, code_size = uint(size), is_compiled = false]])
            fclose(f)

    // Render pass layout
    render_pass_layout.colors[0] = [[ColorAttachmentDesc 
        format = Format B8G8R8A8_UNORM, 
        layout = ImageLayout PresentSrc, 
        load_op = RenderPassLoadOp Clear]]
    
    // Create pipeline
    var pipeline_options = [[CreateGraphicsPipelineOptions name = "triangle"]]
    pipeline_options.vertex_shader = [[ShaderInfo compiled_shader = hello_vs, entry_func = "main"]]
    pipeline_options.pixel_shader = [[ShaderInfo compiled_shader = hello_fs, entry_func = "main"]]

    reset(pipeline_options.graphics_state)
    set_vertex_buffer_binding(pipeline_options.graphics_state, uint8(0), uint16(typeinfo(sizeof type<Vertex>)))
    set_vertex_buffer_attribute(pipeline_options.graphics_state, uint8(0), uint8(0), uint16(typeinfo(offsetof<position> type<Vertex>)), Format R32G32_SFLOAT)
    set_vertex_buffer_attribute(pipeline_options.graphics_state, uint8(0), uint8(1), uint16(typeinfo(offsetof<color> type<Vertex>)), Format R32G32B32_SFLOAT)
    pipeline_options.graphics_state.depth_test_enabled = false
    pipeline_options.graphics_state.render_pass_layout = render_pass_layout
    pipeline = gfx_create_graphics_pipeline(pipeline_options)

    // Command
    command_pool = gfx_create_command_pool(QueueType Graphics)
    resize(command_buffers, MAX_FRAMES_IN_FLIGHT)
    for i in range(0, MAX_FRAMES_IN_FLIGHT)
        command_buffers[i] = gfx_allocate_command_buffer(command_pool)
    
    // Sync objects
    resize(in_flight_fences, MAX_FRAMES_IN_FLIGHT)
    resize(image_available_semaphores, MAX_FRAMES_IN_FLIGHT)
    resize(render_finished_semaphores, MAX_FRAMES_IN_FLIGHT)
    for i in range(0, MAX_FRAMES_IN_FLIGHT)
        in_flight_fences[i] = gfx_create_fence(true)
        image_available_semaphores[i] = gfx_create_semaphore()
        render_finished_semaphores[i] = gfx_create_semaphore()
    
    // Swapchain
    create_swapchain(window.width, window.height)

    // Buffers
    create_index_buffer()
    create_vertex_buffer()

def on_update()
    draw_frame()

def on_destroy()
    gfx_device_wait_idle()
    gfx_shutdown()
    shutdown(window)

def draw_frame()
    unsafe 
        gfx_wait_for_fence(in_flight_fences[current_frame], true, uint64(-1))

        let acquire_swapchain = gfx_acquire_next_image(swapchain, [[AcquireNextImageOptions time_out = uint64(-1), semaphore = image_available_semaphores[current_frame]]])

        if acquire_swapchain.status == SwapchainStatus OutOfDate
            recreate_swapchain()
            return

        gfx_reset_fences(addr(in_flight_fences[current_frame]), 1)

        gfx_reset_command_buffer(command_buffers[current_frame], false)
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
        gfx_queue_submit(QueueType Graphics, submit_options)

        var present_options = [[QueuePresentOptions]]
        present_options.swapchain = swapchain
        present_options.image_index = uint(acquire_swapchain.image_index)
        present_options.wait_semaphores = addr(render_finished_semaphores[current_frame])
        present_options.num_wait_semaphores = 1u
        let present_status = gfx_queue_present(present_options)

        if present_status == SwapchainStatus OutOfDate || present_status == SwapchainStatus Suboptimal || window.resized
            window.resized = false
            recreate_swapchain()
        elif present_status != SwapchainStatus Success
            print("failed to present\n")
            
        current_frame = (current_frame + 1u) % uint(MAX_FRAMES_IN_FLIGHT)

def record_commands(cb: HCommandBuffer; image_index: uint)
    gfx_cmd_begin(cb, false)
    var render_pass = [[CmdBeginRenderPassOptions]]
    render_pass.framebuffer = swapchain_framebuffers[image_index]
    render_pass.render_pass_layout = render_pass_layout
    render_pass.extent = [[uint[2] swapchain_width; swapchain_height]]
    render_pass.clear = true
    render_pass.clear_values[0].color =  [[float[] 1.0; 1.0; 1.0; 1.0]]
    gfx_cmd_begin_render_pass(cb, render_pass)
    gfx_cmd_bind_graphics_pipeline(cb, pipeline)
    gfx_cmd_set_viewport(cb, [[CmdSetViewportOptions x = 0.0, y = 0.0, width = float(swapchain_width), height = float(swapchain_height), min_depth = 0.0, max_depth = 1.0]])
    gfx_cmd_set_scissor(cb, [[CmdSetScissorOptions offset = [[int[2] 0; 0]], extent = [[uint[2] swapchain_width; swapchain_height]]]])
    gfx_cmd_bind_vertex_buffer(cb, [[CmdBindVertexBufferOptions binding = 0u, buffer = vertex_buffer, offset = 0u]])
    gfx_cmd_bind_index_buffer(cb, [[CmdBindIndexBufferOptions buffer = index_buffer, offset = 0u, index_type = IndexType Uint16]])
    gfx_cmd_draw_indexed(cb, [[CmdDrawIndexedOptions index_count = uint(length(indices)), instance_count = 1u, first_index = 0u, vertex_offset = 0, first_instance = 0u]])
    gfx_cmd_end_render_pass(cb)
    gfx_cmd_end(cb)

def recreate_swapchain()
    gfx_device_wait_idle()
    for fb in swapchain_framebuffers
        gfx_destroy_framebuffer(fb)
    gfx_destroy_swapchain(swapchain)
    create_swapchain(window.width, window.height)

def create_swapchain(width: uint; height: uint)
    swapchain = gfx_create_swapchain([[CreateSwapchainOptions width = width, height = height, vsync = true, format = Format B8G8R8A8_UNORM]])
    let num_images = int(gfx_get_swapchain_image_count(swapchain))
    resize(swapchain_framebuffers, num_images)
    for i in range(0, num_images)
        var option = [[CreateFramebufferOptions]]
        option.width = width
        option.height = height
        option.color_attachments[0] = [[TextureViewDesc 
            texture = gfx_get_swapchain_back_buffer(swapchain, uint(i)), 
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
        swapchain_framebuffers[i] = gfx_create_framebuffer(option)
    swapchain_width = width
    swapchain_height = height

def copy_buffer(src_buffer: HBuffer; dst_buffer: HBuffer; size: uint64)
    var cb = gfx_allocate_command_buffer(command_pool)
    gfx_cmd_begin(cb, true)
    gfx_cmd_copy_buffer(cb, [[CmdCopyBufferOptions 
        src_buffer = src_buffer, src_offset = uint64(0), 
        dst_buffer = dst_buffer, dst_offset = uint64(0), 
        size = size]])
    gfx_cmd_end(cb)

    var submit_options = [[QueueSubmitOptions]]
    unsafe
        submit_options.command_buffers = addr(cb)
    submit_options.num_command_buffers = 1u
    gfx_queue_submit(QueueType Graphics, submit_options)
    gfx_queue_wait_idle(QueueType Graphics)
    gfx_free_command_buffer(cb)

def create_vertex_buffer
    let buffer_size = length(vertices) * typeinfo(sizeof type<Vertex>)
    
    var staging_buffer = gfx_create_buffer([[CreateBufferOptions 
        size = uint64(buffer_size), 
        usage = BufferUsage TransferSrc, 
        exclusive = true]])
    var data = gfx_map_buffer(staging_buffer)
    unsafe 
        memcpy(data, addr(vertices), buffer_size)
    gfx_unmap_buffer(staging_buffer)

    vertex_buffer = gfx_create_buffer([[CreateBufferOptions size = uint64(buffer_size), usage = BufferUsage VertexBuffer | BufferUsage TransferDst, exclusive = true]])

    copy_buffer(staging_buffer, vertex_buffer, uint64(buffer_size))
    gfx_destroy_buffer(staging_buffer)

def create_index_buffer
    let buffer_size = length(indices) * typeinfo(sizeof type<uint16>)
    
    var staging_buffer = gfx_create_buffer([[CreateBufferOptions 
        size = uint64(buffer_size), 
        usage = BufferUsage TransferSrc, 
        exclusive = true]])
    var data = gfx_map_buffer(staging_buffer)
    unsafe 
        memcpy(data, addr(indices), buffer_size)
    gfx_unmap_buffer(staging_buffer)

    index_buffer = gfx_create_buffer([[CreateBufferOptions size = uint64(buffer_size), usage = BufferUsage IndexBuffer | BufferUsage TransferDst, exclusive = true]])

    copy_buffer(staging_buffer, index_buffer, uint64(buffer_size))
    gfx_destroy_buffer(staging_buffer)