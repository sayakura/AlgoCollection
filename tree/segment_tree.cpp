#include <iostream>
#include <vector>

using namespace std;

/*
            0, 7
    0, 3            4, 7
 0, 1    2 3     4, 5    6, 7
00 11   22 33   44  55  66  77
*/

// practice: https://leetcode.com/contest/weekly-contest-214/problems/create-sorted-array-through-instructions/

// sum segment tree
class SegmentTree{
public:
    vector<int> segv;
    int n;
    SegmentTree(vector<int> &nums) {
        if (!nums.size()) return ;
        segv.assign(nums.size() * 4, 0);
        n = nums.size();
        build(nums, 1, 0, n - 1); 
    }
    /*
        build a segment tree with input array
        arr = the input array
        v = the index of the current vertex (if imagining the segment tree array as a tree)
        l = the lower boundary of the current "segment"
        r = the upper boundary
    */
    void build(vector<int> &nums, int v, int l, int r) {
        if (l == r) segv[v] = nums[l];
        else {
            int mid = l + (r - l) / 2;
            build(nums, v * 2, l, mid);
            build(nums, v * 2 + 1, mid + 1, r);
            // summation, since this is a segment tree
            segv[v] = segv[v * 2] + segv[v * 2 + 1]; 
        }
    }
    // return the sum of range(a, b)
    int sumRange(int v, int l, int r, int a, int b) {
        if (a > b) return 0;
        if (l == a && r == b) return segv[v];
        int mid = l + (r - l) / 2;
        return sumRange(v * 2, l, mid, a, min(mid, b))
            + sumRange(v * 2 + 1, mid + 1, r, max(mid + 1, a), b);
    }
    void update(int v, int l, int r, int pos, int val) {
        if (l == r) segv[v] = val;
        else {
            int mid = l + (r - l) / 2;
            if (pos <= mid) update(v * 2, l, mid, pos, val);
            else update(v * 2 + 1, mid + 1, r, pos, val);
            segv[v] = segv[v * 2] + segv[v * 2 + 1];
        }
    }
    int sumRange(int a, int b) {
        return sumRange(1, 0, n - 1, a, b);
    }
    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }
};