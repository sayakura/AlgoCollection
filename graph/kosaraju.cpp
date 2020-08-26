#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> getTranspose(int V, vector<vector<int>> &adj) {
  vector<vector<int>> transpose(V);
  for (int i = 0; i < V; i++) {
    for (int next : adj[i])
      transpose[next].push_back(i);
  }
  return transpose;
}

void collectConnectComponents(int node, vector<bool> &visited, vector<vector<int>> &adj, vector<int> &component) {
  visited[node] = true;
  component.push_back(node);
  for (int next : adj[node]) {
    if (!visited[next])
      collectConnectComponents(next, visited, adj, component);
  }
}

// simple dfs
void fillStack(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st) {
  visited[node] = true;
  for (auto next : adj[node]) {
    if (!visited[next])
      fillStack(next, visited, adj, st);
  }
  st.push(node);
}

///// kosaraju eternal god ! /////
vector<vector<int>> Kosaraju(int V, vector<vector<int>> adj) {
  vector<bool> visited(V, false);
  stack<int> st;
  for (int i = 0; i < V; i++) {
    if (!visited[i])
      fillStack(i, visited, adj, st);
  }
  auto transpose = getTranspose(V, adj);
  fill(visited.begin(), visited.end(), false);
  vector<vector<int>> connectedComponents;
  // here we are traversing it backward, so that if we went from component a to b, now we are going from b to a, since a -> b is reversed in the reversed graph "transpose", you cant go from b to a
  // and that leaves u a prefect component!
  while (!st.empty()) {
    int node = st.top();
    st.pop();
    if (!visited[node]) {
      vector<int> component;
      collectConnectComponents(node, visited, transpose, component);
      connectedComponents.push_back(component);
    }
  }
  return connectedComponents;
}

int main() {
  int V = 9;

  vector<vector<int>> adj =
  {
      { 1, 3 },
      { 2, 4 },
      { 3, 5 },
      { 7 },
      { 2 },
      { 4, 6 },
      { 7, 2 },
      { 8 },
      { 3 }
  };
  auto connectedComponents = Kosaraju(V, adj);
  for (auto component : connectedComponents) {
    for (int n : component)
      cout << n << " ";
    cout << endl;
  }
}
