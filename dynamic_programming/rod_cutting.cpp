/**
Problem Statement #
Given a rod of length ‘n’, we are asked to cut the rod and sell the pieces in a way that will maximize the profit. We are also given the price of every piece of length ‘i’ where ‘1 <= i <= n’.

Example:

Lengths: [1, 2, 3, 4, 5]
Prices: [2, 6, 7, 10, 13]
Rod Length: 5

Let’s try different combinations of cutting the rod:

Five pieces of length 1 => 10 price
Two pieces of length 2 and one piece of length 1 => 14 price
One piece of length 3 and two pieces of length 1 => 11 price
One piece of length 3 and one piece of length 2 => 13 price
One piece of length 4 and one piece of length 1 => 12 price
One piece of length 5 => 13 price

This shows that we get the maximum price (14) by cutting the rod into two pieces of length ‘2’ and one piece of length ‘1’.
**/
#include <iostream>
#include <vector>

using namespace std;

int solveRodCutting(const vector<int> &lengths, vector<int> &prices, int n) {
    if (n < 0 || !lengths.size() || lengths.size() != prices.size())
        return 0;
    int len = prices.size();
    vector<vector<int> > dp(len, vector<int>(n + 1));

    for (int i = 0; i < len; i++) 
        dp[i][0] = 0;
    for (int i = 0; i <= n; i++) 
        dp[0][i] = (lengths[0] <= i) ? prices[0] : 0;
    for (int r = 1; r < len; r++) {
        for (int c = 1; c <= n; c++) {
            int p1 = 0, p2 = 0;
            if (lengths[r] <= c)
                p1 = prices[r] + dp[r][c - lengths[r]];
            p2 = dp[r - 1][c];
            dp[r][c] = max(p1, p2);
        }
    }
    return dp[len - 1][n];
}

int main(int argc, char *argv[]) {
  vector<int> lengths = {1, 2, 3, 4, 5};
  vector<int> prices = {2, 6, 7, 10, 13};
  int maxProfit = solveRodCutting(lengths, prices, 5);
  cout << maxProfit << endl;
}