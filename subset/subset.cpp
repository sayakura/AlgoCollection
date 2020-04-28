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
