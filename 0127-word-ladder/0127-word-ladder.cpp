class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictionary(wordList.begin(), wordList.end());
        if(!dictionary.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, int> distance;
        distance[beginWord] = 1;

        while(!q.empty()) {
            string current = q.front();
            q.pop();

            if(current == endWord) return distance[current];

            // children generation
            for(int i=0; i<current.size(); i++) {
                string child = current;
                for(char c='a'; c<='z'; c++) {
                    child[i] = c;
                    if(dictionary.count(child) && !distance.count(child)) {
                        distance[child] = distance[current] + 1;
                        q.push(child);
                    }
                }
            }
        }
        return 0;
    }
};