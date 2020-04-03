// Making Change 
 
// Given an array containing the available denominations of coins in descending order, write a function to compute the number of possible ways of representing a monetary amount in cents.
//  For simplicity, assume that there are an infinite number of coins available for each coin denomination in the array.

// Examples:

// make_change({25,10,5,1}, 4, 10) ==> 4

// namespace std have been included for this problem.

#include <vector>
#include <iostream>
using namespace std;
// Add any helper functions(if needed) above.
int make_change(int coins[], int n, int amount)
{
    if (amount < 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= amount; j++) {
            if (i > 0)
                dp[i][j] = dp[i - 1][j];
            if (j >= coins[i])
                dp[i][j] += dp[i][j - coins[i]];
        }
    }
    return dp[n - 1][amount];
}

int make_change2(int coins[], int n, int amount)
{
    if(amount == 0)
        return 1;
    if(amount < 0)
        return 0;
    if(n <= 0)
        return 0;
    return make_change2(coins, n - 1, amount) + make_change2(coins, n, amount - coins[n - 1]);
}

int main() {
    int arr[] = {25, 10, 5, 1};
    int siz = 4;
    int amount = -100;
    cout << make_change(arr, siz, amount);
}