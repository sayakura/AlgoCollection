struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isEqual(TreeNode *s, TreeNode *t) {
    if (!s && !t) // they just have to be the same
        return true;
    if (!s || !t)
        return false;
    return s->val == t->val && isEqual(s->left, t->left) && isEqual(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if (!t) // idk if a empty subtree t will be a valid subtree of s or not, I assume it is 
        return true;
    return s && (isEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t));
}