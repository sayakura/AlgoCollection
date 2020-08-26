#include <vector>
using namespace std;

vector<vector<int>> permuate(vector<int> &num) {
    vector<vector<int>> result;
    helper(num, 0, result);
    return result;
}

void helper(vector<int> &num, int idx, vector<vector<int>> &result) {
    if (idx >= num.size()) {
        result.push_back(num);
        return ;
    }
    for (int i = idx; i < num.size(); i++) {
        swap(num[idx], num[i]);
        helper(num, idx + 1, result);
        swap(num[idx], num[i]);
    }
}