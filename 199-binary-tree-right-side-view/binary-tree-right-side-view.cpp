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
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return result;
    }

private:
    vector<int> result;

    void dfs(TreeNode* node, int depth) {
        if (!node) return;

        if (result.size() == depth) {
            result.push_back(node->val);
        }

        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }
};


// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         if (root == nullptr) return { };
//         vector<int> result;
//         queue<TreeNode*> q;
//         q.push(root);
//         while (!q.empty()) {
//             int qSize = q.size();
//             for (int s = 0; s < qSize; s++) {
//                 auto node = q.front();
//                 q.pop();
//                 if (node->left) {
//                     q.push(node->left);
//                 }
//                 if (node->right) {
//                     q.push(node->right);
//                 }
//                 if (s == qSize - 1) {
//                     result.push_back(node->val);
//                 }
//             }
//         }
//         return result;
//     }
// };