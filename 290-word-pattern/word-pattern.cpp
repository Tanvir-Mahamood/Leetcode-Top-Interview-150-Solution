class Solution {
public:
    void stringToWords(string container, vector<string> &words) {
        istringstream iss(container);
        string word;
        while(iss>>word)
            words.push_back(word);
    }

    bool wordPattern(string pattern, string s) {
        vector<string> mp(26, "");
        map<string, int> cnt;

        vector<string> words;
        stringToWords(s, words);

        if(pattern.size() != words.size()) return false;
        
        int i, ch;
        string word;
        for(i=0; i<pattern.size(); i++) {
            ch = pattern[i] - 'a';
            word = words[i];

            if(mp[ch] == "" && !cnt[word]) {
                mp[ch] = word;
                cnt[word]++;
            }
            else if(mp[ch] == "") return false;
            else if(mp[ch] != "" && mp[ch] != word) return false;
        }
        return true;
    }
};