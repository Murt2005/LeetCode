class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> currentPath;
        int n = graph.size();
        int targetNode = n - 1;

        dfs(result, graph, currentPath, targetNode, 0);

        return result;
    }

private:
    void dfs(vector<vector<int>>& result, vector<vector<int>>& graph, vector<int>& currentPath, int targetNode, int node) {
        currentPath.push_back(node);

        if (node == targetNode) {
            result.push_back(currentPath);
        } else {
            for (int neighbor : graph[node]) {
                dfs(result, graph, currentPath, targetNode, neighbor);
            }
        }
        currentPath.pop_back();
    }
};