//=========================== Trie Template =======================

struct Node {
    Node *links[26];
    bool flag = false;
    string word = ""; // store full word

    bool ContainsKey(char ch) {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }
    Node *get(char ch) {
        return links[ch-'a'];
    }
    void setEnd(string w) {
        flag = true;
        word = w;
    }
    bool isEnd() {
        return flag;
    }
};

class Trie
{
public:
    Node* root;

    Trie() {
        root = new Node(); //creating new object
    }

    void Insert(string word) { //O(len(word))
        Node* node = root; //initializing empty node pointing to root initially
        for(int i=0; i<word.size(); i++) {
            if(!node->ContainsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]); //Moves to the reference trie
        }
        node->setEnd(word);
    }
};

//==================================================================

class Solution {
public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    void dfs(vector<vector<char>>& board, int i, int j, Node* node, vector<string>& ans) {
        char ch = board[i][j];

        if(ch == '#' || !node->ContainsKey(ch))
            return;

        node = node->get(ch);

        if(node->isEnd()) {
            ans.push_back(node->word);
            node->flag = false; // avoid duplicate
        }

        board[i][j] = '#';

        int row = board.size();
        int col = board[0].size();

        for(int d=0; d<4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if(ni>=0 && nj>=0 && ni<row && nj<col) {
                dfs(board, ni, nj, node, ans);
            }
        }

        board[i][j] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for(string word: words) {
            trie.Insert(word);
        }

        vector<string> ans;
        int row = board.size();
        int col = board[0].size();
        // vector<vector<bool>> visited(row,vector<bool>(col, false));

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                dfs(board, i, j, trie.root, ans);
            }
        }

        return ans;
    }
};