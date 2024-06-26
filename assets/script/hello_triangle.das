require clay_gfx

var render_pass_layout = [[RenderPassLayout]]
var pipeline = [[HGraphicsPipeline]]
var swapchain_width = 0u
var swapchain_height = 0u

[export]
def record_commands(cb: HCommandBuffer; fb: HFramebuffer)
    let handle = gfx_create_buffer([[CreateBufferOptions size = uint64(16), usage = BufferUsage VertexBuffer, exclusive = true]])
    let mem = gfx_map_buffer(handle, 0u, 16u)
    gfx_unmap_buffer(handle)
    gfx_destroy_buffer(handle)
    
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
    gfx_cmd_draw(cb, [[CmdDrawOptions vertex_count = 3u, instance_count = 1u, first_vertex = 0u, first_instance = 0u]])
    gfx_cmd_end_render_pass(cb)
    gfx_cmd_end(cb)