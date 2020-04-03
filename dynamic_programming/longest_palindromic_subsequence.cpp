/**
 * 
 * 
    Problem Statement #
    Given a sequence, find the length of its Longest Palindromic Subsequence (LPS). In a palindromic subsequence, elements read the same backward and forward.

    A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

    Example 1:

    Input: "abdbca"
    Output: 5
    Explanation: LPS is "abdba".
    Example 2:

    Input: = "cddpd"
    Output: 3
    Explanation: LPS is "ddd".
    Example 3:

    Input: = "pqr"
    Output: 1
    Explanation: LPS could be "p", "q" or "r".
**/
#include <iostream>
#include <vector>
using namespace std;

int findLPSLengthRecursive(const string &st, int start , int end)
{
    if (start > end)
        return 0;
    if (start == end)
        return 1;
    if (!st.length())
        return 0;
    if (st[start] == st[end])
        return 2 + findLPSLengthRecursive(st, start + 1, end - 1);
    int skip_left = findLPSLengthRecursive(st, start + 1, end);
    int skip_right = findLPSLengthRecursive(st, start, end - 1);
    return max(skip_left, skip_right);
}

int findLPSLengthTopDown(vector<vector<int > >&dp, const string &st, int start , int end)
{
    // should pass in from outside, and clear it after used. 
    if (start > end)
        return 0;
    if (start == end)
        return 1;
    if (dp[start][end] != -1) 
        return dp[start][end];
    if (st[start] == st[end])
        dp[start][end] = 2 + findLPSLengthTopDown(dp, st, start + 1, end - 1);
    else 
        dp[start][end] = max(findLPSLengthTopDown(dp, st, start + 1, end), findLPSLengthTopDown(dp, st, start, end - 1));
    return dp[start][end];
}

int findLPSDP(const string &st)
{
    vector<vector<int> >dp(st.length(), vector<int>(st.length(), 0));
    for (int i = 0; i < st.length(); i++)
        dp[i][i] = 1;
    for (int i = st.length() - 1; i >= 0; i--)  {
        for (int j = i + 1; j < st.length(); j++) {
            if (st[i] == st[j])
                dp[i][j] = 2 + dp[i + 1][j - 1];
            else 
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][st.length() - 1];
}

void findLPSLength(const string &st) {

    cout << findLPSLengthRecursive(st, 0, st.length() - 1) << endl;

    vector<vector<int> > dp(st.length(), vector<int>(st.length() + 1, -1)); 
    cout << findLPSLengthTopDown(dp, st, 0, st.length() - 1) << endl;
    cout << findLPSDP(st) << endl;
}

int main(int argc, char *argv[]) {
  findLPSLength("abdbca"); // -> 5
  findLPSLength("cddpd");  // -> 3
  findLPSLength("pqr");    // -> 1
}