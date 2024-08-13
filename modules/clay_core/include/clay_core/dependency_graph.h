#pragma once

#include <optional>
#include <clay_core/macro.h>

namespace clay
{
namespace core
{
typedef usize DependencyGraphNodeID;

class DependencyGraphNode;
class DependencyGraphEdge;
class DependencyGraph;

class DependencyGraphNode
{
    friend class DependencyGraphImpl;

public:
    DependencyGraphNode()                        = default;
    virtual ~DependencyGraphNode() CLAY_NOEXCEPT = default;

    virtual void on_insert() CLAY_NOEXCEPT {}
    virtual void on_remove() CLAY_NOEXCEPT {}

    bool                                       is_vaild() const CLAY_NOEXCEPT { return id.has_value() && graph != nullptr; }
    const std::optional<DependencyGraphNodeID> get_node_id() const CLAY_NOEXCEPT { return id; }

private:
    DependencyGraph*                     graph;
    std::optional<DependencyGraphNodeID> id;
};

class DependencyGraphEdge
{
    friend class DependencyGraphImpl;

public:
    DependencyGraphEdge()                        = default;
    virtual ~DependencyGraphEdge() CLAY_NOEXCEPT = default;

    virtual void on_connect() CLAY_NOEXCEPT {}
    virtual void on_disconnect() CLAY_NOEXCEPT {}

private:
    DependencyGraph*                     graph;
    std::optional<DependencyGraphNodeID> from;
    std::optional<DependencyGraphNodeID> to;
};

class DependencyGraph
{
public:
    static DependencyGraph* create() CLAY_NOEXCEPT;
    static void             destroy(DependencyGraph* graph) CLAY_NOEXCEPT;

    virtual ~DependencyGraph() CLAY_NOEXCEPT                                           = default;
    virtual DependencyGraphNodeID insert_node(DependencyGraphNode* node) CLAY_NOEXCEPT = 0;
    virtual bool                  remove_node(DependencyGraphNodeID id) CLAY_NOEXCEPT  = 0;
    virtual DependencyGraphNode*  access_node(DependencyGraphNodeID id) CLAY_NOEXCEPT  = 0;

    virtual bool connect_node(DependencyGraphNodeID from, DependencyGraphNodeID to, DependencyGraphEdge* edge) CLAY_NOEXCEPT = 0;
    virtual bool disconnect_node(DependencyGraphNodeID from, DependencyGraphNodeID to) CLAY_NOEXCEPT                         = 0;
};

} // namespace core
} // namespace clay