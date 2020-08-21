#include <unordered_map>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

void printCircuit(unordered_map<int, vector<int>> &G) {
    unordered_map<int, int> edge_count;
    for (auto &itr : G) 
        edge_count[itr.first] = itr.second.size();

    if (!G.size())
        return ;

    stack<int> cur_path;
    vector<int> circuit;

    // start from any vertex
    cur_path.push(0);
    int curr_v = 0;
    while (!cur_path.empty()) {
        if (edge_count[curr_v]) {
            cur_path.push(curr_v);
            int next_v = G[curr_v].back();

            edge_count[curr_v]--;
            G[curr_v].pop_back();
            curr_v = next_v;
        } else {
            circuit.push_back(curr_v);
            curr_v = cur_path.top();
            cur_path.pop();
        }
    }
    reverse(circuit.begin(), circuit.end());
    for (int c : circuit)
        cout << c << " ";
    cout << endl;
    
}

int main() {
    unordered_map<int, vector<int>> G;
    G[0] = { 1, 2 };
    G[2] = { 0, 1 };
    G[1] = { 2 };
    printCircuit(G);
    return 0;
}