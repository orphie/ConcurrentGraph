// Copyright (c) 2022 by Yu Zhao (zhaoyu2014@gmail.com)
// This code is licensed under the MIT License.

#pragma once
#include <vector>
#include <iterator>
#include <map>
#include "concurrent_node.h"

namespace nonestd {
template <typename _Tp>
class concurrent_graph {
private: // typedefs
    using _Self = concurrent_graph;
    using _Node = concurrent_node<_Tp>;
    using _Nodes = std::vector<_Node>;
    using _NodeID = size_t;

public: // construct/destruct
    concurrent_graph(const concurrent_graph&)               = delete;
    concurrent_graph& operator=(const concurrent_graph&)    = delete;
    concurrent_graph()  {}
    ~concurrent_graph() {}

public: // modifiers
    void insert(const _Tp& node);
    void connect(const std::vector<_Tp>& predecessors, const _Tp& node, const std::vector<_Tp>& successors);
    void connect(const std::vector<_Tp>& predecessors, const _Tp& node);
    void connect(const _Tp& node, const std::vector<_Tp>& successors);
    void erase(const _Tp& node);
    void erase_predecessors(const _Tp& node);
    void erase_successors(const _Tp& node);

public:
    size_t size() const;

public:
    template <typename Functor>
    void run(const Functor& fun,
             bool mt = true) const;

private:
    _NodeID getNodeId(const _Tp&) const;
    //using node_iterator = std::random_access_iterator<_NodeID>;
    class node_iterator {};
    node_iterator beginNode();
    node_iterator endNode();
};
} // namespace nonestd
