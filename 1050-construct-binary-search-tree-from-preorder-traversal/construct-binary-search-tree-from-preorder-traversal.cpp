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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder, 0, preorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder, int start, int end) {
        if (start > end) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[start]);
        int leftStart = start + 1;
        int rightStart;
        for (int i = start; i <= end; i++) {
            if (preorder[i] > preorder[start]) {
                rightStart = i;
                break;
            }
        }

        int leftEnd = rightStart - 1;
        int rightEnd = end;

        root->left = helper(preorder, leftStart, leftEnd);
        root->right = helper(preorder, rightStart, rightEnd);

        return root;
    }
};


/*

preorder = [8,5,1,7,10,12]



*/