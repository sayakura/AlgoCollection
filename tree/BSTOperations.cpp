#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node *newNode(int key) {
    return new Node{ key, nullptr, nullptr };
}

void inorder(Node * root) {
    if (!root)
        return ;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);    
}

Node *insert(Node *root, int key) {
    if (!root)  return newNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

void    insert2(Node* &root, int key) {
    if (root == nullptr) {
        root = newNode(key);
        return ;
    } 

    if (key < root->data)
        insert2(root->left, key);
    else
        insert2(root->right, key);
}


int main() {
    Node *root = nullptr;
    int keys[] = {15, 10, 20, 8, 12, 16, 25};    
    
    for (int key: keys) 
        root = insert(root, key);
    inorder(root);
    cout << endl;
    Node *root2 = nullptr;
    
    for (int key: keys) 
        insert2(root2, key);
    inorder(root);
    cout << endl;
}