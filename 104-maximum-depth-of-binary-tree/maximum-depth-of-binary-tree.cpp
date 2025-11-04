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
    int maxDepth(TreeNode* root) {
        return dfs(root);
    }

private:
    int dfs(TreeNode* node) {
        if (!node) {
            return 0;
        }

        int maxLeft = dfs(node->left);
        int maxRight = dfs(node->right);
        return max(maxLeft, maxRight) + 1;
    }
};