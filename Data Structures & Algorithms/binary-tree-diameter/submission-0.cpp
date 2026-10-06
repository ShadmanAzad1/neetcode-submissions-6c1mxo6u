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

    int diameterOfBinaryTree(TreeNode* root) {
        int best = 0;
        maxHeight(root, best);
        return best;
    }

    int maxHeight(TreeNode* root, int &best) {
        if(root == NULL) return 0;
        int left = maxHeight(root->left, best);
        int right = maxHeight(root->right, best);
        best = max(best, left + right);
        return 1 + max(left, right);
    }
};
