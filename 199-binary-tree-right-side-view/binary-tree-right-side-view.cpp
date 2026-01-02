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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        vector<int> ans;

        queue<TreeNode*> q;
        q.push(root);
        // traverse level wise, collect last element from each level
        while(q.size()) { 
            int len = q.size();
            for(int i=0; i<len; i++) {
                TreeNode* curr = q.front();
                q.pop();

                if(i == len-1) ans.push_back(curr->val); // the last element
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return ans;
    }
};