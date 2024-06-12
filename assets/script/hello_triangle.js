
function recordCommands(cmd) {

    let cmdDrawOptions = new gfx.CmdDrawOptions();
    cmdDrawOptions.vertexCount = 3;
    cmdDrawOptions.instanceCount = 1;
    cmdDrawOptions.firstVertex = 0;
    cmdDrawOptions.firstInstance = 0;
    gfx.cmdDraw(cmd, cmdDrawOptions);
    gfx.cmdEndRenderPass(cmd);
    gfx.cmdEnd(cmd);
}