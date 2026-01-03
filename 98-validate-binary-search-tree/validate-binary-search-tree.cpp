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
    bool status = true, isEmptyPrev = true;
    int prev, curr;

    void inorder(TreeNode* root) {
        if(!root) return;
        inorder(root->left);

        curr = root->val;
        if(!isEmptyPrev && prev >= curr) {
            status = false;
            return;
        }
        prev = curr;
        isEmptyPrev = false;

        inorder(root->right);
    }

    bool isValidBST(TreeNode* root) {
        inorder(root);
        return status;
    }
};