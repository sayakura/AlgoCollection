
#include <iostream>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void preorderRec(TreeNode *root) {
    if (!root)
        return ;
    cout << root->val << endl;
    preorderRec(root->left);
    preorderRec(root->right);
}

void preorder2Stack(TreeNode *root) {
    if (!root)
        return ;
    stack<TreeNode *>   s;
    
    s.push(root);
    while (!s.empty()) {
        TreeNode *cur = s.top();
        s.pop();

        cout << cur->val << endl; // print parent directly 
        if (cur->right)           // left print before right, so right go to the stack first
            s.push(cur->right);
        if (cur->left)
            s.push(cur->left);

    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    preorderRec(root);
    preorder2Stack(root); 
    return 0;
}