#include <vector>
#include <iostream>

using namespace std;

/*
        a b e 
    c   0 0 0
    b   0 0 0
    a   1 1 0
    b   0 2 0
    e       3
*/


int longestCommonSubstring(string a, string b) {
    int n = a.size(), m = b.size();
    int ret = 0;
    vector<vector<int> >dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ret = max(ret, dp[i][j]);
            }
        }
    }
    return ret;
}

int main() {
    string a = "OldSite:GeeksforGeeks.org";
    string b = "NewSite:GeeksQuiz.com";
    cout << longestCommonSubstring(a, b) << endl;
    return 0;
}