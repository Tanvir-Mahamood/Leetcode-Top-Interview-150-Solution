class Solution {
public:
    // yes = cycle found
    // no => cycle not found

    bool dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;

        for(int child: adj[node]) {
            if(!visited[child]) {
                if(dfs(child, adj, visited, pathVisited)) {
                    return true;
                }
            }
            else if(pathVisited[child]) {
                return true;
            }
        }
        pathVisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses, false), pathVisited(numCourses, false);

        for(auto it: prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0; i<numCourses; i++) { // graph can be disjoint
            if(!visited[i]) {
                if(dfs(i, adj, visited, pathVisited)) return false;
            }
        }
        return true;
    }
};

// simply check, if there is a cycle or not.
// if cycle found, then print False