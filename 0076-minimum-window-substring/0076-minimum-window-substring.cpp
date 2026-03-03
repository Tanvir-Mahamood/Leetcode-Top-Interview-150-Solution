class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        int left = 0, right = 0, idx, minLength = INT_MAX, cnt = 0;
        unordered_map<char, int> mp;
        for(char ch: t) {
            mp[ch]++;
        }

        for(right=0; right<s.size(); right++) {
            char ch = s[right];
            if(mp[ch] > 0) {
                cnt++;
            }
            mp[ch]--;

            while(cnt == t.size()) { // minimize it
                int substrLength = right - left + 1;
                if(minLength > substrLength) {
                    minLength = min(minLength, substrLength);
                    idx = left;
                }
                char leftChar = s[left];
                mp[leftChar]++;
                left++;
                if(mp[leftChar] > 0) {
                    cnt--;
                }
            }
        }
        if(minLength == INT_MAX) return "";
        return s.substr(idx, minLength);
    }
};