#pragma once

#include <clay_core/dependency_graph.h>
#include <clay_gfx/resource.h>
#include <functional>
#include <string>

namespace clay
{
namespace rg
{

struct ObjectType {
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
        Read,
        Write,
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

template <ObjectType::Enum type>
struct ObjectHandle {
    ObjectHandle(const core::DependencyGraphNodeID& _handle)
        : handle(_handle)
    {
    }
    inline operator core::DependencyGraphNodeID() const { return handle; }

private:
    core::DependencyGraphNodeID handle;
};

template <>
struct ObjectHandle<ObjectType::Texture> {
    struct SRV {
    };

    struct UAV {
    };

    struct RTV {
    };

    struct DSV {
    };
};

using PassHandle    = ObjectHandle<ObjectType::Pass>;
using TextureHandle = ObjectHandle<ObjectType::Texture>;

struct RenderPassContext;
using OnRenderPassExecute = std::function<void(class RenderGraph&, RenderPassContext&)>;

struct RenderGraphNode : public core::DependencyGraphNode {
    RenderGraphNode(ObjectType::Enum type);
    const ObjectType::Enum node_type;
    std::string            name;
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