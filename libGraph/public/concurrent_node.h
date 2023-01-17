// Copyright (c) 2022 by Yu Zhao (zhaoyu2014@gmail.com)
// This code is licensed under the MIT License.

#pragma once

#include <stddef.h>

namespace nonestd {

template <typename _Tp>
class concurrent_node {
private:    // typedefs
    using NodeID = size_t;

public:     // construct/destruct
    concurrent_node() = delete;
    concurrent_node(const concurrent_node& node) : _data(node._data) {}
    concurrent_node& operator=(const concurrent_node& node) = delete;
    concurrent_node(const _Tp& data)  : _data(data) {} 

public: // Access
    class iterator {
    };
    iterator begin_predecessor() const;
    iterator end_predecessor()   const;

    iterator begin_successor() const;
    iterator end_successor()   const;

    // Connect/disconnect
    void connect_predecessor(NodeID);
    void disconnect_predecessor(NodeID);
    void connect_successor(NodeID);
    void disconnect_successor(NodeID);
private:
    const _Tp& _data;   
};  // class concurrent_node

} // namespace std
