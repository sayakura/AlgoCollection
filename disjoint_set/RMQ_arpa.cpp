#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> parent;

int find(int v) {
    return parent[v] == -1 ? v : parent[v] = find(parent[v]);
}

// minimum range query 
vector<int> arpa(vector<int> &nums, vector<vector<int>> &queires) {
    const int N = nums.size(); 
    unordered_map<int, vector<vector<int> > > qu;
    vector<int> anw;
    stack<int> st;

    parent.assign(N, -1);
    for (auto &q : queires)  qu[q.back()].push_back(q);
    for (int i = 0; i < nums.size(); i++) {
        while (!st.empty() && nums[st.top()] > nums[i]) 
            parent[st.top()] = i, st.pop();
        st.push(i);
        for (auto q : qu[i]) 
            anw.push_back(nums[find(q.front())]);
    }
    return anw;
}

int main() {
    vector<int> nums = { 1, 3, 4, 2, 3, 1, 5};
    vector<vector<int>> queries = {
        { 0, 0 }, // 0 
        { 1, 1 },
        { 0, 1 }, // 2
        { 2, 3 },
        { 3, 5 }, // 3
        { 4, 6 }
    };
    auto ret = arpa(nums, queries);
    for (int i = 0; i < queries.size(); i++) {
        cout << "query: <" << queries[i].front() << ", " << queries[i].back() << ">" << " ans: " << ret[i] << " ( "; 
        for (int j = queries[i].front(); j <= queries[i].back(); j++) cout << nums[j] << " ";
        cout << " )" << endl;
    }
    return 0;
}

