    #include <vector>
#include <iostream>

using namespace std;

int longestIncresingSubsequence(vector<int> arr) {
    const int n = arr.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    return dp[n - 1];
}

int longestDecresingSubsequence(vector<int> arr) {
    const int n = arr.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; j++) {
            if (arr[i] < arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    return dp[n - 1];
}


int main() {
    vector<int> arr = { 1, 9, 19, 17, 32, 15, 99 };
    int ret = longestIncresingSubsequence(arr);
    cout << ret << endl;
    arr = { 10, -1, 4, 7, 0, 5, 2, -1, -9 };
    ret = longestDecresingSubsequence(arr);
    cout << ret << endl;
    return 0;
}