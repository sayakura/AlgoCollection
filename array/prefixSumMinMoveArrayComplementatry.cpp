// https://leetcode.com/problems/minimum-moves-to-make-array-complementary/ 
int minMoves(vector<int>& nums, int limit) {
    const int N = nums.size();
    vector<int> memo(2 * limit + 2, 0);
    for (int i = 0; i < N / 2; i++) {
        int a = nums[i], b = nums[N + ~i];
        memo[min(a, b) + 1]--; // 1 op
        memo[a + b]--; // 0 op
        memo[a + b + 1]++; // 1 op 
        memo[max(a, b) + limit + 1]++; // 2 op 
    }
    int ret = N, acc = N;
    for (int i = 2; i <= 2 * limit; i++) {
        acc += memo[i];
        ret = min(ret, acc);
    } 
    return ret;
}
