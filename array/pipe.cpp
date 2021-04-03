#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

void    printPipe(vector<vector<bool> > &pipe) {
    for (int j = 0; j < pipe[0].size(); j++)
        cout << "-";
    cout << endl;   
    for (int i = 0; i < pipe.size(); i++) {
        for (int j = 0; j < pipe[i].size(); j++)
            if (pipe[i][j])
                cout << "█";
            else
                cout << "□";
        cout << endl;   
    }
    for (int j = 0; j < pipe[0].size(); j++)
            cout << "-";
    cout << endl;   
}

vector<bool> query(int N, vector<vector<int> > input) {
    vector<vector<bool> > pipe(2, vector<bool>(N, false));     
    unordered_map<int, int> hm;
    vector<bool> ret; 
    for (auto q : input) {
        int j = q.front(), i = q.back();
        cout << "input: " << j << "," << i << endl;
        pipe[i][j] = !pipe[i][j];
        if (i == 0) {  
            if (!pipe[i][j])
                hm.erase(j);
            else {
                int count = (j > 0 ? pipe[1][j - 1] : 0) +
                        pipe[1][j] + 
                        (j < N - 1 ? pipe[1][j + 1] : 0);
                if (count > 0)
                    hm[j] = count;
            }
        } else { 
            if (!pipe[i][j]) {
                if (j > 0 && pipe[0][j - 1]) {
                    if (--hm[j - 1] == 0)
                        hm.erase(j - 1); 
                }
                if (j < N - 1 && pipe[0][j + 1]) {
                    if (--hm[j + 1] == 0)
                        hm.erase(j + 1);
                }
                if (pipe[0][j])
                    if (--hm[j] == 0)
                        hm.erase(j);
            } else {
                if (j > 0 && pipe[0][j - 1])      hm[j - 1]++;
                if (j < N - 1 && pipe[0][j + 1])  hm[j + 1]++;
                if (pipe[0][j])
                    hm[j]++;
            }
        }
        ret.push_back((hm.size() == 0));
        // displaying
        if (hm.size() != 0)
            cout << "【BLOCKED】" << endl;
        else 
            cout << "【FREE】" << endl;
        printPipe(pipe);
        // 
    }
    return ret;
}
int main() {
    vector<vector<int>> input = { {1, 0}, {1, 1}, {1, 1}, {3, 1}, {2, 1}, {3, 1}, {2, 1}, {5, 0}, {5, 1}, {1, 1}, {1, 1}, {5, 1}, {0, 0}, {0, 1}};
    auto ret = query(10, input);
    cout << "[ ";
    for (bool r : ret) 
        if (r) 
            cout << "True ";
        else 
            cout << "False ";
    cout << " ]";
    cout << endl;
}