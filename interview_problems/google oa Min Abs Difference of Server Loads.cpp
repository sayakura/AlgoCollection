#include <vector>
#include <numeric>
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// int minDifference(vector<int> &A) {  
//     const int N = A.size(); 
//     bool dp[N];
//     bzero(dp, N);
//     dp[0] = true;




// }

int minDifference(vector<int> &A) {  
    int sum = accumulate(begin(A), end(A), 0);
    int half = sum / 2 + 1;
    bool dp[A.size() + 1][half + 1];
    for (int i = 0; i < A.size(); i++) 
        dp[i][0] = true;
    for (int i = 1; i <= half; i++) 
        dp[0][i] = false;

    for (int i = 1; i <= A.size(); i++) {
        for (int j = 1; j <= half; j++) {
            dp[i][j] = dp[i - 1][j];
            if (A[i - 1] <= j) 
                dp[i][j] |= dp[i - 1][j - A[i - 1]];
        }
    }
    for (int j = half; j >= 0; j--) 
        if (dp[A.size()][j]) return sum - 2 * j;
    return -1;
}

int main() {
    vector<int> loads = {1,2,8,19};
    cout << minDifference(loads) << endl;
    return 0;
}
