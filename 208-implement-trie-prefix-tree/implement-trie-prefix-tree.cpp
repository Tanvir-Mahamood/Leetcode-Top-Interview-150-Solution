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

    bool RecursiveSearch(Node* node, string word, int idx) {
        if(idx == word.length()) {
            return node->isEnd();
        }
        char ch = word[idx];
        if(!node->containKey(ch)) {
            return false;
        }
        return RecursiveSearch(node->get(ch), word, idx+1);
    }

    bool RecursiveSearchWith(Node* node, string prefix, int idx) {
        if(idx == prefix.length()) {
            return true;
        }
        char ch = prefix[idx];
        if(!node->containKey(ch)) {
            return false;
        }
        return RecursiveSearchWith(node->get(ch), prefix, idx+1);
    }

    void RecursiveInsert(Node* node, string word, int idx) {
        if(idx == word.length()) {
            node->setEnd();
            return;
        }
        char ch = word[idx];
        if(!node->containKey(ch)) {
            node->put(ch, new Node());
        }
        RecursiveInsert(node->get(ch), word, idx+1);
    }

public:
    Trie() {
        root = new Node(); // taking a root
    }
    
    void insert(string word) { //O(len(word))
        RecursiveInsert(root, word ,0);
    }
    
    bool search(string word) { //O(len(word))
        return RecursiveSearch(root, word, 0);
    }
    
    bool startsWith(string prefix) { //O(len(word))
        return RecursiveSearchWith(root, prefix, 0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */