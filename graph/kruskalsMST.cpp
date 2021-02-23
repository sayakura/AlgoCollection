typedef pair<int, int> pii;

// kruskals is bad when the graph is dense, since it has to sort all the edges
/*
    Kruskal's algorithm initially places all the nodes of the original graph isolated from each other,
    to form a forest of single node trees, and then gradually merges these trees, combining at each 
    iteration any two of all the trees with some edge of the original graph. Before the execution of the algorithm, 
    all edges are sorted by weight (in non-decreasing order).
    Then begins the process of unification: pick all edges from the first to the last (in sorted order), 
    and if the ends of the currently picked edge belong to different subtrees, these subtrees are combined,
    and the edge is added to the answer. After iterating through all the edges, all the vertices will belong to the same sub-tree, and we will get the answer.
*/
class Solution {
public:
    int minCostConnectPoints(int n, vector<array<int, 3>> &edges) {
        disjoint_set ds(n);
        int mincost = 0;

        sort(edges.begin(), edges.end());
        for (auto &[w, u, v] : edges) {
            if (!ds.connected(u, v)) { // check if putting this new edge into our existing mst will create a cycle
                ds.join(u, v);
                mincost += w;  
                if (ds.size() == 1) break ; // break if a mst has found (all nodes are now in one component)
            }
        }
        return mincost;
    }
};