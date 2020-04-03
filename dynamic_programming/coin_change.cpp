/**
 * https://leetcode.com/problems/coin-change
 * 
    Given an infinite supply of ‘n’ coin denominations and a total money amount, we are asked to find the total number of distinct ways to make up that amount.

    Example:

    Denominations: {1,2,3}
    Total amount: 5
    Output: 5
    Explanation: There are five ways to make the change for '5', here are those ways:
      1. {1,1,1,1,1} 
      2. {1,1,1,2} 
      3. {1,2,2}
      4. {1,1,3}
      5. {2,3}
    Problem Statement #
    Given a number array to represent different coin denominations and a total amount ‘T’, we need to find all the different ways to make a change for ‘T’ with the given coin denominations. We can assume an infinite supply of coins, therefore, each coin can be chosen multiple times.
**/

#include <iostream>
#include <vector>

using namespace std;

int countChange(const vector<int> &denominations, int total) {
    if (!denominations.size() || !total) 
        return 0;

    int length = denominations.size();
    vector<vector<int> > dp(length, vector<int>(total + 1));

    for (int i = 0; i < length; i++)
        dp[i][0] = 1;
    for (int i = 0; i < length; i++) {
        for (int t = 1; t <= total; t++) {
            if (i > 0)
                dp[i][t] = dp[i - 1][t];
            if (t >= denominations[i]) 
                dp[i][t] += dp[i][t - denominations[i]];
        }
    }

    return dp[length - 1][total];
}

int main(int argc, char *argv[]) {
  vector<int> denominations = {25,10,5,1};
  cout << countChange(denominations, 100) << endl;
}