#include <vector>
#include <iostream>

using namespace std;

int partition(vector<int> arr, int left, int right, int k) {
    int pilot = arr[right];
    int l = left;
    for (int i = left; i < right; i++) {
        if (arr[i] <= pilot)
            swap(arr[l++], arr[i]);
    }
    swap(arr[l], arr[right]);
    return l;
}

int quickSelect(vector<int> arr, int k) {
    // k largest  -> N - K smallest
    /*
    asdasdasda
    */
    const int N = arr.size();
    int K = N - k;
    int left = 0, right = N - 1;
    while (left <= right) {
        int pilot = partition(arr, left, right, k);
        if (pilot == k) 
            return arr[pilot];
        else if (pilot < k) 
            left = pilot + 1;
        else 
            right = pilot - 1;
    }
    return arr[pilot];
}



int main() {



}
