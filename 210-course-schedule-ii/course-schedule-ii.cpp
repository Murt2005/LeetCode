class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;
        int processed = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            processed++;
            result.push_back(course);

            for (int next : adj[course]) {
                inDegree[next]--;
                if (inDegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (processed != numCourses) {
            return {};
        }

        return result;
    }
};