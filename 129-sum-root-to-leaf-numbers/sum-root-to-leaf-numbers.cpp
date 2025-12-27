/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int allSum = 0;

    void solve(TreeNode* node, int num) {
        num = num*10 + node->val;

        if(node->left)  solve(node->left, num);
        if(node->right) solve(node->right, num);

        if(!node->left && !node->right) allSum += num;
    }

    int sumNumbers(TreeNode* root) {
        solve(root, 0);
        return allSum;
    }
};