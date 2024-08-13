#pragma once

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

    const DependencyGraphNodeID get_handle() const CLAY_NOEXCEPT { return handle; }

private:
    DependencyGraph*      graph;
    DependencyGraphNodeID handle;
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
    DependencyGraph*      graph;
    DependencyGraphNodeID from;
    DependencyGraphNodeID to;
};

class DependencyGraph
{
public:
    static DependencyGraph* create() CLAY_NOEXCEPT;
    static void             destroy(DependencyGraph* graph) CLAY_NOEXCEPT;

    virtual ~DependencyGraph() CLAY_NOEXCEPT                                          = default;
    virtual DependencyGraphNodeID insert(DependencyGraphNode* node) CLAY_NOEXCEPT     = 0;
    virtual bool                  remove(DependencyGraphNodeID id) CLAY_NOEXCEPT      = 0;
    virtual DependencyGraphNode*  access_node(DependencyGraphNodeID id) CLAY_NOEXCEPT = 0;
};

} // namespace core
} // namespace clay