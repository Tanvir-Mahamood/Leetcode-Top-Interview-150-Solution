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
    void flatten(TreeNode* root) {
        TreeNode* currNode = root;
        while(currNode) {
            if(currNode->left) {
                TreeNode* temp = currNode->left;

                while(temp->right) {
                    temp = temp->right;
                }

                temp->right = currNode->right;
                currNode->right = currNode->left;
                currNode->left = nullptr;
            }
            currNode = currNode->right;
        }
    }
};