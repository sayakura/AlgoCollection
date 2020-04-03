#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// this is identical to merging two sorted array, one optimization is to only copy i to mid 
// into a new vector
void merge(vector<int> &arr, int i, int mid, int j) {
    vector<int> left(mid - i + 1); // [i, mid]
    vector<int> right(j - mid);    // [mid + 1, j]

    copy(arr.begin() + i, arr.begin() + mid + 1, left.begin());
    copy(arr.begin() + mid + 1, arr.begin() + j + 1, right.begin());
    int l, r;
    for (l = 0, r = 0; l < left.size() && r < right.size();) {
        if (left[l] < right[r])
            arr[i++] = left[l++];
        else if (left[l] >= right[r])
            arr[i++] = right[r++];
    }
    while (l < left.size())
        arr[i++] = left[l++];
}

void merge_sort(vector<int> &arr, int i, int j) {
    if (!arr.size() || i >= j)
        return ;
    int mid = i + (j - i) / 2;
    merge_sort(arr, i, mid);
    merge_sort(arr, mid + 1, j);
    merge(arr, i, mid, j);
}

int main() {
    vector<int> arr = { 2, 3, 5, -1, -5, 10, 9, 7, 11, 6};
    merge_sort(arr, 0, arr.size() - 1);
    for (auto x: arr) 
        cout << x << endl;
    cout << " ===== " << endl;
    vector<int> arr2 = { 1, 0};
    merge_sort(arr2, 0, arr2.size() - 1);
    for (auto x: arr2) 
        cout << x << endl;
    cout << " ===== " << endl;
    vector<int> arr3 = { 1 };
    merge_sort(arr3, 0, arr3.size() - 1);
    for (auto x: arr3) 
        cout << x << endl;
}