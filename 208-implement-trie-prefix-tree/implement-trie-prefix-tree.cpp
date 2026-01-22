struct Node {
    Node* link[26];
    bool flag = false;

    bool containKey(char ch) {
        return (link[ch-'a'] != NULL);
    }

    void put(char ch, Node* reff) {
        link[ch-'a'] = reff;
    }

    Node* get(char ch) {
        return link[ch-'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node(); // taking a root
    }
    
    void insert(string word) { //O(len(word))
        Node* node = root; // initially pointing to the root for each insertion
        for(char ch: word) {
            if(!node->containKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch); // move to next (referenced) node
        }
        node->setEnd();
    }
    
    bool search(string word) { //O(len(word))
        Node* node = root;
        for(char ch: word) {
            if(!node->containKey(ch)) {
                return false;
            }
            node = node->get(ch); // good to go
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) { //O(len(word))
        Node* node = root;
        for(char ch: prefix) {
            if(!node->containKey(ch)) {
                return false;
            }
            node = node->get(ch); // good to go
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */