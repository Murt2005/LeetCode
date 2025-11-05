/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, vector<TreeNode*>> graph;
        buildGraph(root, nullptr, graph);

        vector<int> result;
        unordered_set<TreeNode*> visited;
        dfs(target, visited, graph, result, k);
        return result;
    }

private:
    void buildGraph(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, vector<TreeNode*>>& graph) {
        if (!node) return;

        if (parent) {
            graph[parent].push_back(node);
            graph[node].push_back(parent);
        }

        buildGraph(node->left, node, graph);
        buildGraph(node->right, node, graph);
    }

    void dfs(TreeNode* node, unordered_set<TreeNode*>& visited, unordered_map<TreeNode*, vector<TreeNode*>>& graph, vector<int>& result, int k) {
        if (!node || visited.count(node)) {
            return;
        }
        
        if (k == 0) {
            result.push_back(node->val);
            return;
        }

        visited.insert(node);

        for (TreeNode* neighbor : graph[node]) {
            dfs(neighbor, visited, graph, result, k - 1);
        }


    }
};


/*

build a graph, adjList
from the target node, run dfs on all neighbors
keep track of the distance
whenever the distance reaches k, stop that search and add the node value to the result array


*/