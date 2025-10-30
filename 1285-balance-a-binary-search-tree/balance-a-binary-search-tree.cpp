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
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraversal(root);

        return buildTree(0, nodeArr.size() - 1);
    }

private:
    vector<int> nodeArr;

    void inorderTraversal(TreeNode* root) {
        if (!root) return;

        inorderTraversal(root->left);
        nodeArr.push_back(root->val);
        inorderTraversal(root->right);
    }

    TreeNode* buildTree(int startIndex, int endIndex) {
        if (startIndex > endIndex) {
            return NULL;
        }

        int middleIndex = (startIndex + endIndex) / 2;

        TreeNode* root = new TreeNode(nodeArr[middleIndex]);

        root->left = buildTree(startIndex, middleIndex - 1);
        root->right = buildTree(middleIndex + 1, endIndex);

        return root;
    }
};