/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

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
        level.clear();
        return root;
    }
};