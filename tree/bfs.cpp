
#include <iostream>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// i think doing bfs recursively is not worth the time learning
void bfs(TreeNode *root) {
    if (!root)
        return ;
    queue<TreeNode *> q;

    q.push(root);
    while (!q.empty()) {
        TreeNode *tmp = q.front(); 
        q.pop();
        cout << tmp->val << endl; 
        if (tmp->left)
            q.push(tmp->left); 
        if (tmp->right)
            q.push(tmp->right);   
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    bfs(root);
    return 0;
}