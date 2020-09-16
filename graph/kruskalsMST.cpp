typedef pair<int, int> pii;
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