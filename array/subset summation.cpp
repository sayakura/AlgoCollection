// namespace std have been included for this problem.
#include <deque>
#include <iostream>
using namespace std;
// Add any helper functions(if needed) above.
// namespace std have been included for this problem.
#include <deque>
#include <algorithm>
void dfs(deque<int> d, int sum, int col, int arr[], int size, int must_have, int target,  bool &ret) {
    if (ret)
        return ;
    if (col >= size || sum == target) {
        if (sum == target) {
            auto out = find(d.begin(), d.end(), must_have);
            if (out != d.end())
                ret = true;
        }
        return ;
    }
    for (; col < size; col++) {
        d.push_back(arr[col]);
        dfs(d, sum + arr[col], col + 1, arr, size, must_have, target, ret);
        d.pop_front();
    }
    
}
// Add any helper functions(if needed) above.
bool group_sum_with_num(int arr[], int n, int must_have, int sum)
{
    bool ret = false;
    dfs(deque<int>(), 0, 0, arr, n, must_have, sum, ret);
    return ret;
}
int main() {
    int arr[] = {4, 6, 7, 9, 10, -11};
    int siz = 6;
    cout << group_sum_with_num(arr, siz, 0, 12);
}
