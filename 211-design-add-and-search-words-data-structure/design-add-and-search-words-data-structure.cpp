struct Node {
    Node* link[26];
    bool flag = false;

    bool containKey(char ch) {
        return (link[ch-'a'] != NULL);
    }

    bool containIdx(int i) {
        return (link[i] != NULL);
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

class WordDictionary {
private:
    Node* root;

    bool RecursiveSearch(Node* node, string word, int idx) {
        if(idx == word.length()) {
            return node->isEnd();
        }

        char ch = word[idx];
        if(ch == '.') {
            bool result;
            for(char ch1='a'; ch1<='z'; ch1++) {
                if(node->containKey(ch1)) {
                    result = RecursiveSearch(node->get(ch1), word, idx+1);
                    if(result) break;
                }
            }
            return result;
        }
        else if(node->containKey(ch)) {
            return RecursiveSearch(node->get(ch), word, idx+1);
        }
        else {
            return false;
        }
    }

public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root; 
        for(char ch: word) {
            if(!node->containKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch); 
        }
        node->setEnd();
    }
    
    bool search(string word) {
        return RecursiveSearch(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */