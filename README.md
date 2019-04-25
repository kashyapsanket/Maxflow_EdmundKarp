# Maxflow_EdmundKarp
C++ implementation of the Edmund Karp algorithm to find the maximum flow across a graph given the source node, sink node and edge capacities.

The graph is maintained as an adjacency list in a vector.
On calling the Edmund Karp method, an internal call to the BFS method is invoked. BFS is invoked to find a path from the source to the sink.
