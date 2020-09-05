#include <vector>
#include <unordered_set>
#include <stack>
#include <iostream>

using namespace std;

int id = 0;
int sccCount = 0;

 void dfs(int u, stack<int> &st, vector<int> &onStack, vector<int> &low, vector<int> &dist, vector<vector<int>> &adj) {
    st.push(u);
    onStack[u] = true;
    dist[u] = low[u] = id++;

    for (int v : adj[u]) {
        if (dist[v] == -1) { // when v is not visited
            dfs(v, st, onStack, low, dist, adj);
            low[u] = min(low[u], low[v]);
        } else if (onStack[v]) // u is a back edge to v 
            low[u] = min(low[u], dist[v]);
    }

    if (dist[u] == low[u]) {
        while (st.top() != u) {
            cout << st.top() << " ";
            onStack[st.top()] = false;
            st.pop();
        }
        cout << "head: " << st.top() << endl;
        onStack[st.top()] = false;
        st.pop();
        sccCount++;
    }
 }

vector<int> tarjans(vector<vector<int> > &adj) {
    int unvisited = -1;
    int n = 8;
    vector<int> dist(n, -1);
    vector<int> low(n, 0);
    vector<int> onStack(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++)
        if (dist[i] == -1)
            dfs(i, st, onStack, low, dist, adj);
    return low;
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
    vector<vector<int> > adj(8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (graph[i][j])
                adj[i].push_back(j);            
        }
    }
    tarjans(adj);
 } 


