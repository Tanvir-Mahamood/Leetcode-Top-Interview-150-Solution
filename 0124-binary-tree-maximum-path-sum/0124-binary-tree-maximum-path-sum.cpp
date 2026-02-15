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
private:
    int dfs(TreeNode* node, int &res1) {
        if(!node) return 0;

        int leftSum = max(0, dfs(node->left, res1));
        int rightSum = max(0, dfs(node->right, res1));

        // either splitting has done on child subtree, or spitting has done on current node
        res1 = max(res1, leftSum + rightSum + node->val); // with splitting
        int res2 = max(leftSum, rightSum) + node->val; // without splitting

        return res2;
    }

public:
    int maxPathSum(TreeNode* root) {
        int res1 = root->val;
        dfs(root, res1);
        return res1;
    }
};