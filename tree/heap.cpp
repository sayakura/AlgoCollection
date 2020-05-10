#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

template <typename T>
class Heap {
    vector<T> arr;
    function<bool(T, T)> cmp;
public:
    Heap(vector<T>array, function<bool(T, T)> comparerator) : arr(array), cmp(comparerator) {
        heapifyAll();
    }
    Heap(function<bool(T, T)> comparerator) : cmp(comparerator) {}
    void heapify(int i) {
        size_t size = arr.size();
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < size && cmp(arr[left], arr[largest]))
            largest = left;
        if (right < size && cmp(arr[right], arr[largest]))
            largest = right;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }
    void heapifyAll() {
        size_t size = arr.size();
        for (int i = size / 2 - 1; i >= 0; i--) 
            heapify(i);
    }
    void insert(int newNum) {
        arr.push_back(newNum);
        if (arr.size() == 1)
            return ;
        heapifyAll();
    }
    void deleteNode(int target) {
        int i;
        for (i = 0; i < arr.size(); i++) {
            if (arr[i] == target)
                break ;
        }
        swap(arr[i], arr[arr.size() - 1]);
        arr.pop_back();
        heapifyAll();
    }
    T top() {
        if (arr.size() > 0)
            return arr[0];
        throw "No Element in the Heap";
    }
    void pop() {
        if (arr.size() == 0)
            throw "No Element in the Heap";
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        heapifyAll();
    }
    bool empty() {
        return arr.size() == 0;
    }
};

int main() {
    vector<int> array = {4, 1, 5, 2, 6, 8, 12, 3};
    Heap<int> minh(array, [](int a, int b) {
        return a < b;
    });
    while (!minh.empty()) {
        cout << minh.top() << " ";
        minh.pop();
    }
    
    cout << endl;
    Heap<int> maxh(array, [](int a, int b) {
        return a > b;
    });
    while (!maxh.empty()) {
        cout << maxh.top() << " ";
        maxh.pop();
    }
    cout << endl;
}