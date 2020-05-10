#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int val;
    Node *left, *right;
};

Node *insertLevelOrder(vector<int> arr, Node *root, int i) {
    if (i < arr.size()) {
        Node *cur = new Node{arr[i], nullptr, nullptr};
        cur->left = insertLevelOrder(arr, cur->left, 2 * i + 1);
        cur->right = insertLevelOrder(arr, cur->right, 2 * i + 2);
        root = cur;
    }
    return root;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto root = insertLevelOrder(arr, nullptr, 0);
    
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        auto &n = q.front(); q.pop();
        cout << n->val << endl;
        if (n->left)
            q.push(n->left);
        if (n->right)
            q.push(n->right);
    }
    return 0;
}