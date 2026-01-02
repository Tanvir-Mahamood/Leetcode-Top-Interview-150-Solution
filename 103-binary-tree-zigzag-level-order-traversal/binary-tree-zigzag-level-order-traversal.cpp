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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        stack<TreeNode*> currLevel, nextLevel;
        vector<int> level;
        vector<vector<int>> ans;
        bool LeftToRight = true;

        currLevel.push(root);
        
        while(currLevel.size()) {
            TreeNode* temp = currLevel.top();
            currLevel.pop();
            
            level.push_back(temp->val);
            
            if(LeftToRight) {
                if(temp->left) nextLevel.push(temp->left);
                if(temp->right) nextLevel.push(temp->right);
            }
            else {
                if(temp->right) nextLevel.push(temp->right);
                if(temp->left) nextLevel.push(temp->left);
            }

            if(currLevel.size() == 0) {
                LeftToRight = !LeftToRight;
                swap(currLevel, nextLevel);
                ans.push_back(level);
                level.clear();
            }
        }
        return ans;
    }
};