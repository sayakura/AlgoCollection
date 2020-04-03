
#include <iostream>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderRec(TreeNode *root) {
    if (!root)
        return ;
    inorderRec(root->left);
    cout << root->val << endl;
    inorderRec(root->right);
}

void inorder2Stack(TreeNode *root) {
    if (!root)
        return ;
    stack<TreeNode *>   s;
    
    while (!s.empty() || root) {    // !s.empty() is for the left subtree, root is for right substree
        while (root) {
            s.push(root);           // push parent first, but move down to the left child path
            root = root->left;      // this ensures the left subtree is pushed to the stack including parent of da subtree(root)
        }
        root = s.top();             // print leftest child first, the next one will be parent(on the stack)
        cout << root->val << endl;
        s.pop();
        root = root->right;          // see if we have right child, if yes we do the same thing to right child, we pushed this child to stack because we need to print him
    }
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    inorderRec(root);
    inorder2Stack(root); 
    return 0;
}