class Solution {
public:
    vector<Node*> level;

    void solve(Node* node, int h) {
        if(!node) return;

        node->next = (h < level.size()) ? level[h] : nullptr;
        if(h >= level.size()) level.resize(h+1, nullptr);
        level[h] = node;

        solve(node->right, h+1);
        solve(node->left, h+1);
    }

    Node* connect(Node* root) {
        level.clear();
        solve(root, 0);
        return root;
    }
};