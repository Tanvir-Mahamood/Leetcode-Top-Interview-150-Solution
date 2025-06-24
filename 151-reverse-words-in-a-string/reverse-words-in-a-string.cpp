class Solution {
public:
    string normalizeString(const string& input) {
        string result, word;
        stringstream ss(input);
        // Read words, automatically ignoring extra spaces
        while (ss >> word) {
            if (!result.empty()) {
                result += " "; // Add a single space between words
            }
            result += word;
        }
        return result;
    }

    string reverseWords(string s) {
        ios::sync_with_stdio(false); cin.tie(NULL);
        
        string s2 = normalizeString(s);
        string ans, word;

        for (int i = s2.size() - 1; i >= 0; i--) {
            if (s2[i] == ' ') {
                reverse(word.begin(), word.end());
                word += ' ';
                ans += word;
                word.clear();
            } else
                word += s2[i];
        }
        reverse(word.begin(), word.end());
        ans += word;
        return ans;
    }
};