# **ConcurrentGraph**
A directed graph with build-in support of lock-free concurrent traversal, concurrent topological sort, loop detection, etc

## The Graph
Use classic graph defination: 
"A graph is made up of two finite sets: a set of nodes (or vertices) and a set of edges. 
Each node has a label to identify it and distinguish it from other nodes. 
Edges in a graph connect exactly two nodes and are denoted by the labels of the pair of nodes that are related. 
If you have a graph of three nodes A, B, and C, the two edges connecting A with B and B with C would be written as (A,B) and (B,C)." - <<The Art of Concurrency>>, Clay Breshears

## The Concurrency Implementation
C++11 Standard Library, lock-free unless mentioned
