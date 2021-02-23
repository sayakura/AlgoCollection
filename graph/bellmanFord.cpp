#include <iostream>
#include <vector>

using namespace std;

void bellmanFord(int N, vector<vector<pair<int, int>> > &adj, int src) {
    cout << "starting algorithem " << endl;
    vector<int> dist(N, INT_MAX);
    vector<int> prev(N, -1);
    dist[src] = 0;

    // run |V| - 1 times to relax all edges
    for (int i = 0; i < N - 1; ++i) { 
        for (int u = 0; u < N; ++u) {
            for (auto [v, w] : adj[u]) {
                int newd = dist[u] + w;
                // makesure there's already a path to u
                if (dist[u] != INT_MAX && newd < dist[v]) {
                    dist[v] = newd;
                    prev[v] = u; // update path
                }
            }
        }
    }

    // // optimization
    // for (;;) {
        bool any = false;
        for (int u = 0; u < N; u++) {
            for (auto &[v, w] : adj[u]) {
                int newd = dist[u] + w;
                if (dist[u] < INT_MAX && newd < dist[v]) {
                    dist[v] = newd;
                    prev[v] = u;
                    any = true;
                }
            }
        }
        if (!any) break ;
    }

    // run it one last time check for negative cycle
    for (int u = 0; u < N; ++u) {
        cout << "From " << u << " to src: " << dist[u] << endl;
         for (auto [v, w] : adj[u]) {
            int newd = dist[u] + w;
            if (dist[u] != INT_MAX && newd < dist[v]) {
                cout << "Error: Negative cycle found" << endl;
                break ;
            }
        }
    }
}

int main() {
    int V = 4;
    vector<vector<pair<int, int>> > adj(V);
    adj[0] = { {1, 5}, {2, 4} };
    adj[1] = { {3, 3} };
    adj[2] = { {1, 6} };
    adj[3] = { {2, 2} };
    bellmanFord(V, adj, 0);
    return 0;
}

// SPFA

/*
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

bool spfa(int s, vector<int>& d) {
    int n = adj.size();
    d.assign(n, INF);
    vector<int> cnt(n, 0);
    vector<bool> inqueue(n, false);
    queue<int> q;

    d[s] = 0;
    q.push(s);
    inqueue[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inqueue[v] = false;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                if (!inqueue[to]) {
                    q.push(to);
                    inqueue[to] = true;
                    cnt[to]++;
                    if (cnt[to] > n)
                        return false;  // negative cycle
                }
            }
        }
    }
    return true;
}
*/  