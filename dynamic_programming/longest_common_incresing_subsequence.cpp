#include <vector>
#include <iostream>

using namespace std;

int longestCommonIncresingSubsequence(vector<int> &a, vector<int> &b) {
    int l1 = a.size(), l2 = b.size();
    vector<int> dp(l2, 0);
    for (int i = 0; i < l1; ++i) {
        int current = 0;
        for (int j = 0; j < l2; ++j) {
            if (a[i] == b[j])
                dp[j] = max(current + 1, dp[j]);
            if (a[i] < b[j])
                current = max(current, dp[j]);
            cout << dp[j] << " ";
        }
        cout << endl;
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> a = { 5, 1, 0, 2, 3 };
    vector<int> b = { 2, 5, 9, 1, 0 };
    cout << longestCommonIncresingSubsequence(a, b) << endl;
}