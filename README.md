# **ConcurrentGraph**
A directed graph with support of lock-free concurrent traversal, concurrent topological sort, loop detection, etc

## Graph
Use classic graph defination: 
"A graph is made up of two finite sets: a set of nodes (or vertices) and a set of edges. 
Each node has a label to identify it and distinguish it from other nodes. 
Edges in a graph connect exactly two nodes and are denoted by the labels of the pair of nodes that are related. 
If you have a graph of three nodes A, B, and C, the two edges connecting A with B and B with C would be written as (A,B) and (B,C)." - <<The Art of Concurrency>>, Clay Breshears

## Member functions of graph
### modifiers:
void insert(const node_type& node);
void connect(const std::vector<node_type>& predecessors, const node_type& node, const std::vector<node_type>& successors);
void connect(const std::vector<node_type>& predecessors, const node_type& node);
void connect(const node_type& node, const std::vector<node_type>& successors);
void erase(const node_type& node);
void erase_preddecessors(const node_type& node);
void erase_successors(const node_type& node);
void erase_connection(const node_type& predecessor, const node_type& successor);
void clear() noexcept;
### iterators:
node_iterator begin() noexcept;
node_iterator end() noexcept;

## Member functions of propagator
### TODO

## Member functions of topological sort
### TODO

## Implementation
Using C++11 Standard Library, lock-free-concurrency unless mentioned

## Examples
Examples and use models could be found in test

