
#include <iostream>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void bfs(TreeNode *root) {
     if (!root)
        return ;
    queue<TreeNode *> q;

    q.push(root);
    while (!q.empty()) {
        for (int siz = q.size(); siz; siz--) {
            TreeNode *cur = q.front(); q.pop();
            cout << cur->val << " ";
            if (cur->left)
                q.push(cur->left); 
            if (cur->right)
                q.push(cur->right);   
        }
        cout << " [end of the level]" << endl;
    }
}

// i think doing bfs recursively is not worth the time learning
void bfs2(TreeNode *root) { // ORDER ONLY 
    if (!root)
        return ;
    queue<TreeNode *> q;

    q.push(root);
    while (!q.empty()) {
        TreeNode *cur = q.front(); 
        q.pop();
        cout << cur->val << endl; 
        if (cur->left)
            q.push(cur->left); 
        if (cur->right)
            q.push(cur->right);   
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    bfs(root);
    bfs2(root);
    return 0;
}