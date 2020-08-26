#include <vector>
#include <iostream> 

using namespace std;

vector<vector<int > > findSubsets(const vector<int> &nums) {
    vector<vector<int > > subsets = {{}}; 

    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0, subsize = subsets.size(); j < subsize; j++) {
            auto set = subsets[j];
            set.push_back(nums[i]);
            subsets.push_back(set);
        }
    }
    return subsets;
} 


int main(int argc, char* argv[]) {
  vector<vector<int>> result = findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}

void helper(vector<vector<int>> &ret, vector<int> cur, vector<int> &nums, int start) {
    ret.push_back(cur);
    for (int i = start; i < nums.size(); i++) { 
        if (i > start && nums[i] == nums[i - 1]) continue ; // sort first 
        cur.push_back(nums[i]);
        helper(ret, cur, nums, i + 1);
        cur.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    // sort(nums.begin(), nums.end())
    helper(ret, {}, nums, 0);
    return ret;
}