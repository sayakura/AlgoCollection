#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void dfs(int curnode, vector<vector<int>> &adj, vector<bool> &visited) {
  visited[curnode] = true;
  cout << curnode << endl;
  for (int next : adj[curnode])
    if (!visited[next])
      dfs(next, adj, visited);
}

void dfsItr(int start, vector<vector<int>> &adj) {
  vector<bool> visited(adj.size(), false);
  stack<int> st;
  st.push(start);
  while (!st.empty()) {
    int u = st.top(); st.pop();
    cout << u << " ";
    visited[u] = true;
    for (int v : adj[u]) {
      if (!visited[v])
        st.push(v);
    }
  }
  cout << endl;
}

void bfs(int startnode, int numV, vector<vector<int>> &adj) {
  queue<int> q;
  vector<bool> visited(numV, false);
  q.push(startnode);
  visited[startnode] = true;
  while (!q.empty()) {
    int siz = q.size();
    while (siz--) {
      int cur = q.front(); q.pop();
      visited[cur] = true;
      for (int next : adj[cur])
        if (!visited[next])
          q.push(next);
      cout << cur << " ";
    }
    cout << endl;
  }
}

int main() {
  int numV = 7;
  vector<vector<int>> adj(numV + 1);
  vector<bool> visited(numV + 1, false);
  vector<vector<int>> edges;
  edges = {
    {1, 2},
    {1, 3},
    {1, 4},
    {3, 5},
    {4, 6},
    {2, 7}
  };
  for (auto e : edges) {
    adj[e.front()].push_back(e.back());
  }
  dfs(1, adj, visited);
  cout << "====" << endl;
  bfs(1, numV, adj);
  cout << "====" << endl;
  dfsItr(1, adj);
}
