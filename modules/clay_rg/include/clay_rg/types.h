#pragma once

#include <clay_core/dependency_graph.h>
#include <clay_gfx/resource.h>

#include <functional>
#include <string>

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

template <ResourceType::Enum type>
struct ResourceHandle {
    ResourceHandle(const core::DependencyGraphNodeID& _handle)
        : handle(_handle)
    {
    }
    inline operator core::DependencyGraphNodeID() const { return handle; }

private:
    core::DependencyGraphNodeID handle;
};

using PassHandle = ResourceHandle<ResourceType::Pass>;

struct RenderPassContext;
using OnRenderPassExecute = std::function<void(class RenderGraph&, RenderPassContext&)>;

struct RenderGraphNode : public core::DependencyGraphNode {
    RenderGraphNode(ResourceType::Enum type);
    const ResourceType::Enum node_type;
    std::string              name;
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