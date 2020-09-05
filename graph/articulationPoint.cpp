/*
 a vertex u is articulation point if one of the following two conditions is true.
1) u is root of DFS tree and it has at least two children.
2) u is not root of DFS tree and it has a child v such that no vertex in subtree rooted with v
*/
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

int n = 8; // number of nodes

vector<vector<int> > adj(n);
vector<bool> visited;
vector<int> dist, low;
/*
dist: store the discovery time of each node
low: low link value
*/
int timer;

void dfs(int u, int p = -1) {
    visited[u] = true;
    dist[u] = low[u] = timer++;
    int children = 0;
    for (int v : adj[u]) {
        if (visited[v]) {
            low[u] = min(low[u], dist[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (dist[u] < low[v] && p != -1) {
                cout << v << " is an articulation point " << endl;
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        cout << p << " is an articulation point " << endl;
    }
}

void articulationPoint() {
    timer = 0;
    visited.assign(n, false);
    dist.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }
}


int main() {
    int graph[8][8] = {
        {0, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 0}
    };
    for (int i = 0; i < 8; i++) {
        cout << i << ": ";
        for (int j = 0; j < 8; j++) {
            if (graph[i][j]) {
                cout << j << " ";
                adj[i].push_back(j);            
            }
        }
        cout << endl;
    };
    articulationPoint();
 } 






