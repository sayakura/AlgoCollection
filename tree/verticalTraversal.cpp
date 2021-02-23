/** 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> nodes;
    void dfs(TreeNode* root, int x, int y){
        if(!root) return;
        nodes.push_back({x, y, root->val});
        if (root->left) dfs(root->left, x-1, y+1);
        if (root->right) dfs(root->right, x+1, y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        sort(nodes.begin(), nodes.end());
        vector<vector<int>> res;

        int curx = nodes[0][0];
        res.push_back({ nodes[0][2] });
        for (int i = 1; i< nodes.size(); ++i){
            if(nodes[i][0] == curx)
                res.back().push_back(nodes[i][2]);
            else{
                curx = nodes[i][0];
                res.push_back({nodes[i][2]});
            }
        }
        return res;
    }
};

int main () {
    int arr[] = { 0,8,1,-1,-1,3,2,-1,4,5,-1,-1,7,6 };

    return 0;
}


