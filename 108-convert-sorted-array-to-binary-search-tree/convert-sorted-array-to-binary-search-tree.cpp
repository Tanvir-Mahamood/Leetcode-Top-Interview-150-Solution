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
    TreeNode* bst(int left, int right, vector<int> &nums) {
        if(left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = bst(left, mid-1, nums);
        node->right = bst(mid+1, right, nums);

        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = bst(0, n-1, nums);
        return root;
    }
};