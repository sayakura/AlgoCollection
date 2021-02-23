#include <vector>
#include <iostream>
#include <queue> 

using namespace std;

#define RED 1
#define BLUE -1
bool isBipartite(vector<vector<int> > adj, int n) {
    vector<int> color(n, 0);

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!color[i]) {
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (color[v] && color[v] != -color[u]) 
                        return false;
                    else if (!color[v]) {
                        color[v] = -color[u]; 
                        q.push(v);
                    }
                }
            }
        }
    }
    return true;
}



int main() {
    int n = 4;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2};
    cout << "Is Bipartite: " << (isBipartite(adj, n) ? "YES" : "NO") << endl;

    n = 3;
    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {1, 0};
    cout << "Is Bipartite: " << (isBipartite(adj, n) ? "YES" : "NO") << endl;
    return 0;
}