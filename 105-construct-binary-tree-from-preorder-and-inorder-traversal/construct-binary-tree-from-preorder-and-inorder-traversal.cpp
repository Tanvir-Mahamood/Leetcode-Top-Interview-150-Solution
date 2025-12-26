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
    int preIdx = 0;
    unordered_map<int, int> mp;

    TreeNode* BT(vector<int>& preorder, int left, int right) {
        if(left > right) return nullptr;

        int val = preorder[preIdx++];

        TreeNode* node = new TreeNode(val);

        int inIdx = mp[val];

        node->left = BT(preorder, left, inIdx-1);
        node->right = BT(preorder, inIdx+1, right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return BT(preorder, 0, inorder.size()-1);
    }
};