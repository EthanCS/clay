#pragma once

#include <string>
#include <clay_core/macro.h>

namespace clay
{
namespace core
{
typedef usize DAG_NodeHandle;

class DAG_Node;
class DAG_Edge;
class DAG;

class DAG_Node
{
    friend class DAG_Impl;

public:
    DAG_Node()                        = default;
    virtual ~DAG_Node() CLAY_NOEXCEPT = default;

    virtual void on_insert() CLAY_NOEXCEPT {}
    virtual void on_remove() CLAY_NOEXCEPT {}

    const DAG_NodeHandle get_handle() const CLAY_NOEXCEPT { return handle; }

private:
    DAG*           graph;
    DAG_NodeHandle handle;
};

class DAG_Edge
{
    friend class DAG_Impl;

public:
    DAG_Edge()                        = default;
    virtual ~DAG_Edge() CLAY_NOEXCEPT = default;

    virtual void on_connect() CLAY_NOEXCEPT {}
    virtual void on_disconnect() CLAY_NOEXCEPT {}

private:
    DAG*           graph;
    DAG_NodeHandle from;
    DAG_NodeHandle to;
};

class DAG
{
public:
    static DAG* create() CLAY_NOEXCEPT;
    static void destroy(DAG* dag) CLAY_NOEXCEPT;

    virtual ~DAG() CLAY_NOEXCEPT                                              = default;
    virtual DAG_NodeHandle insert(DAG_Node* node) CLAY_NOEXCEPT               = 0;
    virtual bool           remove(const std::string& name) CLAY_NOEXCEPT      = 0;
    virtual DAG_Node*      access_node(const std::string& name) CLAY_NOEXCEPT = 0;
};

} // namespace core
} // namespace clay