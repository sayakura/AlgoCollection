/**
 * 
    * Introduction #
    We are given a ribbon of length ‘n’ and a set of possible ribbon lengths. Now we need to cut the ribbon into the maximum number of pieces that comply with the above-mentioned possible lengths. Write a method that will return the count of pieces.

    Example 1:

    n: 5
    Ribbon Lengths: {2,3,5}
    Output: 2
    Explanation: Ribbon pieces will be {2,3}.
    Example 2:

    n: 7
    Ribbon Lengths: {2,3}
    Output: 3
    Explanation: Ribbon pieces will be {2,2,3}.
**/

#include <iostream>
#include <vector>

using namespace std;

int countRibbonPieces(const vector<int> &ribbonLengths, int total) {
    if (!ribbonLengths.size())
        return 0;

    int length = ribbonLengths.size();
    int _min = numeric_limits<int>::min();
    vector<int > dp(total + 1, numeric_limits<int>::min());

    dp[0] = 0;
    for (int t = 1; t <= total; t++) {
        for (int i = 0; i < length; i++) {
            if (t >= ribbonLengths[i] && dp[t - ribbonLengths[i]] != _min)
                dp[t] = max(dp[t], dp[t - ribbonLengths[i]] + 1);   
        }
    }
    return dp[total] == _min ? -1 : dp[total];
}


int main(int argc, char *argv[]) {
  vector<int> ribbonLengths = {2, 3, 5};
  cout << countRibbonPieces(ribbonLengths, 5) << endl;
  ribbonLengths = vector<int>{2, 3};
  cout << countRibbonPieces(ribbonLengths, 7) << endl;
  ribbonLengths = vector<int>{5, 3, 7};
  cout << countRibbonPieces(ribbonLengths, 13) << endl;
  ribbonLengths = vector<int>{3, 5};
  cout << countRibbonPieces(ribbonLengths, 7) << endl;
}