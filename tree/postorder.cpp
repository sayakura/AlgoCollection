
#include <iostream>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postorderRec(TreeNode *root) {
    if (!root)
        return ;
    postorderRec(root->left);
    postorderRec(root->right);
    cout << root->val << endl;
}

/**
 * doing it with one stack doesnt look intuitive, therefore I only provided this solution
 * this solution is intuitive, the space is O(2n) -> O(n)
 * 
**/
void postorder2Stack(TreeNode *root) {
    if (!root)
        return ;
    stack<TreeNode *>   s;
    stack<int>          out;
    
    s.push(root);               //starting from root
    while (!s.empty()) {
        TreeNode *cur = s.top();
        s.pop();
        
        out.push(cur->val);     // with postorder traversal, the parent is processed lastly (that's why stack is used here)
        if (cur->left)          // go in to left child first
            s.push(cur->left);
        if (cur->right)         // and then right child
            s.push(cur->right);
    }
    while (!out.empty()) {      // all the childeren get printed before every parent
        cout << out.top() << endl;
        out.pop();
    }
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    postorderRec(root);
    postorder2Stack(root); 
    return 0;
}