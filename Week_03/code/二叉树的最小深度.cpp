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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root -> left) return minDepth(root -> right) + 1;
        if (!root -> right) return minDepth(root -> left) + 1;
        return min(minDepth(root -> left), minDepth(root -> right)) + 1;
    }
};//递归 O(n) O(n)

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> myque;
        myque.push(make_pair(root, 1));
        while(1) {
            TreeNode* node = myque.front().first;
            int depth = myque.front().second;
            myque.pop();
            if (!node -> right && !node -> left) return depth;
            if (node -> right) myque.push(make_pair(node -> right, depth + 1));
            if (node -> left) myque.push(make_pair(node -> left, depth + 1));
        }
    }
};   //层序遍历
