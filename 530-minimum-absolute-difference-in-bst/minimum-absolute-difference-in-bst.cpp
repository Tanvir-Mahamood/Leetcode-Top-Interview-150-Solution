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
    int prev = 100005, curr, minVal = 100005;

    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);

        curr = root->val;
        int diff = abs(curr - prev);
        minVal = min(minVal, diff);
        prev = curr;

        inorder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minVal;
    }
};