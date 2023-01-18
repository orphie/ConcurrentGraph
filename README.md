# **ConcurrentGraph**
A directed graph with lock-free concurrent visit, topological sort/visit, loop handling, etc

## Graph
Classic graph defination: 
"A graph is made up of two finite sets: a set of nodes (or vertices) and a set of edges. 
Each node has a label to identify it and distinguish it from other nodes. 
Edges in a graph connect exactly two nodes and are denoted by the labels of the pair of nodes that are related. 
If you have a graph of three nodes A, B, and C, the two edges connecting A with B and B with C would be written as (A,B) and (B,C)." - <<The Art of Concurrency>>, Clay Breshears

## APIs
### modifiers:
~~~~~~~~~~cpp
void insert(const node_type& node);
void connect(const std::vector<node_type>& predecessors, const node_type& node, const std::vector<node_type>& successors);
void connect(const std::vector<node_type>& predecessors, const node_type& node);
void connect(const node_type& node, const std::vector<node_type>& successors);
void erase(const node_type& node);
void erase_preddecessors(const node_type& node);
void erase_successors(const node_type& node);
void erase_connection(const node_type& predecessor, const node_type& successor);
void clear() noexcept;
~~~~~~~~~~
### iterators:
~~~~~~~~~~cpp
node_iterator begin() noexcept;
node_iterator end() noexcept;
~~~~~~~~~~

## Examples
Examples and use models could be found in test

