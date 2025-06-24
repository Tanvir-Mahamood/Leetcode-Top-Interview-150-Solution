class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        ios::sync_with_stdio(false);
        cin.tie(0);

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(int i=0; i<prerequisites.size(); i++)
        {
            int a = prerequisites[i][0], b = prerequisites[i][1];
            adj[b].push_back(a);
            indegree[a] += 1;
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<numCourses; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            for(int child: adj[node])
            {
                indegree[child]--;
                if(indegree[child] == 0) q.push(child);
            }
        }
        if(ans.size() != numCourses) return {};
        else return ans;
    }
};