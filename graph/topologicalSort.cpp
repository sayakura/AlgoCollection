#include <vector>
#include <iostream>
#include <unordered_map> 
#include <queue> 
using namespace std;


// only works on directed acyclic graph 
vector<int>    tp_sort(int vertices, vector<vector<int>> &edges) {
    vector<int> sortedOrder;

    if (vertices <= 0 || edges.size() == 0) 
        return sortedOrder;
    // source: node that has no incomming edge and has only outgoing edges 
    // sink: node that has only incoming and no outgoing edge

    // # of incoming edges
    unordered_map<int, int> degree;
    unordered_map<int, vector<int> > graph;

    // for BFS
    queue<int> sources;

    // initailization && build the graph
    for (auto &eachEdge: edges) {
        int parent = eachEdge[0];
        int child = eachEdge[1];
        if (!degree.count(parent)) {
            degree[parent] = 0;
            graph[parent] = {};
        }
        degree[child]++;
        graph[parent].push_back(child);
    }

    // find all the sources
    for (auto d: degree) {
        if (d.second == 0) 
            sources.push(d.first);
    }

    while (!sources.empty()) {
        int vertex = sources.front();
        sources.pop();
        sortedOrder.push_back(vertex);

        vector<int> children = graph[vertex];
        for (auto eachChild : children) {
            if (--degree[eachChild] == 0) 
                sources.push(eachChild);
        }
    }

    // if there's any cycle then .size() > vertices
    // but we should not trust what they pass in
    if (sortedOrder.size() != degree.size()) 
        return {};
    return sortedOrder;
}

int main(int argc, char* argv[]) {
    vector<vector<int> >val = {{3, 2}, {3, 0},{2, 0}, {2, 1}};
    vector<int> result =tp_sort(4, val);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    val = {{4, 2}, {4, 3}, {2, 0}, {2, 1}, {3, 1}};
    result = tp_sort(5, val);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;

    val = {{6, 4}, {6, 2}, {5, 3}, {5, 4}, {3, 0}, {3, 1},{3, 2}, {4, 1}};
    result = tp_sort(7, val);
    for (auto num : result) {
        cout << num << " ";
    }
    cout << endl;
}