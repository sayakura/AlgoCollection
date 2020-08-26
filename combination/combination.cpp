class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        helper(0, ret, cur, candidates, target);
        return ret;
    } 
    void helper(int idx, vector<vector<int>> &ret, vector<int> &cur, vector<int> &nums, int remain) {
        if (remain < 0) return ;
        else if (remain == 0) ret.push_back(cur);
        else {
            for (int i = idx; i < nums.size(); i++) {
                cur.push_back(nums[i]);
                helper(i, ret, cur, nums, remain - nums[i]);
                cur.pop_back();
            }            
        }
    }
};