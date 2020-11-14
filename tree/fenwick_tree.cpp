#include <iostream>
#include <vector>

using namespace std;

// pratice problem 
//  https://leetcode.com/problems/range-sum-query-mutable/
// https://leetcode.com/problems/create-sorted-array-through-instructions/
// 1 base implementation
class BIT {
public: 
    vector<int> bitvt;
    BIT(vector<int> &arr) {
        bitvt = vector<int>(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++) 
            add(i, arr[i]);
    }
    void add(int index, int val) {
        index = index + 1;
        while (index < bitvt.size()) {
            bitvt[index] += val;
            index += index & (-index);
        }
    }
    /* 
    void update(int index, val) {
        for (int i = index + 1; i < bitvt.size(); i += i & -i) {

        }
    } 
    */ 
    int getSum(int index) {
        int sum = 0;
        index += 1;
        while (index > 0) {
            sum += bitvt[index];
            index -= index & (-index);
        }
        return sum;
    }
    int getRange(int l, int r) {
        return getSum(r) - getSum(l - 1);
    }
};


int main() {
    vector<int> arr = { 1, 2, 3, 4, 5 ,6 ,7, 8 };
                   //   0  1  2  3  4
    BIT *bit = new BIT(arr);
    cout << bit->getSum(4) << endl;
    cout << bit->getRange(5, 7) << endl; 
    return 0;
}

