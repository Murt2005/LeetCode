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
    int result;
    int pathSum(TreeNode* root, int targetSum) {
        visitNodes(root, targetSum);
        return result;
    }

    void visitNodes(TreeNode* node, int targetSum) {
        if (!node) return;

        findPath(node, targetSum, node->val);

        if (node->left) {
            visitNodes(node->left, targetSum);
        }

        if (node->right) {
            visitNodes(node->right, targetSum);
        }
    }

    void findPath(TreeNode* node, int targetSum, long long currentSum) {
        if (!node) return;

        if (currentSum == targetSum) result++;

        if (node->left) {
            findPath(node->left, targetSum, currentSum + node->left->val);
        }

        if (node->right) {
            findPath(node->right, targetSum, currentSum + node->right->val);
        }
    }
};

/*
[1,null,2,null,3,null,4,null,5] targetSum = 3
output: 3
expected: 2



*/