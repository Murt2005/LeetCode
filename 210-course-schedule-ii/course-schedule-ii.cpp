class Solution {
private:
    bool isCycle(vector<vector<int>>& adj, vector<int>& visited, int i, vector<int>& result) {
        if (visited[i] == 1) {
            return true;
        }

        if (visited[i] == 2) {
            return false;
        }

        visited[i] = 1;

        for (const auto& next : adj[i]) {
            if (isCycle(adj, visited, next, result)) {
                return true;
            }
        }
        visited[i] = 2;
        result.push_back(i);
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> result;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (isCycle(adj, visited, i, result)) {
                    return { };
                }
            }
            
        }

        reverse(result.begin(), result.end());
        return result;
    }
};




// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses);
//         vector<int> inDegree(numCourses, 0);

//         for (const auto& pre : prerequisites) {
//             adj[pre[1]].push_back(pre[0]);
//             inDegree[pre[0]]++;
//         }

//         queue<int> q;
//         for (int i = 0; i < numCourses; i++) {
//             if (inDegree[i] == 0) {
//                 q.push(i);
//             }
//         }

//         vector<int> result;
//         int processed = 0;
//         while (!q.empty()) {
//             int course = q.front();
//             q.pop();
//             processed++;
//             result.push_back(course);

//             for (int next : adj[course]) {
//                 inDegree[next]--;
//                 if (inDegree[next] == 0) {
//                     q.push(next);
//                 }
//             }
//         }

//         if (processed != numCourses) {
//             return {};
//         }

//         return result;
//     }
// };