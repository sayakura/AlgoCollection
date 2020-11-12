#include <iostream>
#include <vector>

using namespace std;


void printArray(vector<vector<int>> &arr) {
    // for (int i = 0, j = 0; i < arr.size() ; j++) {
    //     if (j >= arr[i].size()) {
    //         i++; 
    //         if (i == arr.size()) break; 
    //         j = 0;
    //     }
    //     if (j < arr[i].size())
    //         cout << arr[i][j] << endl;
    // }
    if (!arr.size()) return ;
    int i, j;
    i = j = 0;
    while (1) {
        if (j >= arr[i].size()) {
            i++;
            if (i == arr.size()) break; 
            j = 0;
        }
        if (j < arr[i].size())
            cout << arr[i][j] << endl;
        j++;
    }
}

int main() {
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9, 10, 11},
        {},
        {12, 13}
    };
    printArray(arr);
}