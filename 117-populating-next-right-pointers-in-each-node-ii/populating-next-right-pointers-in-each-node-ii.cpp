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
    Node* head;
    vector<Node*> level;

    void solve(Node* node, int h) {
        if(!node) return;

        node->next = level[h];
        level[h] = node;

        solve(node->right, h+1);
        solve(node->left, h+1);
        return;
    }

    Node* connect(Node* root) {
        level.resize(6001);
        for(int i=0; i<6001; i++) level[i] = nullptr;

        head = root;
        solve(root, 0);
        return head;
    }
};