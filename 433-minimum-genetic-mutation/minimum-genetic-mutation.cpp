class Solution {
public:
    // comparig 2 gene to check if there is an exact 1 mutation 
    bool isChild(string a, string b) {
        int cnt = 0;
        for(int i=0; i<a.size(); i++) {
            if(a[i] != b[i]) cnt++;
        }
        return (cnt == 1);
    }

    void bfs(string source, vector<string>& bank, unordered_map<string, int> &distance) {
        queue<string> q;
        distance[source] = 0;
        q.push(source);
        while(!q.empty()) {
            string currGene = q.front();
            q.pop();
            
            for(string child: bank) {
                if(isChild(child, currGene) && distance.find(child) == distance.end()) {
                    distance[child] = distance[currGene] + 1;
                    q.push(child);
                }
            }
        }
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, int> distance;
        bfs(startGene, bank, distance);

        auto it = distance.find(endGene);
        if(it != distance.end()) return it->second;
        else return -1;
    }
};