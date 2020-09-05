#include <vector>
#include <iostream>

using namespace std;

int longestCommonSubsequence(string a, string b) {
    int n = a.size(), m = b.size();
    int ret = 0;
    vector<vector<int> >dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1;j <= m; ++j) {
            if (a[i] == b[j]) 
                dp[i][j] = 1 + dp[i - 1][j - 1]; //select both a[i] and b[j]
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);  // skip a[i] or b[j]
        }
    }
    return dp[n][m];
}

int main() {
    string a = "a1b1c1d";
    string b = "abcde";
    cout << longestCommonSubsequence(a, b) << endl;
    return 0;
}