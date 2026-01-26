class Solution {
public:
    vector<string> ans;

    void helper(int level, string temp, char ch, string &digits, unordered_map<char, string> &keyPad) {
        int next_level = level + 1;
        if(ch != '.') temp += ch;
        if(next_level >= digits.size()) {
            ans.push_back(temp);
            return;
        }
        string next_alpha = keyPad[digits[next_level]];
        
        for(char ch1: next_alpha) {
            helper(next_level, temp, ch1, digits, keyPad);
        }

    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> keyPad = {
                                            {'2', "abc"},
                                            {'3', "def"},
                                            {'4', "ghi"},
                                            {'5', "jkl"},
                                            {'6', "mno"},
                                            {'7', "pqrs"},
                                            {'8', "tuv"},
                                            {'9', "wxyz"}
                                        };

        helper(-1, "", '.', digits, keyPad);
        return ans;
    }
};