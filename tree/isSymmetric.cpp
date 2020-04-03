struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/** a valid symmetric tree 
    1
   / \
  2   2
 / \ / \
3  4 4  3

after flipping
    1
   / \
  2   2
 / \ / \
3  4 3  4
**/
bool isSymmetric(TreeNode* root) {
    return isMirror(root, root);
}
bool isMirror(TreeNode *l, TreeNode *r) {
    if (!l && !r) return true;
    if (!l || !r) return false;
    return (l->val == r->val)&& isMirror(r->left, l->right) && isMirror(r->right, l->left); // we flip the right and left child so that the should be the same
}
