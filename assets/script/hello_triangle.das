require clay_gfx

var render_pass_layout = [[RenderPassLayout]]
var pipeline = [[HGraphicsPipeline]]
var swapchain_width = 0u
var swapchain_height = 0u

var buffer_created = false
var vertex_buffer = [[HBuffer]]

[export]
def record_commands(cb: HCommandBuffer; fb: HFramebuffer)
    if buffer_created == false
        print("creating buffer\n")
        vertex_buffer = gfx_create_buffer([[CreateBufferOptions size = uint64(16), usage = BufferUsage VertexBuffer, exclusive = true]])
        let mem = gfx_map_buffer(vertex_buffer, 0u, 16u)
        gfx_unmap_buffer(vertex_buffer)
        buffer_created = true
    
    gfx_cmd_begin(cb)
    var render_pass = [[CmdBeginRenderPassOptions]]
    render_pass.framebuffer = fb
    render_pass.render_pass_layout = render_pass_layout
    render_pass.extent = [[uint[2] swapchain_width; swapchain_height]]
    render_pass.clear = true
    render_pass.clear_values[0].color =  [[float[] 1.0; 1.0; 1.0; 1.0]]
    gfx_cmd_begin_render_pass(cb, render_pass)
    gfx_cmd_bind_graphics_pipeline(cb, pipeline)
    gfx_cmd_set_viewport(cb, [[CmdSetViewportOptions x = 0.0, y = 0.0, width = float(swapchain_width), height = float(swapchain_height), min_depth = 0.0, max_depth = 1.0]])
    gfx_cmd_set_scissor(cb, [[CmdSetScissorOptions offset = [[int[2] 0; 0]], extent = [[uint[2] swapchain_width; swapchain_height]]]])
    gfx_cmd_bind_vertex_buffer(cb, [[CmdBindVertexBufferOptions binding = 0u, buffer = vertex_buffer, offset = 0u]])
    gfx_cmd_draw(cb, [[CmdDrawOptions vertex_count = 3u, instance_count = 1u, first_vertex = 0u, first_instance = 0u]])
    gfx_cmd_end_render_pass(cb)
    gfx_cmd_end(cb)

[export]
def on_init()
    print("hello triangle init\n")

[export]
def on_update()
    print("hello triangle update\n")

[export]
def on_destroy()
    gfx_device_wait_idle()
    gfx_shutdown()