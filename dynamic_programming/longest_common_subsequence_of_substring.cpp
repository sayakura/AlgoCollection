
#include <iostream>
#include <vector>
using namespace std;

int find(string s, string t) {
    int n = s.size(), m = t.size();
    int ret = 0;
    int last = -1;
    vector<vector<int> > dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                if (i && j)
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1;
            } else {
                if (i)
                    dp[i][j] = dp[i - 1][j];
            }
            cout << dp[i][j] << " ";
            if (dp[i][j] > ret) 
                last = j;
            ret = max(ret, dp[i][j]);
        }
        cout << endl;
    }
    string a = "";
    for (int i = 0; i < ret; i++) 
        a += t[last--];
    reverse(begin(a), end(a));
    cout << a << endl;
    return ret;
}

int main () {
    string s = "365412";
    string t = "423516";

    cout << find(s, t) << endl;
}