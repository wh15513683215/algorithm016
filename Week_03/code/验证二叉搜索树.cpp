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
    bool isValidBST(TreeNode* root) {
        return help(root, NULL, NULL);
    }
    bool help(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root) return true;
        if (min && root -> val <= min -> val || max && root -> val >= max -> val)
        return false;
        return help(root -> left, min, root) && help(root -> right, root, max);
    }
}; //递归 O(n) O(n)递归栈的深度
