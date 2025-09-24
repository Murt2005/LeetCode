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
    int maxLength = 0;

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return maxLength;
    }

    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {-1, -1};

        auto left = dfs(node->left);
        auto right = dfs(node->right);

        int leftZigZag = right.second + 1;
        int rightZigZag = left.first + 1;

        maxLength = max(maxLength, max(leftZigZag, rightZigZag));

        return {leftZigZag, rightZigZag};
    }
};