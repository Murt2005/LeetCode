class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int numEquations = equations.size();
        int numQueries = queries.size();
        vector<double> result(numQueries);

        buildGraph(equations, values);

        for (int i = 0; i < numQueries; i++) {
            string startNode = queries[i][0];
            string endNode = queries[i][1];

            if (graph.find(startNode) == graph.end() || graph.find(endNode) == graph.end()) {
                result[i] = -1.0;
                continue;
            }

            visited.clear();
            double ratio = -1.0;
            bool pathExists = findPath(startNode, endNode, 1.0, ratio);
            result[i] = pathExists ? ratio : -1.0;
        }

        return result;
    }

private:
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_set<string> visited;

    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        for (int i = 0; i < equations.size(); i++) {
            string startNode = equations[i][0];
            string endNode = equations[i][1];
            double quotient = values[i];

            graph[startNode].push_back({endNode, quotient});
            graph[endNode].push_back({startNode, 1 / quotient});
        }
    }

    bool findPath(const string& currentNode, const string& endNode, double accumulatedProduct, double& result) {
        if (currentNode == endNode) {
            result = accumulatedProduct;
            return true;
        }

        visited.insert(currentNode);

        for (const auto& [neighborNode, edgeWeight] : graph[currentNode]) {
            if (visited.find(neighborNode) == visited.end()) {
                double newProduct = accumulatedProduct * edgeWeight;
                
                if (findPath(neighborNode, endNode, newProduct, result)) {
                    return true;
                }
            }
        }

        visited.erase(currentNode);

        return false;
    }
};