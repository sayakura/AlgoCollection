## Graph
Traversal
  - DFS
  - BFS
Minimum Spanning Tree
  - Kruskal's algorith
    1. Starts building MST by adding the minimum cost edge in the graph to the MST
    2. Best known time complexity is O(E log V)
    3. Typically preferred for sparse graphs with a small number of edges
  - Prim's algorithm
    1. Starts building MST from any starting vertex in the graph
    2. Best known time complexity is O(E + VlogV)
    3. Typically preferred for dense graphs with a large number of edges
