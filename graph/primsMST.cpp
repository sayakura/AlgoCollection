#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

// this is a prims algorithm implementation for problem https://leetcode.com/problems/min-cost-to-connect-all-points/
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size(), connected = 0;
    vector<int> visited(n, false);
    vector<int> d(n, INT_MAX); // for optimization
    // the most crucial step, yes, u need a min heap! (max heap by default)
    priority_queue<pii, vector<pii>, greater<pii>> q; 
    vector<vector<int>> mat(n, vector<int>(n, 0));
    // pre calculation for the problem, not needed if the graph already has some weight
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue ;
            if (mat[j][i] != 0) mat[i][j] = mat[j][i];
            else mat[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        }
    }
    int mincost = 0;
    q.push({0, 0});
    while (!q.empty()) {
        auto [w, u] = q.top(); q.pop();
        if (visited[u]) continue ;
        mincost += w;
        if (++connected == n)
            break ;
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            // skip if we had already found a path to v that has smaller cost
            if (!visited[v] && u != v && mat[u][v] < d[v]) {
                q.push({ mat[u][v], v});
                d[v] = mat[u][v];
            }
        }
    }
    return mincost;
}
