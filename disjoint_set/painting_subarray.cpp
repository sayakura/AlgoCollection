#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> parent;
    int size;
public: 
    // query [l, r, c]
    vector<int> painting_subarray(int segL, vector<vector<int>> &queries) {
        vector<int> colors;

        // -1 as not painted 
        colors.assign(segL, -1);
        initalize_set(segL);
        for (int i = queries.size() - 1; i >= 0; i--) {
            int l = queries[i][0], r = queries[i][1], c = queries[i][2];
            for (int v = find(l); v <= r; v = find(v)) {
                colors[v] = c;
                parent[v] = v + 1;
            }
        }
        return colors;
    }
    void initalize_set(int n) {
        parent.assign(n, 0);
        size = n;
        for (int i = 0; i < n; i++) 
            parent[i] = i;
    }
    int find(int v) {
        while (parent[v] != v) {
            if (parent[v] >= size) return size;
            parent[v] = parent[parent[v]];
            v = parent[v];
        }
        return v;
    }
    
};

int main() {
    Solution s;
    /*
     [ ][ ][ ][ ][ ]
         1  1
      2  2
         3  3  3
               4  4

->   2  3  3  4  4
    */
    vector<vector<int>> queries = {
        {1, 2, 1},
        {0, 1, 2},
        {1, 3, 3},
        {3, 4, 4}
    };
    auto r = s.painting_subarray(5, queries);
    for (int c : r) 
        cout << c << " ";
    cout << endl;
    queries = {
        {0, 4, 1},
        {1, 1, 2},
        {3, 3, 3},
        {4, 4, 4}
    };
    r = s.painting_subarray(5, queries);
     for (int c : r) 
        cout << c << " ";
    cout << endl;
}
