#include <vector>
#include <iostream>

using namespace std;

class disjoint_set {
    vector<pair<int, int>> arr;
    int siz;
        
    public: 
    disjoint_set(int N) {
        arr = vector<pair<int, int>>(N);
        for (int i = 0; i < N; i++) {
            arr[i].first = i;
            arr[i].second = 0;
        }
        siz = N;
    }
    int find(int x) {
        if (arr[x].first != x)
            arr[x].first = find(arr[x].first);
        return arr[x].first;
    }
    void join(int x, int y) {
        int xv = find(x);
        int yv = find(y);
        if (xv == yv)
            return ;
        siz--;
        if (arr[xv].second < arr[yv].second)
            arr[xv].first = yv;
        else if (arr[xv].second > arr[yv].second) 
            arr[yv].first = xv;
        else {
            arr[xv].first = yv;
            arr[xv].second++;
        }
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int size() {
        return siz;
    }
};