class Solution {
private:
    void dfs(int node, double dist, vector<vector<pair<int,double>>> &adj, vector<double> &distance) {
        int i;
        distance[node] = dist;
        for(auto child: adj[node]) {
            int childNode = child.first;
            double weight = child.second;
            if(distance[childNode] == -1) {
                dfs(childNode, distance[node] * weight, adj, distance);
            }
        }
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> nodeIndex;
        vector<vector<pair<int,double>>> adj;
        vector<double> ans;
        vector<double> distance;
        int idx = 0;

        for(int i=0; i<equations.size(); i++) { // adjacency list construction
            string node1 = equations[i][0];
            string node2 = equations[i][1];
            double weight = values[i];

            if(nodeIndex.find(node1) == nodeIndex.end()) { // integer index not found for node1
                nodeIndex[node1] = idx++; 
                adj.push_back({});
            }
            if(nodeIndex.find(node2) == nodeIndex.end()) { // integer index not found for node2
                nodeIndex[node2] = idx++;
                adj.push_back({});
            }
            int node1_idx =  nodeIndex[node1];
            int node2_idx =  nodeIndex[node2];

            adj[node1_idx].push_back({node2_idx, weight});
            adj[node2_idx].push_back({node1_idx, 1/weight});
        }

        for(auto query: queries) {
            string dividend = query[0];
            string divisor = query[1];

            int idx_dividend = (nodeIndex.find(dividend) == nodeIndex.end()) ? -1 : nodeIndex[dividend];
            int idx_divisor =  (nodeIndex.find(divisor) == nodeIndex.end()) ? -1 : nodeIndex[divisor];

            if(idx_dividend == -1 || idx_divisor == -1) {
                ans.push_back(-1.0);
                continue;
            }

            distance.assign(idx, -1);

            dfs(idx_dividend, 1, adj, distance);
            ans.push_back(distance[idx_divisor]);
        }
        return ans;
    }
};