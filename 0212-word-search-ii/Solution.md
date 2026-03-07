# C++ | Trie + DFS Backtracking 

# Intuition
Searching for each word individually in the grid using standard DFS would be highly inefficient ($$O(W \cdot M \cdot N \cdot 4^L)$$). By building a Trie of all target words, we can traverse the board once and check for all potential word matches simultaneously. If a prefix doesn't exist in our Trie, we can prune the search immediately, saving significant time.

# Approach
  - **Trie Construction:** Insert all input words into a Trie. Each leaf node (or end-of-word node) stores the actual word string for easy retrieval.
  - **Grid Traversal:** Iterate through every cell $$(i, j)$$ in the $M \times N$ board.
  - **Backtracking DFS:** For each cell, initiate a DFS if the character exists as a child of the Trie root.
      - **Mark Visited:** Temporarily replace the current character with `#` to avoid reusing the same cell in a single word path.
      - **Trie Matching:** Move down the Trie as we move through the grid.
      - **Found a Word:** If a node is marked as `isEnd`, add the stored word to our results. Set `flag = false` immediately to prevent adding the same word multiple times.
      - **Restore:** After exploring all 4 directions, restore the original character (backtrack).
  - **Optimization:** The Trie allows us to "fail fast." If a path on the board doesn't match any prefix in our Trie, the recursion stops.

# Complexity
- Time complexity:
$$O(M \times N \times 4^L)$$

- Space complexity:
$$O(S)$$

# Code
```cpp []
//===================== Trie Template ================================

struct Node {
    Node *links[26];
    bool flag = false;
    string word = "";

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
        root = new Node(); // creating new object
    }

    void Insert(string word) { // O(len(word))
        Node* node = root; // initializing empty node pointing to root initially
        for(int i=0; i<word.size(); i++) {
            if(!node->ContainsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]); // Moves to the reference trie
        }
        node->setEnd(word);
    }
};

//====================================================================

class Solution {
private:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    bool isValid(int x, int y, vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        if(x < 0 || x >= row || y < 0 || y >= col) return false;
        if(board[x][y] == '#') return false;
        return true;
    }

    void dfs(vector<vector<char>>& board, int x, int y, Node* node, vector<string> &ans) {
        char ch = board[x][y];

        if(!node->ContainsKey(ch)) {
            return;
        }

        node = node->get(ch);

        if(node->isEnd()) {
            ans.push_back(node->word);
            node->flag = false; // avoid duplication
        }

        board[x][y] = '#'; // marking as visited

        for(int i=0; i<4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if(isValid(new_x, new_y, board)) {
                dfs(board, new_x, new_y, node, ans);
            }
        }
        board[x][y] = ch; // restoration
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int row = board.size();
        int col = board[0].size();
        vector<string> ans;

        Trie trie;
        for(string word: words) {
            trie.Insert(word);
        }

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                dfs(board, i, j, trie.root, ans);
            }
        }

        return ans;
    }
};
```
# My Trie Templates:
https://github.com/Tanvir-Mahamood/Competitive-Programming/tree/main/Algorithm/Trie


