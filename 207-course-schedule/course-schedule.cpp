class Solution {
private:
    bool isCycle(vector<vector<int>>& adj, vector<int>& visited, int i) {
        if (visited[i] == 1) {
            return true;
        }

        if (visited[i] == 0) {
            visited[i] = 1;
            for (const auto& next : adj[i]) {
                if (isCycle(adj, visited, next)) {
                    return true;
                }
            }
        }
        visited[i] = 2;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (isCycle(adj, visited, i)) {
                return false;
            }
        }

        return true;
    }
};