/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        vector<long long> levelSums;
        dfs(root, 0, levelSums);

        int maxLevel = 0;
        long long maxSum = levelSums[0];

        for (int i = 1; i < levelSums.size(); i++) {
            if (levelSums[i] > maxSum) {
                maxSum = levelSums[i];
                maxLevel = i;
            }
        }
        return maxLevel + 1;
    }

private:
    void dfs(TreeNode* node, int level, vector<long long>& levelSums) {
        if (!node) return;

        if (level >= levelSums.size()) {
            levelSums.push_back(0);
        }

        levelSums[level] += node->val;
        dfs(node->left, level + 1, levelSums);
        dfs(node->right, level + 1, levelSums);
    }
};

// class Solution {
// public:
//     int maxLevelSum(TreeNode* root) {
//         int maxLevelSum = INT_MIN;
//         int level = 1;
//         int result = 0;
//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             int queueSize = q.size();
//             int levelSum = 0;
//             for (int s = 0; s < queueSize; s++) {
//                 TreeNode* node = q.front();
//                 q.pop();
//                 levelSum += node->val;
//                 if (node->left) q.push(node->left);
//                 if (node->right) q.push(node->right);
//             }
//             if (levelSum > maxLevelSum) {
//                 maxLevelSum = levelSum;
//                 result = level;
//             }
//             level++;
//         }
//         return result;
//     }
// };