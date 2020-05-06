#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

#define NO_EDGE numeric_limits<int>::min()

void AjacencyMatrix(int num, vector<vector<int>> &edges) {
    int n = num;
    int m = num;
    int matrix[n][m];

    // initialization
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = NO_EDGE;
        }
    }

    for (auto &edge : edges)
        matrix[edge[0]][edge[1]] = edge[2];
        // undirected graph: matrix[edge[1]][edge[0]] = edge[2]
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != 0)
                cout << " ";
            if (matrix[i][j] != NO_EDGE) 
                cout << matrix[i][j];
            else 
                cout << "N";
        }
        cout << endl;
    }
}

void makeAjacencyList(int num, vector<vector<int>> edges) {
    unordered_map<int, vector<pair<int, int>>> adj; // vector<int, vector<int>> adj;
    for (auto &edge : edges) 
        adj[edge[0]].push_back({ edge[1], edge[2] });

    // printing, iterating
    for (int i = 0; i < num; i++) {
        cout << i << " : ";
    /**/for (int j = 0; j < adj[i].size(); j++) {
            if (j != 0)
                cout << " <- ";
            cout << adj[i][j].first << "(" << adj[i][j].second << ")";
        }
        cout << endl;
    }
}

struct E {
    int to, weight, next;
};

vector<E> Edge;
vector<int> Head;
int tot = 0;

inline void AddEdge(int from, int to, int wei) {
    if (tot >= Edge.size() - 1) {
        cout << "NOOOOOOOOOOOOOOOOOO!" << endl;
        return ;
    }
    Edge[tot].to = to;
    Edge[tot].weight = wei;
    Edge[tot].next = Head[from];
    Head[from] = tot++;
}

void makeAjacencyStar(int num, vector<vector<int>> edges) {
    // some intitialization 
    Edge.resize(edges.size() + 1, {});
    Head.resize(edges.size() + 1, -1);

    // forming the list
    for (auto & edge : edges) 
        AddEdge(edge[0], edge[1], edge[2]);
    
    // printing, iterating
    for (int i = 0; i < edges.size(); i++) {
        cout << i << " : ";
    /**/for (int itr = Head[i]; itr != -1; itr = Edge[itr].next) { // itr != -1  or   ~itr
            if (itr != Head[i])
                cout << " <- ";
            cout << Edge[itr].to << "(" << Edge[itr].weight << ")";
        }
        cout << endl;
    }
}

int main (void) {
    vector<vector<int>>  edges = { {0, 1, 0}, {1, 2, 1}, {2, 3, 3}, {4, 1, 4} };
    AjacencyMatrix(5, edges);
    cout << endl;
    vector<vector<int>>  edges2 = { {0, 1, 0}, {2, 3, 3}, {4, 1, 4}, {4, 2, 3}, {4, 3, 8}, {5, 1, 9}};
    makeAjacencyList(6, edges2);
    cout << endl;
    makeAjacencyStar(6, edges2);
    return 0;
}