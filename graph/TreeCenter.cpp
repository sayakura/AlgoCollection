#include <unordered_map>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

unordered_map<int, vector<int>> makeUndirectedAjacencyList(int num, vector<vector<int>> edges) {
    unordered_map<int, vector<int>> adj; 
    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    cout << "Graph: " << endl;
    for (int i = 1; i <= num; i++) {
        cout << i << " : ";
        /**/for (int j = 0; j < adj[i].size(); j++) {
                if (j != 0)
                cout << " <- ";
            cout << adj[i][j];
        }
        cout << endl;
    }
    cout << "-----"  << endl;
    return adj;
}

void findTreeCenter(int numV, unordered_map<int, vector<int>> adj) {
    vector<int> connCnt(numV + 1);
    queue<int> q; 
    int vnode;

    for (int i = 1; i <= numV; i++) {
        cout << i << " : " << adj[i].size() << endl; 
        connCnt[i] = adj[i].size();
        if (connCnt[i] == 1)
            q.push(i);
    }

    vnode = q.size();
    while (vnode < numV) {
        int siz = q.size(); 
        while (siz--) {
            int n = q.front(); q.pop();
            for (int nb : adj[n]) 
                if (--connCnt[nb] == 1) {
                    q.push(nb);
                    vnode++;
                }
        }
    }
    cout << q.size() << " center(s)" << endl;
    while (!q.empty()) {
        cout << "center : " << q.front() << endl;
        q.pop();
    }
}

int main() {
    /*
        1 -- 2
             |
            [3] -- 4
             |
        5 -- 6
             |
             7
    */
    cout << "----------------" << endl;
    vector<vector<int> > edges = { {1, 2}, {2, 3}, {3, 4}, {3, 6}, {5, 6}, {6, 7} };
    findTreeCenter(7, makeUndirectedAjacencyList(7, edges));
    cout << endl;
/*
    1 -- 2     6
         |    /
         3 - 4 - 5
        / \
       10  7 - 8
           |
           9
*/
    cout << "----------------" << endl;
    vector<vector<int> > edges2 = { {1, 2}, {2, 3}, {3, 4}, {3, 10}, {4, 5}, {4, 6}, {3, 7}, {7, 8}, {7, 9}};
    findTreeCenter(10, makeUndirectedAjacencyList(10, edges2));
    cout << endl;
/*
             1
           /   \ 
          2     3
         /|\   /|\
        4 5 6 7 8 9
*/
    cout << "----------------" << endl;
    vector<vector<int> > edges3 = { {1, 2}, {1, 3}, {2, 4}, {2, 5}, {2, 6}, {3, 7}, {3, 8}, {3, 9}};
    findTreeCenter(9, makeUndirectedAjacencyList(9, edges3));
    cout << endl;
/*
     1         4
      \       /
       2 - - 5
      /       \
    3          6
*/
    cout << "----------------" << endl;
    vector<vector<int> > edges4 = { {1, 2}, {2, 3}, {2, 5}, {5, 4}, {5, 6}};
    findTreeCenter(6, makeUndirectedAjacencyList(6, edges4));
    return 0;
}

