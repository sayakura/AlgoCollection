/** 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <unordered_map>
#include <queue>

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ret;
        unordered_map<int, vector<int>> ghm;
        unordered_map<int, TreeNode *> hm;
        int lastLeftMost = 0;
        int lastRightMost = 0;
        int level = 0;
        
        if (!root)
            return ret;
        hm[0] = root;
        ghm[0].push_back(root->val);
        while (hm.size()) {
            unordered_map<int, TreeNode *> tmp;
            for (int i = lastLeftMost; i <= lastRightMost; i++) {
                if (hm[i]) {
                    if (hm[i]->left) {
                        tmp[i - 1] = hm[i]->left;
                        ghm[i - 1].push_back(hm[i]->left->val);
                        lastLeftMost = min(lastLeftMost, i - 1);
                    }
                    if (hm[i]->right) {
                        tmp[i + 1] = hm[i]->right;
                        ghm[i + 1].push_back(hm[i]->right->val);
                        lastRightMost = max(lastRightMost, i + 1);
                    }
                }
            }
            hm = tmp;
        }
        for (int i = lastLeftMost; i <= lastRightMost; i++) { 
            if (ghm.count(i))
                ret.push_back(ghm[i]);
        }
        return ret;        
    }
};

int main () {
    int arr[] = { 0,8,1,-1,-1,3,2,-1,4,5,-1,-1,7,6 };

    return 0;
}