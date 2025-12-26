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
    int preIdx;
    unordered_map<int, int> mp;

    TreeNode* BT(vector<int>& postorder, int left, int right) {
        if(left > right) return nullptr;

        int val = postorder[preIdx--];

        TreeNode* node = new TreeNode(val);

        int inIdx = mp[val];

        node->right = BT(postorder, inIdx+1, right);
        node->left = BT(postorder, left, inIdx-1);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        preIdx = inorder.size() - 1;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return BT(postorder, 0, inorder.size()-1);
    }
};