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
    
    int Search(vector<int>& inorder, int left, int right, int val) {
        for(int i=left; i<=right; i++) {
            if(inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* BT(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if(left > right) return nullptr;

        int val = preorder[preIdx++];

        TreeNode* node = new TreeNode(val);

        int inIdx = Search(inorder, left, right, val);

        node->left = BT(preorder, inorder, left, inIdx-1);
        node->right = BT(preorder, inorder, inIdx+1, right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return BT(preorder, inorder, 0, inorder.size()-1);
    }
};