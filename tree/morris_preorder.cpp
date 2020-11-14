
#include <iostream>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void Morris_preorder(TreeNode *root) {
    TreeNode *prev, *cur = root;
    while (cur) {
        if (!cur->left) {
            cout << cur->val << endl;
            cur = cur->right;
        } else {
            prev = cur->left;
            while (prev->right && prev->right != cur)
                prev = prev->right;
            if (!prev->right) { // 做链接的时候就打印了
                cout << cur->val << endl;
                prev->right = cur;
                cur = cur->left;
            } else {
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    Morris_preorder(root);
    return 0;
}