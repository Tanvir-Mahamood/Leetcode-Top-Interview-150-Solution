/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* curr, unordered_map<Node*, Node*> &mp) {
        Node* clone = new Node(curr->val);
        vector<Node*> neighbors;
        mp[curr] = clone;
        for(Node* it: curr->neighbors) {
            if(mp.find(it) != mp.end()) { // found
                neighbors.push_back(mp[it]);
            }
            else { // not found
                neighbors.push_back(dfs(it, mp));
            }
        }
        clone->neighbors = neighbors;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;

        if(!node) return nullptr;
        return dfs(node, mp);
    }
};