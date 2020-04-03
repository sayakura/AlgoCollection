// namespace std have been included for this problem.
#include <queue>

#include<iostream>
using namespace std;

typedef struct treeNode{
    int value;              /* value of the node */
    struct treeNode* left;  /* pointer to the left child node */
    struct treeNode* right; /* pointer to the right child node */
} treeNode;
// Add any helper functions(if needed) above.
int find_max_sum_level(treeNode* root)
{
    if (!root)
        return -1;
    queue<treeNode *> q;
    int maxNum = 0;
    int maxIdx = 0;
    int level = 0;
    treeNode *tmp = root;
    q.push(tmp);
    while (!q.empty()) {
        int siz = q.size();
        int LvlSum = 0;
        while (siz--) {
            tmp = q.front();
            LvlSum += tmp->value;
            q.pop();
            if (tmp->left)
                q.push(tmp->left);
            if (tmp->right)
                q.push(tmp->right);
        } 
        if (LvlSum > maxNum) {
            maxNum = LvlSum;
            maxIdx = level;
        }
        level++;
    }
    return maxIdx;
}


int main() {

    treeNode *root = new treeNode{7, new treeNode{2, nullptr, nullptr}, new treeNode{0, nullptr, nullptr}};

    cout << find_max_sum_level(root);
}