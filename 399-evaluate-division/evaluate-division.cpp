class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        int m = queries.size();
        vector<double> ans(m);

        for (int i = 0; i < n; i++) {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }

        for (int i = 0; i < m; i++) {
            queryAns = 1;
            
            if (adjList.find(queries[i][0]) == adjList.end() || adjList.find(queries[i][1]) == adjList.end()) {
                ans[i] = -1;
                continue;
            }
            
            bool pathFound = dfs(queries[i][0], queries[i][1], 1);
            if (!pathFound) {
                ans[i] = -1;
            } else {
                ans[i] = queryAns;
            }
        }

        return ans;
    }

private:
    unordered_map<string, vector<pair<string, double>>> adjList;
    unordered_map<string, bool> visited;
    double queryAns;

    bool dfs(string& startNode, string& endNode, double runningProduct) {
        if (startNode == endNode) {
            queryAns = runningProduct;
            return true;
        }


        bool tempAns = false;
        visited[startNode] = true;

        for (int next = 0; next < adjList[startNode].size(); next++) {
            if (!visited[adjList[startNode][next].first]) {
                tempAns = dfs(adjList[startNode][next].first, endNode, runningProduct * adjList[startNode][next].second);;
                if (tempAns) {
                    break;
                }
            }
        }

        visited[startNode] = false;

        return tempAns;
    }

};