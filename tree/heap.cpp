#include <vector>
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

class Heap {
    vector<int> arr;
    function<bool(int, int)> cmp;
public:
    Heap(vector<int>array) {
        for (int num : array)
            insert(num);
    }
    Heap() {}
    Heap(function<bool(int, int)> comparerator) : cmp(comparerator) {}
    inline int parent(int i) { 
        int t = (i - 1) / 2;
        if (t < 0)
            return 0;
        return t;
    }
    inline int left(int i) { return i * 2 + 1; }
    inline int right(int i) { return i * 2 + 2; }
    void heapify(int i) {
        size_t size = arr.size();
        int smallest = i;
        int l = left(i);
        int r = right(i);
        if (l < size && arr[l] < arr[smallest])
            smallest = l;
        if (r < size && arr[r] < arr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }
    void insert(int newNum) {
        arr.push_back(newNum);
        if (arr.size() == 1)
            return ;
        int pos = arr.size() - 1;
        for (; pos > 0 && arr[parent(pos)] > newNum; pos = parent(pos)) {
            arr[pos] = arr[parent(pos)];
        }
        arr[pos] = newNum;
    }
    void deleteNode(int target) {
        cout << "delete : " << target << endl;
        int i;
        for (i = 0; i < arr.size(); i++) {
            if (arr[i] == target)
                break ;
        }
        swap(arr[i], arr[arr.size() - 1]);
        arr.pop_back();
        heapify(i);
    }
    int top() {
        if (arr.size() > 0)
            return arr[0];
        throw "No Element in the Heap";
    }
    void pop() {
        if (arr.size() == 0)
            throw "No Element in the Heap";
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        heapify(0);
    }
    bool empty() {
        return arr.size() == 0;
    }
    void print() {
        cout << "heap: ";
        for (int &n : arr)
            cout << n << " ";
        cout << endl;
    }
};

int main() {
    vector<int> array = {4, 1, 5, 2, 6, 8, 12, 3};
    Heap minh;
    minh.insert(4);
    minh.insert(1);
    minh.insert(7);
    minh.insert(3);
    minh.insert(2);
    minh.insert(9);
    minh.insert(12);
    minh.insert(8);
    minh.insert(15);
    minh.print();
    while (!minh.empty()) {
        cout << minh.top() << " ";
        minh.pop();
    }
    cout << endl;

    cout << "second example: " << endl;
    Heap minh2(array);
    minh2.print();
    minh2.deleteNode(8);
    minh2.deleteNode(2);
    minh2.print();
    while (!minh2.empty()) {
        cout << minh2.top() << " ";
        minh2.pop();
    }
    cout << endl;
}