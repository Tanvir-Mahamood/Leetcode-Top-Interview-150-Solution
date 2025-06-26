class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0, len = 0, i;
        unordered_set<int> seen;
        while(left <= right && right < s.size()) {
            if(!seen.count(s[right])) {
                seen.insert(s[right++]);
                len = max(len, right - left);
            }
            else {
                seen.erase(s[left++]);
            }
        }
        return len;
    }
};