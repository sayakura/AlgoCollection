
#include <iostream>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void Morris_inorder(TreeNode *root) {
    TreeNode *prev, *cur = root;
    while (cur) {
        if (!cur->left) { // 触底了，打印
            cout << cur->val << endl; 
            cur = cur->right;
        } else {
            prev = cur->left;
            while (prev->right && prev->right != cur) 
                prev = prev->right;
            if (!prev->right) {
                prev->right = cur;
                cur = cur->left;
            } else { // 切断之前链接到自己的指针， 同时打印自己，去右边 
                cout << cur->val << endl;
                cur = cur->right;
                prev->right = nullptr;
            }
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    Morris_inorder(root);
    return 0;
}