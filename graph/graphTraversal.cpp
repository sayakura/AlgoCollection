#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> makeAjacencyList(int num, vector<vector<int>> edges) {
    unordered_map<int, vector<int>> adj; // vector<int, vector<int>> adj;
    for (auto &edge : edges) 
        adj[edge[0]].push_back(edge[1]);

        for (int i = 1; i <= num; i++) {
            cout << i << " : ";
            /**/for (int j = 0; j < adj[i].size(); j++) {
             if (j != 0)
                cout << " <- ";
            cout << adj[i][j]<< "(" << adj[i][j] << ")";
        }
        cout << endl;
    }

   return adj;
}


void dfs(int at, vector<bool> &visited, unordered_map<int, vector<int>> &graph) {
    if (visited[at]) return ;
    visited[at] = true;

    cout << at << " ";
    auto &nb = graph[at];
    for (int next : nb) 
        dfs(next, visited, graph);
}


void  bfs(int at, int vnum, unordered_map<int, vector<int>> &graph) { 
    queue<int> q;
    vector<bool> visited(vnum, false);

    q.push(at);
    visited[at] = true;
    while (!q.empty()) {
        int now = q.front(); q.pop();
        cout << now << " ";
        auto &nb = graph[now];
        for (int next : nb) {
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }            
        }
    }
    cout << endl;
}

int main() {
    vector<vector<int > > edges = { {1, 2}, {2, 3}, {2, 5}, {3, 4}, {5, 4}, {5, 7}, {4, 6}};
    int vnum = 7;
    vector<bool> visited(vnum, false);
    auto graph = makeAjacencyList(vnum, edges);

    dfs(1, visited, graph);
    cout << endl;
    bfs(1, vnum, graph);
    return 0;
}