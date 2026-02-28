class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), wordLength = words[0].size(), totalWords = words.size();
        vector<int> ans;

        unordered_map<string, int> targetFreq;
        for(string word: words) {
            targetFreq[word]++;
        }
        for(int offset=0; offset<wordLength; offset++) {
            int left = offset;
            unordered_map<string, int> currentFreq;
            int cnt = 0;
            for(int right=offset; right+wordLength<=n; right+=wordLength) {
                string word = s.substr(right, wordLength);

                if(targetFreq[word]) {
                    currentFreq[word]++;
                    cnt++;

                    while(currentFreq[word] > targetFreq[word]) {
                        string leftWord = s.substr(left, wordLength); // to be deleted
                        currentFreq[leftWord]--;
                        cnt--;
                        left += wordLength;
                    }

                    if(cnt == totalWords) {
                        ans.push_back(left);  
                    }
                }
                else {
                    currentFreq.clear();
                    cnt = 0;
                    left = right + wordLength;
                }
            }
        }

        return ans;
    }
};