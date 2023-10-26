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
    bool validate(TreeNode* root, int umin=INT_MIN, int umax=INT_MAX) {
        if (root == NULL) return true;

        if (root->val <= umin || root->val >= umax)
            return false;

        return validate(root->left, umin, root->val) && validate(root->right, root->val, umax);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root);
    }
};