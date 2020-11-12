vector<vector<int>> twoSum(vector<int> &nums, int start, int target) {
    int l = start, r = nums.size() - 1;
    vector<vector<int>> ret;
    while (l < r) {
        int lv = nums[l], rv = nums[r];
        int sum = lv + rv; 
        if (sum < target) 
            while (l < r && nums[l] == lv) l++;
        else if (sum > target)
            while (l < r && nums[r] == rv) r--;
        else {
            ret.push_back({ lv, rv });
            while (l < r && nums[l] == lv) l++;
            while (l < r && nums[r] == rv) r--;
        }
    }
    return ret;
}
vector<vector<int>> nSum(vector<int> &nums, int n, int start, int target) {
    int siz = nums.size(); 
    vector<vector<int>> ret;
    if (start == nums.size() || siz < n || nums[start] * n > target || target > nums.back() * n) return ret;
    if (n == 2) 
        return twoSum(nums, start, target);
    for (int i = start; i < siz; i++) {
        for (auto &v : nSum(nums, n - 1, i + 1, target - nums[i])) {
            v.push_back(nums[i]);
            ret.push_back(v);
        };
        while(i < siz - 1 && nums[i] == nums[i + 1]) i++;
    }
    return ret;
}
// example 
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(begin(nums), end(nums));
    return nSum(nums, 4, 0, target);
}