#pragma once

#include <clay_core/dependency_graph.h>

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

struct RenderGraphNode : public core::DependencyGraphNode {
    RenderGraphNode(ResourceType::Enum type);

    const ResourceType::Enum node_type;
};

struct RenderGraphEdge : public core::DependencyGraphEdge {
    RenderGraphEdge(ActionType::Enum type);

    const ActionType::Enum action_type;
};

} // namespace rg
} // namespace clay