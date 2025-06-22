class Solution {
public:
    int romanToInt(string s) {
        ios::sync_with_stdio(false); cin.tie(0);
        
        unordered_map<char, int> pos(7);
        pos['I'] = 1;
        pos['V'] = 5;
        pos['X'] = 10;
        pos['L'] = 50;
        pos['C'] = 100;
        pos['D'] = 500;
        pos['M'] = 1000;

        int ans = pos[s[0]];
        for(int i=1; i<s.size(); i++) {
            ans += pos[s[i]];
            if(pos[s[i]] > pos[s[i-1]]) ans -= (2 * pos[s[i-1]]);
        }
        return ans;
    }
};