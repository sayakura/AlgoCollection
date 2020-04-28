#include <vector>
#include <iostream> 
#include <queue> 

using namespace std;

vector<vector<int> > findPermutations(const vector<int> &nums) {
    vector<vector<int> > result;
    queue<vector<int> > permutations;

    permutations.push({});
    for (int n : nums) {
        for (int i = 0; i < n; i++) {
            auto oldPermutation = permutations.front();
            permutations.pop();
            for (int j = 0; j <= oldPermutation.size(); j++) {
                vector<int> newPermutation(oldPermutation);
                newPermutation.insert(newPermutation.begin() + j, n);
                if (newPermutation.size() == nums.size()) {
                    result.push_back(newPermutation);
                } else {
                    permutations.push(newPermutation);
                }
            }
        }
    } 
    return result;
} 


