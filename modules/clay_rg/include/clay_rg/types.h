#pragma once

#include "clay_gfx/handle.h"
#include <clay_core/dependency_graph.h>
#include <clay_gfx/resource.h>

#include <functional>

namespace clay
{
namespace rg
{
struct ResourceType {
    enum Enum
    {
        Pass,
        Texture,
        Buffer,
    };
};

struct ActionType {
    enum Enum
    {
        ReadOnly,
        ReadWrite,
    };
};

struct PassType {
    enum Enum
    {
        Render,
        Compute,
        Copy,
        Present,
    };
};

struct RenderPassContext;
using OnRenderPassExecute = std::function<void(class RenderGraph&, RenderPassContext&)>;

struct RenderGraphNode : public core::DependencyGraphNode {
    RenderGraphNode(ResourceType::Enum type);
    const ResourceType::Enum node_type;
};

struct RenderGraphEdge : public core::DependencyGraphEdge {
    RenderGraphEdge(ActionType::Enum type);
    const ActionType::Enum action_type;
};

struct PassContext {
    class PassNode*                 node = nullptr;
    gfx::Handle<gfx::CommandBuffer> cmd;
};

struct RenderPassContext : public PassContext {
    gfx::RenderPassEncoder encoder;
};

} // namespace rg
} // namespace clay